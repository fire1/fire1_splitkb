
#include QMK_KEYBOARD_H
#include <stdio.h>

#define L_BASE 0
#define L_LOWER (1 << 1)
#define L_RAISE (1 << 2)
#define L_ADJUST (1 << 3)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)

#define KBR_POSITION_ROW 11
#define KBR_POSITION_COL 1

#define KBR_POSITION KBR_POSITION_COL, KBR_POSITION_ROW

// static const char codeToMap[30]  = {' ', ' ', ' ', ' ', 0xAA, 0xAC,0xAC};
static const char codeToChar[60] = {' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', (char)28, 0x7F, (char)27, (char)29, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '};
static char       keylog[5]      = {' ', ' ', ' ', ' '};

//
// Logo char definitions
static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0xFF, 0xA0, 0xA1, 0xA2, 0xA3, 0xFF, 0xC0, 0xC1, 0xC2, 0xC3};

static const char PROGMEM win_logo[] = {0x97, 0x98, 0xFF, 0x20, 0x20, 0xB7, 0xB8, 0xFF, 0xFF};

static const char PROGMEM mac_logo[] = {0x95, 0x96, 0xFF, 0x20, 0x20, 0xB6, 0xFF, 0xFF, 0xFF};

static const char PROGMEM kbr_full[] = {0x86, 0x87, 0x88, 0x89, 0xFF, 0xA6, 0xA7, 0xA8, 0xA9};

static char keymap[9] = {};
#include "lib/ani.c"
static uint8_t  keypressIndex = 0;
static uint16_t privateTimer  = 0;
static bool     isNotBootRun  = false;

static bool is_layer_eql(uint16_t state) {
    if (layer_state == state) {
        return true;
    }

    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN);
}

void default_rgb_layer(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN);
}
/**
 * @brief Change RGB color
 *
 * @param h
 * @param s
 * @param v
 */
void change_rgb_layer(uint8_t h, uint8_t s, uint8_t v) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(h, s, v);
}
//
// Suspend RGB feature
void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
}

/**
 * @brief At boot display OS and swithc to QMK logo
 *
 */
void drawLogo(void) {
    if (timer_elapsed(privateTimer) < 5000) {
        //
        // Close init run

        if (keymap_config.swap_lctl_lgui) {
            oled_set_cursor(2, 1);
            oled_write_P(mac_logo, false);
        } else {
            oled_set_cursor(2, 1);
            oled_write_P(win_logo, false);
        }
        oled_set_cursor(0, 3);
        oled_write_P(PSTR("     "), false);
        oled_set_cursor(0, 4);
        oled_write_P(PSTR("     "), false);
    }

    if (!isNotBootRun && timer_elapsed(privateTimer) > 5000) {
        isNotBootRun = true;
        oled_set_cursor(1, 1);
        oled_write_P(qmk_logo, false);
        oled_set_cursor(0, 4);
        oled_write_P(PSTR("     "), false); //
    }
}

void handleLayers(led_t ledUsbState) {
    oled_set_cursor(0, 5);
    switch (layer_state) {
        case L_BASE:
            if (ledUsbState.caps_lock) {
                oled_write_P(PSTR("CPSLK"), true);
                //
                // Capslovk pin
                change_rgb_layer(HSV_PINK);
            } else {
                oled_write_P(PSTR("QWRTY"), false);
                default_rgb_layer();
            }
            break;

        case L_LOWER:
            change_rgb_layer(HSV_TEAL);
            break;
        case L_RAISE:
            change_rgb_layer(HSV_YELLOW);
            break;

        case L_ADJUST:
        case L_ADJUST_TRI:
        default:
            oled_write_P(PSTR("ADJST"), true);
            change_rgb_layer(HSV_TURQUOISE);

            // oled_write_P(PSTR("UNDEF"), false);
            break;
    }

    oled_set_cursor(0, 6);
    oled_write_P(PSTR("-----"), false);

    oled_set_cursor(0, 7);
    oled_write_P(PSTR("LOWER"), is_layer_eql(L_LOWER));
    oled_set_cursor(0, 8);
    oled_write_P(PSTR("RAISE"), is_layer_eql(L_RAISE));
}

void drawKeyboard(void) {
    oled_set_cursor(KBR_POSITION);
    oled_write(keymap, false);

    oled_set_cursor(0, 13);
    oled_write_P(PSTR("     "), false);

    oled_set_cursor(1, 14);
    oled_write(keylog, false);
}

void renderMaster(led_t ledUsbState) {
    drawLogo();

    handleLayers(ledUsbState);

    drawKeyboard();
}

//
// Setup screen
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    memcpy_P(&keymap, kbr_full, sizeof(kbr_full));
    privateTimer = timer_read();
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        renderMaster(host_keyboard_led_state());
    }

    return false;
}

void setScreenKeys(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if (keycode < 60) {
        name = codeToChar[keycode];
    }

    // update keylog and shift it
    keylog[3] = keylog[2];
    keylog[2] = keylog[1];
    keylog[1] = keylog[0];
    keylog[0] = name;
}
/**
 * @brief OLED keyboard animation of the keypresses
 *
 * @param keycode
 * @param record
 * @return true
 * @return false
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    setScreenKeys(keycode, record);
    animateKeymap(keycode, record);

    //
    // Reset keymap animation pressesdfkjiekjdfiekjdf
    if (keypressIndex > 5) {
        memcpy_P(&keymap, kbr_full, sizeof(kbr_full));
        keypressIndex = 0;
    }

    keypressIndex++;

    return true; // We didn't handle other keypresses
}
