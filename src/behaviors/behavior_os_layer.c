#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zmk/behavior.h>
#include <zmk/keymap.h>
#include <zmk/layers.h>
#include <zmk/keycode.h>
#include <hid.h>

struct behavior_os_layer_config {};

static int behavior_os_layer_keymap_binding_pressed(struct zmk_behavior_binding *binding,
                                                    struct zmk_behavior_binding_event event) {
    uint8_t linux_layer = binding->param1;
    uint8_t windows_layer = binding->param2;
    uint8_t android_layer = binding->param3;
    uint8_t default_layer = binding->param4;

    int layer_to_activate = default_layer;

    if (strcmp(current_host_os, "linux") == 0) {
        layer_to_activate = linux_layer;
    } else if (strcmp(current_host_os, "windows") == 0) {
        layer_to_activate = windows_layer;
    } else if (strcmp(current_host_os, "android") == 0) {
        layer_to_activate = android_layer;
    }

    zmk_layer_activate(layer_to_activate);

    return ZMK_BEHAVIOR_OPAQUE;
}

static int behavior_os_layer_keymap_binding_released(struct zmk_behavior_binding *binding,
                                                     struct zmk_behavior_binding_event event) {
    uint8_t linux_layer = binding->param1;
    uint8_t windows_layer = binding->param2;
    uint8_t android_layer = binding->param3;
    uint8_t default_layer = binding->param4;

    int layer_to_deactivate = default_layer;

    if (strcmp(current_host_os, "linux") == 0) {
        layer_to_deactivate = linux_layer;
    } else if (strcmp(current_host_os, "windows") == 0) {
        layer_to_deactivate = windows_layer;
    } else if (strcmp(current_host_os, "android") == 0) {
        layer_to_deactivate = android_layer;
    }

    zmk_layer_deactivate(layer_to_deactivate);

    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api behavior_os_layer_driver_api = {
    .binding_pressed = behavior_os_layer_keymap_binding_pressed,
    .binding_released = behavior_os_layer_keymap_binding_released,
};

BEHAVIOR_DEFINE(os_layer_behavior, behavior_os_layer_driver_api);
