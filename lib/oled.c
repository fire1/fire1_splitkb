
#include QMK_KEYBOARD_H
#include <stdio.h>

#define L_BASE 0
#define L_LOWER (1 << 1)
#define L_RAISE (1 << 2)
#define L_ADJUST (1 << 3)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

char keylog_str[6] = {' ', ' ', ' ', ' ', ' '};

static bool is_layer_eql(uint16_t state) {
    if (layer_state == state) {
        return true;
    }

    return false;
}

void render_oled_master(led_t led_usb_state) {
    oled_set_cursor(0, 5);
    switch (layer_state) {

        case L_BASE:
            if (led_usb_state.caps_lock) {
                oled_write(PSTR("CPSLK"), true);
            } else {
                oled_write(PSTR("QWRTY"), false);
            }
            break;
        case L_ADJUST:
        case L_ADJUST_TRI:
            oled_write(PSTR("ADJST"), true);
            break;

        case L_LOWER:
        case L_RAISE:
            // empty
            break;

        default:
            oled_write(PSTR("UNDEF"), false);
            break;
    }

    oled_set_cursor(0, 6);
    oled_write("-----", false);

    oled_set_cursor(0, 7);
    oled_write(PSTR("LOWER"), is_layer_eql(L_LOWER));
    oled_set_cursor(0, 8);
    oled_write(PSTR("RAISE"), is_layer_eql(L_RAISE));

    /* Print current key */
    oled_set_cursor(0, 11);
    oled_write(keylog_str, false);
}

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_oled_master(host_keyboard_led_state());
    }

    return false;
}
