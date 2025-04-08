# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16.0)

set(EXTRA_COMPONENT_DIRS components)

add_compile_definitions(CORE_DEBUG_LEVEL=5)
add_compile_definitions(ESPHOME_LOG_LEVEL=ESPHOME_LOG_LEVEL_DEBUG)
add_compile_definitions(USE_ESP32)
add_compile_definitions(USE_ESP32_FRAMEWORK_ESP_IDF)
add_compile_definitions(USE_ESP32_VARIANT_ESP32)
add_compile_definitions(USE_ESP_IDF)

add_compile_options(-Wno-nonnull-compare)
add_compile_options(-Wno-sign-compare)
add_compile_options(-Wno-unused-but-set-variable)
add_compile_options(-Wno-unused-variable)
add_compile_options(-fno-exceptions)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esphome_separatly_test_jxmi_aidi)