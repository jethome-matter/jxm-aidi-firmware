#include "main.h"

logger::Logger *logger_logger_id;
using namespace i2c;
i2c::IDFI2CBus *i2c1;
preferences::IntervalSyncer *preferences_intervalsyncer_id;
ads1115::ADS1115Component *ads1115_ads1115component_id;
gpio::GPIOSwitch *AI_CUR_SW1;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id;
gpio::GPIOSwitch *AI_CUR_SW2;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_2;
gpio::GPIOSwitch *AI_CUR_SW3;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_3;
gpio::GPIOSwitch *AI_VOLT_SW1;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_4;
gpio::GPIOSwitch *AI_VOLT_SW2;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_5;
gpio::GPIOSwitch *AI_VOLT_SW3;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_6;
gpio::GPIOSwitch *AI_PULL_UP1;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_7;
gpio::GPIOSwitch *AI_PULL_UP2;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_8;
gpio::GPIOSwitch *AI_PULL_UP3;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_9;
gpio::GPIOBinarySensor *discrete_input;
binary_sensor::DelayedOnFilter *binary_sensor_delayedonfilter_id;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_id_10;
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void esphome_setup()
{
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esphome:
  //   name: jxm-aidi-dev1
  //   min_version: 2025.3.3
  //   build_path: build\jxm-aidi-dev1
  //   friendly_name: ''
  //   area: ''
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  App.pre_setup("jxm-aidi-dev1", "", "", "", __DATE__ ", " __TIME__, false);
  // switch:
  // binary_sensor:
  // logger:
  //   level: VERBOSE
  //   initial_level: INFO
  //   id: logger_logger_id
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   logs: {}
  logger_logger_id = new logger::Logger(115200, 512);
  logger_logger_id->set_log_level(ESPHOME_LOG_LEVEL_INFO);
  logger_logger_id->set_uart_selection(logger::UART_SELECTION_UART0);
  logger_logger_id->pre_setup();
  logger_logger_id->set_component_source("logger");
  App.register_component(logger_logger_id);
  // i2c:
  //   sda: 5
  //   scl: 4
  //   frequency: 400000.0
  //   scan: true
  //   id: i2c1
  //   sda_pullup_enabled: true
  //   scl_pullup_enabled: true
  i2c1 = new i2c::IDFI2CBus();
  i2c1->set_component_source("i2c");
  App.register_component(i2c1);
  i2c1->set_sda_pin(5);
  i2c1->set_sda_pullup_enabled(true);
  i2c1->set_scl_pin(4);
  i2c1->set_scl_pullup_enabled(true);
  i2c1->set_frequency(400000);
  i2c1->set_scan(true);
  // esp32:
  //   board: esp32dev
  //   flash_size: 8MB
  //   framework:
  //     version: 5.1.5
  //     sdkconfig_options:
  //       CONFIG_COMPILER_OPTIMIZATION_SPEED: y
  //     advanced:
  //       ignore_efuse_custom_mac: false
  //     components: []
  //     platform_version: https:github.com/pioarduino/platform-espressif32.git#51.03.07
  //     source: pioarduino/framework-espidf@https:github.com/pioarduino/esp-idf/releases/download/v5.1.5/esp-idf-v5.1.5.zip
  //     type: esp-idf
  //   variant: ESP32
  // preferences:
  //   id: preferences_intervalsyncer_id
  //   flash_write_interval: 60s
  preferences_intervalsyncer_id = new preferences::IntervalSyncer();
  preferences_intervalsyncer_id->set_write_interval(60000);
  preferences_intervalsyncer_id->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer_id);
  // ads1115:
  //   address: 0x49
  //   id: ads1115_ads1115component_id
  //   continuous_mode: false
  //   i2c_id: i2c1
  ads1115_ads1115component_id = new ads1115::ADS1115Component();
  ads1115_ads1115component_id->set_component_source("ads1115");
  App.register_component(ads1115_ads1115component_id);
  ads1115_ads1115component_id->set_i2c_bus(i2c1);
  ads1115_ads1115component_id->set_i2c_address(0x49);
  ads1115_ads1115component_id->set_continuous_mode(false);
  // switch.gpio:
  //   platform: gpio
  //   id: AI_CUR_SW1
  //   pin:
  //     number: 17
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id
  //     inverted: false
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   interlock_wait_time: 0ms
  //   name: AI_CUR_SW1
  //   internal: true
  AI_CUR_SW1 = new gpio::GPIOSwitch();
  App.register_switch(AI_CUR_SW1);
  AI_CUR_SW1->set_name("AI_CUR_SW1");
  AI_CUR_SW1->set_object_id("ai_cur_sw1");
  AI_CUR_SW1->set_disabled_by_default(false);
  AI_CUR_SW1->set_internal(true);
  AI_CUR_SW1->set_restore_mode(switch_::SWITCH_ALWAYS_OFF);
  AI_CUR_SW1->set_component_source("gpio.switch");
  App.register_component(AI_CUR_SW1);
  esp32_esp32internalgpiopin_id = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id->set_pin(::GPIO_NUM_17);
  esp32_esp32internalgpiopin_id->set_inverted(false);
  esp32_esp32internalgpiopin_id->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id->set_flags(gpio::Flags::FLAG_OUTPUT);
  AI_CUR_SW1->set_pin(esp32_esp32internalgpiopin_id);
  // switch.gpio:
  //   platform: gpio
  //   id: AI_CUR_SW2
  //   pin:
  //     number: 21
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id_2
  //     inverted: false
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   interlock_wait_time: 0ms
  //   name: AI_CUR_SW2
  //   internal: true
  AI_CUR_SW2 = new gpio::GPIOSwitch();
  App.register_switch(AI_CUR_SW2);
  AI_CUR_SW2->set_name("AI_CUR_SW2");
  AI_CUR_SW2->set_object_id("ai_cur_sw2");
  AI_CUR_SW2->set_disabled_by_default(false);
  AI_CUR_SW2->set_internal(true);
  AI_CUR_SW2->set_restore_mode(switch_::SWITCH_ALWAYS_OFF);
  AI_CUR_SW2->set_component_source("gpio.switch");
  App.register_component(AI_CUR_SW2);
  esp32_esp32internalgpiopin_id_2 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id_2->set_pin(::GPIO_NUM_21);
  esp32_esp32internalgpiopin_id_2->set_inverted(false);
  esp32_esp32internalgpiopin_id_2->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id_2->set_flags(gpio::Flags::FLAG_OUTPUT);
  AI_CUR_SW2->set_pin(esp32_esp32internalgpiopin_id_2);
  // switch.gpio:
  //   platform: gpio
  //   id: AI_CUR_SW3
  //   pin:
  //     number: 32
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id_3
  //     inverted: false
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   interlock_wait_time: 0ms
  //   name: AI_CUR_SW3
  //   internal: true
  AI_CUR_SW3 = new gpio::GPIOSwitch();
  App.register_switch(AI_CUR_SW3);
  AI_CUR_SW3->set_name("AI_CUR_SW3");
  AI_CUR_SW3->set_object_id("ai_cur_sw3");
  AI_CUR_SW3->set_disabled_by_default(false);
  AI_CUR_SW3->set_internal(true);
  AI_CUR_SW3->set_restore_mode(switch_::SWITCH_ALWAYS_OFF);
  AI_CUR_SW3->set_component_source("gpio.switch");
  App.register_component(AI_CUR_SW3);
  esp32_esp32internalgpiopin_id_3 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id_3->set_pin(::GPIO_NUM_32);
  esp32_esp32internalgpiopin_id_3->set_inverted(false);
  esp32_esp32internalgpiopin_id_3->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id_3->set_flags(gpio::Flags::FLAG_OUTPUT);
  AI_CUR_SW3->set_pin(esp32_esp32internalgpiopin_id_3);
  // switch.gpio:
  //   platform: gpio
  //   id: AI_VOLT_SW1
  //   pin:
  //     number: 18
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id_4
  //     inverted: false
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   interlock_wait_time: 0ms
  //   name: AI_VOLT_SW1
  //   internal: true
  AI_VOLT_SW1 = new gpio::GPIOSwitch();
  App.register_switch(AI_VOLT_SW1);
  AI_VOLT_SW1->set_name("AI_VOLT_SW1");
  AI_VOLT_SW1->set_object_id("ai_volt_sw1");
  AI_VOLT_SW1->set_disabled_by_default(false);
  AI_VOLT_SW1->set_internal(true);
  AI_VOLT_SW1->set_restore_mode(switch_::SWITCH_ALWAYS_OFF);
  AI_VOLT_SW1->set_component_source("gpio.switch");
  App.register_component(AI_VOLT_SW1);
  esp32_esp32internalgpiopin_id_4 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id_4->set_pin(::GPIO_NUM_18);
  esp32_esp32internalgpiopin_id_4->set_inverted(false);
  esp32_esp32internalgpiopin_id_4->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id_4->set_flags(gpio::Flags::FLAG_OUTPUT);
  AI_VOLT_SW1->set_pin(esp32_esp32internalgpiopin_id_4);
  // switch.gpio:
  //   platform: gpio
  //   id: AI_VOLT_SW2
  //   pin:
  //     number: 22
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id_5
  //     inverted: false
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   interlock_wait_time: 0ms
  //   name: AI_VOLT_SW2
  //   internal: true
  AI_VOLT_SW2 = new gpio::GPIOSwitch();
  App.register_switch(AI_VOLT_SW2);
  AI_VOLT_SW2->set_name("AI_VOLT_SW2");
  AI_VOLT_SW2->set_object_id("ai_volt_sw2");
  AI_VOLT_SW2->set_disabled_by_default(false);
  AI_VOLT_SW2->set_internal(true);
  AI_VOLT_SW2->set_restore_mode(switch_::SWITCH_ALWAYS_OFF);
  AI_VOLT_SW2->set_component_source("gpio.switch");
  App.register_component(AI_VOLT_SW2);
  esp32_esp32internalgpiopin_id_5 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id_5->set_pin(::GPIO_NUM_22);
  esp32_esp32internalgpiopin_id_5->set_inverted(false);
  esp32_esp32internalgpiopin_id_5->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id_5->set_flags(gpio::Flags::FLAG_OUTPUT);
  AI_VOLT_SW2->set_pin(esp32_esp32internalgpiopin_id_5);
  // switch.gpio:
  //   platform: gpio
  //   id: AI_VOLT_SW3
  //   pin:
  //     number: 33
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id_6
  //     inverted: false
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   interlock_wait_time: 0ms
  //   name: AI_VOLT_SW3
  //   internal: true
  AI_VOLT_SW3 = new gpio::GPIOSwitch();
  App.register_switch(AI_VOLT_SW3);
  AI_VOLT_SW3->set_name("AI_VOLT_SW3");
  AI_VOLT_SW3->set_object_id("ai_volt_sw3");
  AI_VOLT_SW3->set_disabled_by_default(false);
  AI_VOLT_SW3->set_internal(true);
  AI_VOLT_SW3->set_restore_mode(switch_::SWITCH_ALWAYS_OFF);
  AI_VOLT_SW3->set_component_source("gpio.switch");
  App.register_component(AI_VOLT_SW3);
  esp32_esp32internalgpiopin_id_6 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id_6->set_pin(::GPIO_NUM_33);
  esp32_esp32internalgpiopin_id_6->set_inverted(false);
  esp32_esp32internalgpiopin_id_6->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id_6->set_flags(gpio::Flags::FLAG_OUTPUT);
  AI_VOLT_SW3->set_pin(esp32_esp32internalgpiopin_id_6);
  // switch.gpio:
  //   platform: gpio
  //   id: AI_PULL_UP1
  //   pin:
  //     number: 16
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id_7
  //     inverted: false
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   inverted: true
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   interlock_wait_time: 0ms
  //   name: AI_PULL_UP1
  //   internal: true
  AI_PULL_UP1 = new gpio::GPIOSwitch();
  App.register_switch(AI_PULL_UP1);
  AI_PULL_UP1->set_name("AI_PULL_UP1");
  AI_PULL_UP1->set_object_id("ai_pull_up1");
  AI_PULL_UP1->set_disabled_by_default(false);
  AI_PULL_UP1->set_internal(true);
  AI_PULL_UP1->set_inverted(true);
  AI_PULL_UP1->set_restore_mode(switch_::SWITCH_ALWAYS_OFF);
  AI_PULL_UP1->set_component_source("gpio.switch");
  App.register_component(AI_PULL_UP1);
  esp32_esp32internalgpiopin_id_7 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id_7->set_pin(::GPIO_NUM_16);
  esp32_esp32internalgpiopin_id_7->set_inverted(false);
  esp32_esp32internalgpiopin_id_7->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id_7->set_flags(gpio::Flags::FLAG_OUTPUT);
  AI_PULL_UP1->set_pin(esp32_esp32internalgpiopin_id_7);
  // switch.gpio:
  //   platform: gpio
  //   id: AI_PULL_UP2
  //   pin:
  //     number: 19
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id_8
  //     inverted: false
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   inverted: true
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   interlock_wait_time: 0ms
  //   name: AI_PULL_UP2
  //   internal: true
  AI_PULL_UP2 = new gpio::GPIOSwitch();
  App.register_switch(AI_PULL_UP2);
  AI_PULL_UP2->set_name("AI_PULL_UP2");
  AI_PULL_UP2->set_object_id("ai_pull_up2");
  AI_PULL_UP2->set_disabled_by_default(false);
  AI_PULL_UP2->set_internal(true);
  AI_PULL_UP2->set_inverted(true);
  AI_PULL_UP2->set_restore_mode(switch_::SWITCH_ALWAYS_OFF);
  AI_PULL_UP2->set_component_source("gpio.switch");
  App.register_component(AI_PULL_UP2);
  esp32_esp32internalgpiopin_id_8 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id_8->set_pin(::GPIO_NUM_19);
  esp32_esp32internalgpiopin_id_8->set_inverted(false);
  esp32_esp32internalgpiopin_id_8->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id_8->set_flags(gpio::Flags::FLAG_OUTPUT);
  AI_PULL_UP2->set_pin(esp32_esp32internalgpiopin_id_8);
  // switch.gpio:
  //   platform: gpio
  //   id: AI_PULL_UP3
  //   pin:
  //     number: 23
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id_9
  //     inverted: false
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   inverted: true
  //   disabled_by_default: false
  //   restore_mode: ALWAYS_OFF
  //   interlock_wait_time: 0ms
  //   name: AI_PULL_UP3
  //   internal: true
  AI_PULL_UP3 = new gpio::GPIOSwitch();
  App.register_switch(AI_PULL_UP3);
  AI_PULL_UP3->set_name("AI_PULL_UP3");
  AI_PULL_UP3->set_object_id("ai_pull_up3");
  AI_PULL_UP3->set_disabled_by_default(false);
  AI_PULL_UP3->set_internal(true);
  AI_PULL_UP3->set_inverted(true);
  AI_PULL_UP3->set_restore_mode(switch_::SWITCH_ALWAYS_OFF);
  AI_PULL_UP3->set_component_source("gpio.switch");
  App.register_component(AI_PULL_UP3);
  esp32_esp32internalgpiopin_id_9 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id_9->set_pin(::GPIO_NUM_23);
  esp32_esp32internalgpiopin_id_9->set_inverted(false);
  esp32_esp32internalgpiopin_id_9->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id_9->set_flags(gpio::Flags::FLAG_OUTPUT);
  AI_PULL_UP3->set_pin(esp32_esp32internalgpiopin_id_9);
  // binary_sensor.gpio:
  //   platform: gpio
  //   id: discrete_input
  //   pin:
  //     number: 38
  //     inverted: true
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_id_10
  //     ignore_pin_validation_error: false
  //     ignore_strapping_warning: false
  //     drive_strength: 20.0
  //   filters:
  //   - delayed_on: 50ms
  //     type_id: binary_sensor_delayedonfilter_id
  //   disabled_by_default: false
  //   name: discrete_input
  //   internal: true
  discrete_input = new gpio::GPIOBinarySensor();
  App.register_binary_sensor(discrete_input);
  discrete_input->set_name("discrete_input");
  discrete_input->set_object_id("discrete_input");
  discrete_input->set_disabled_by_default(false);
  discrete_input->set_internal(true);
  binary_sensor_delayedonfilter_id = new binary_sensor::DelayedOnFilter();
  binary_sensor_delayedonfilter_id->set_component_source("binary_sensor");
  App.register_component(binary_sensor_delayedonfilter_id);
  binary_sensor_delayedonfilter_id->set_delay(50);
  discrete_input->add_filters({binary_sensor_delayedonfilter_id});
  discrete_input->set_component_source("gpio.binary_sensor");
  App.register_component(discrete_input);
  esp32_esp32internalgpiopin_id_10 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_id_10->set_pin(::GPIO_NUM_38);
  esp32_esp32internalgpiopin_id_10->set_inverted(true);
  esp32_esp32internalgpiopin_id_10->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_id_10->set_flags(gpio::Flags::FLAG_INPUT);
  discrete_input->set_pin(esp32_esp32internalgpiopin_id_10);
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}
