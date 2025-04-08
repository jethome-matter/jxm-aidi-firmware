#include "esphome.h"

namespace JH
{
using namespace esphome;

enum class JxmAidiMode
{
    CURRENT_MEASURE,
    VOLTAGE_MEASURE,
    INPUT
};

class JxmAidiController;

class JxmAidiChannel
{
public:
    JxmAidiChannel(ads1115::ADS1115Multiplexer chan,
                    gpio::GPIOSwitch* cur, 
                    gpio::GPIOSwitch* volt, 
                    gpio::GPIOSwitch* pull_up)
    : m_chan(chan), m_cur(cur), m_volt(volt), m_pull_up(pull_up), m_enabled(true)
    {
        
    }

    void set_mode(JxmAidiMode mode) {
        m_cur->turn_off();
        m_volt->turn_off();
        m_pull_up->turn_off();

        m_mode = mode;
        switch(mode) {
            case JxmAidiMode::CURRENT_MEASURE:
                m_cur->turn_on();
                m_cur_gain =  ads1115::ADS1115_GAIN_4P096;
            break;

            case JxmAidiMode::VOLTAGE_MEASURE:
                m_volt->turn_on();
                m_cur_gain =  ads1115::ADS1115_GAIN_4P096;
            break;

            case JxmAidiMode::INPUT:
                m_pull_up->turn_on();
                m_cur_gain =  ads1115::ADS1115_GAIN_4P096;
            break;
        }
    }
    
    void process_measure(float volt_from_adc) {
        m_last_raw_state = volt_from_adc;
        switch(m_mode) {
            case JxmAidiMode::CURRENT_MEASURE:
                m_last_state = get_measured_current_ma(volt_from_adc);
            break;

            case JxmAidiMode::VOLTAGE_MEASURE:
                m_last_state = get_measured_voltage(volt_from_adc);
            break;

            case JxmAidiMode::INPUT:
                m_last_state = get_measured_input(volt_from_adc);
            break;
        }
    }

    optional<float> get_last_state() { return m_last_state; }
    optional<float> get_last_raw_state() { return m_last_raw_state; }

    void set_enabled(bool val) { m_enabled = val; }

    friend JxmAidiController;
protected:

    float get_measured_voltage(float volt_from_adc) {
        const float koeff = (100.0 + 10.0) / 10.0f;
        return volt_from_adc * koeff; 
    }

    float get_measured_current_ma(float volt_from_adc) {
        // TODO возможно нужен еще простой фильтр для срезания оффсета
        const float koeff = 1000.0/ 150.0f;
        return volt_from_adc * koeff ;
    }

    bool get_measured_input(float volt_from_adc) {
        if(volt_from_adc < 0.1) {
            return true;
        }

        return false;
    }

    optional<float> m_last_state;
    optional<float> m_last_raw_state;
    ads1115::ADS1115Multiplexer m_chan;
    ads1115::ADS1115Gain m_cur_gain;
    gpio::GPIOSwitch * m_cur;
    gpio::GPIOSwitch * m_volt;
    gpio::GPIOSwitch * m_pull_up;
    JxmAidiMode m_mode;
    bool m_enabled;
};

class JxmAidiController
{
public:
    JxmAidiController(ads1115::ADS1115Component *ads1115, size_t max_channels_num = 3) {
        m_adc = ads1115;
        m_channels.reserve(max_channels_num);
    }

    ~JxmAidiController() {
        for(auto &chan : m_channels) {
            delete chan;
        }
    }

    void add_channel(JxmAidiChannel * channel) {
        if(channel == nullptr) return;
        m_channels.push_back(channel);
    }

    void add_channels(std::initializer_list<JxmAidiChannel *> channels) {
        m_channels.insert(m_channels.end(), channels.begin(), channels.end());
    }

    optional<float> get_channel_state(uint8_t i) {
        if(m_channels.size() <= i) return {};

        return m_channels[i]->get_last_state();
    }

    JxmAidiChannel* channel(uint8_t i) {
        if(m_channels.size() <= i) return nullptr;

        return m_channels[i];
    }

    void make_measures() {
        for(auto &chan : m_channels) {
            if(!chan->m_enabled) continue;
            float val = m_adc->request_measurement(chan->m_chan, chan->m_cur_gain, ads1115::ADS1115_16_BITS, ads1115::ADS1115_128SPS);
            chan->process_measure(val);
        }
    }
protected:
    ads1115::ADS1115Component *m_adc;
    std::vector<JxmAidiChannel*> m_channels;
};

}
