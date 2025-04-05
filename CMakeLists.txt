zephyr_library_sources(src/hid.c)
zephyr_library_sources(src/behaviors/os_layer_behavior.c)
zephyr_include_directories(include)
zephyr_include_directories(${APPLICATION_SOURCE_DIR}/include)

set(DTC_EXTRA_BINDING_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR}/config/behaviors
    ${ZMK_CONFIG}/bindings
)
