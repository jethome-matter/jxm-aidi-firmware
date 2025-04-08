#pragma once

#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace sensor;
using namespace binary_sensor;
using namespace switch_;
extern logger::Logger *logger_logger_id;
using namespace i2c;
extern i2c::IDFI2CBus *i2c1;
extern preferences::IntervalSyncer *preferences_intervalsyncer_id;
extern ads1115::ADS1115Component *ads1115_ads1115component_id;
extern gpio::GPIOSwitch *AI_CUR_SW1;
extern esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id;
extern gpio::GPIOSwitch *AI_CUR_SW2;
extern esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_2;
extern gpio::GPIOSwitch *AI_CUR_SW3;
extern esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_3;
extern gpio::GPIOSwitch *AI_VOLT_SW1;
extern esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_4;
extern gpio::GPIOSwitch *AI_VOLT_SW2;
extern esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_5;
extern gpio::GPIOSwitch *AI_VOLT_SW3;
extern esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_6;
extern gpio::GPIOSwitch *AI_PULL_UP1;
extern esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_7;
extern gpio::GPIOSwitch *AI_PULL_UP2;
extern esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_8;
extern gpio::GPIOSwitch *AI_PULL_UP3;
extern esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_9;
extern gpio::GPIOBinarySensor *discrete_input;
extern binary_sensor::DelayedOnFilter *binary_sensor_delayedonfilter_id;
extern esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_10;

extern void esphome_setup();