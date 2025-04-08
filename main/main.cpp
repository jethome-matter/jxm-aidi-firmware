// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "main.h"
#include "esp_log.h"
#include "jxd_aidi_control.h"

TaskHandle_t loop_task_handle = nullptr;  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
TaskHandle_t second_task_handle = nullptr;

void adc_read_task(void *pv_params);

void loop_task(void *pv_params) {
  esphome_setup();
  xTaskCreate(adc_read_task, "adcReadTask", 4096, nullptr, 2, &second_task_handle);
  while (true) {
    App.loop();
  }
}

void adc_read_task(void *pv_params) {

  JH::JxmAidiController controller(ads1115_ads1115component_id, 3);

  auto chan1 = new JH::JxmAidiChannel(ads1115::ADS1115_MULTIPLEXER_P0_NG, AI_CUR_SW1, AI_VOLT_SW1, AI_PULL_UP1);
  auto chan2 = new JH::JxmAidiChannel(ads1115::ADS1115_MULTIPLEXER_P1_NG, AI_CUR_SW2, AI_VOLT_SW2, AI_PULL_UP2);
  auto chan3 = new JH::JxmAidiChannel(ads1115::ADS1115_MULTIPLEXER_P2_NG, AI_CUR_SW3, AI_VOLT_SW3, AI_PULL_UP3);

  chan1->set_mode(JH::JxmAidiMode::VOLTAGE_MEASURE);
  chan2->set_mode(JH::JxmAidiMode::CURRENT_MEASURE);
  chan3->set_mode(JH::JxmAidiMode::INPUT);

  controller.add_channels({chan1, chan2, chan3});
  ESP_LOGI("ADS", "HERE");
  while (true) {
    controller.make_measures();
    ESP_LOGI("ADS", "Measured value chan1=%f, chan2=%f, chan3=%f", chan1->get_last_state().value(), chan2->get_last_state().value(), chan3->get_last_raw_state().value());
    delay(1000);
  }
}

extern "C" void app_main() {
  esp32::setup_preferences();

  xTaskCreate(loop_task, "loopTask", 8192, nullptr, 1, &loop_task_handle);
}
