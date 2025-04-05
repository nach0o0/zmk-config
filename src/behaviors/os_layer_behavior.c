#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zmk/behavior.h>
#include <zmk/behavior_layer.h>
#include <zmk/keymap.h>
#include <string.h>
#include <hid.h>

LOG_MODULE_DECLARE(zmk, LOG_LEVEL_INF);

static int os_layer_behavior_press(struct zmk_behavior_binding *binding,
                                   struct zmk_behavior_binding_event event) {
    uint8_t linux_layer = binding->param1;
    uint8_t windows_layer = binding->param2;
<<<<<<< HEAD
    uint8_t android_layer = binding->param3;
    uint8_t default_layer = binding->param4;
=======
    uint8_t macos_layer = binding->param3;
    uint8_t android_layer = binding->param4;
    uint8_t ios_layer = binding->param5;
    uint8_t default_layer = binding->param6;
>>>>>>> 47aea88ce42cbd33c476cea18ea67c5c787912ee

    int layer_to_activate = default_layer;

    if (strcmp(current_host_os, "linux") == 0) {
        layer_to_activate = linux_layer;
    } else if (strcmp(current_host_os, "windows") == 0) {
        layer_to_activate = windows_layer;
<<<<<<< HEAD
    } else if (strcmp(current_host_os, "android") == 0) {
        layer_to_activate = android_layer;
=======
    } else if (strcmp(current_host_os, "macos") == = 0) {
        layer_to_activate = macos_layer;
    } else if (strcmp(current_host_os, "android") == 0) {
        layer_to_activate = android_layer;
    } else if (strcmp(current_host_os, "ios") == 0) {
        layer_to_activate = ios_layer;
>>>>>>> 47aea88ce42cbd33c476cea18ea67c5c787912ee
    }

    LOG_DBG("Activating layer %d for OS: %s", layer_to_activate, current_host_os);
    zmk_layer_activate(layer_to_activate);

    return ZMK_BEHAVIOR_OPAQUE;
}

static int os_layer_behavior_release(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
    uint8_t linux_layer = binding->param1;
    uint8_t windows_layer = binding->param2;
<<<<<<< HEAD
    uint8_t android_layer = binding->param3;
    uint8_t default_layer = binding->param4;
=======
    uint8_t macos_layer = binding->param3;
    uint8_t android_layer = binding->param4;
    uint8_t ios_layer = binding->param5;
    uint8_t default_layer = binding->param6;
>>>>>>> 47aea88ce42cbd33c476cea18ea67c5c787912ee

    int layer_to_deactivate = default_layer;

    if (strcmp(current_host_os, "linux") == 0) {
        layer_to_deactivate = linux_layer;
    } else if (strcmp(current_host_os, "windows") == 0) {
        layer_to_deactivate = windows_layer;
<<<<<<< HEAD
    } else if (strcmp(current_host_os, "android") == 0) {
        layer_to_deactivate = android_layer;
=======
    } else if (strcmp(current_host_os, "macos") == 0) {
        layer_to_deactivate = macos_layer;
    } else if (strcmp(current_host_os, "android") == 0) {
        layer_to_deactivate = android_layer;
    } else if (strcmp(current_host_os, "ios") == 0) {
        layer_to_deactivate = ios_layer;
>>>>>>> 47aea88ce42cbd33c476cea18ea67c5c787912ee
    }

    LOG_DBG("Deactivating layer %d for OS: %s", layer_to_deactivate, current_host_os);
    zmk_layer_deactivate(layer_to_deactivate);

    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api os_layer_behavior_driver_api = {
    .binding_pressed = os_layer_behavior_press,
    .binding_released = os_layer_behavior_release,
};

BEHAVIOR_DEFINE(os_layer_behavior, os_layer_behavior_driver_api);
