#include QMK_KEYBOARD_H



// Keyboard layers
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
    CHANGE_LAN=SAFE_RANGE
};
// TapDance
enum {
    TD_SFT_CPS=0,// Right shift & caps lock
    TD_SFT_LAN,
    TD_TAB_TCL
};





// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   F5  |    |  F6   |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  | RAISE|BackSP| Menu |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
//   TD(TD_ESC_GRV) HD_SFT_LAN
 [_QWERTY] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,   KC_3,    KC_4,     KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_BSPC,
        KC_TAB,    KC_Q,    KC_W,   KC_E,    KC_R,     KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_MINS,
TD(TD_SFT_LAN),    KC_A,    KC_S,   KC_D,    KC_F,     KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   MT(MOD_RSFT,  KC_QUOT),
        KC_LCTL,  KC_Z,    KC_X,   KC_C,    KC_V,     KC_B,  KC_MUTE,           KC_F6, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   TD(TD_SFT_CPS),
                                KC_LGUI, KC_LGUI, KC_LALT,MO(_LOWER), KC_SPC,   KC_ENT, MO(_RAISE),  KC_BSPC, KC_LGUI,   MT(MOD_RCTL, KC_APP)

),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  INS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   q  |   w  |  ^^  |   r  |   t  |                    |      |      |   *  |   +  |  |   |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   a  |  <-  |  \/  |  ->  |   g  |-------.    ,-------| Left | Down |  Up  |Right | End  |      |
 * |------+------+------+------+------+------|   F11 |    |  F12  |------+------+------+------+------+------|
 * |      |   z  |   x   |  MR  |  ML  |  b   |      |-------|    |-------|      | Home |   <  |  >   |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
    _______,  KC_F1,    KC_F2,   KC_F3,    KC_F4,  KC_F5,                            KC_F6,   KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_INS,
    _______,  _______,  _______, KC_MS_U, _______, _______,                          KC_CIRC, KC_AMPR,   KC_PAST, KC_PLUS, KC_PIPE,  KC_EQL,
    _______,  KC_LCTL,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U,                          KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, KC_END, KC_F11,
    _______,  _______,  _______, KC_BTN2, KC_BTN1, KC_WH_D, _______,       _______,  _______,  KC_HOME,  KC_LABK, KC_RABK, KC_BSLS, KC_F12,
                                _______,_______, _______,  _______, _______,        KC_BSPC,  _______, KC_DEL, _______,_______
),



/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   `  |  @   |   #  |  $   |   %  |                    |   ^  |   &  |   *  |   !  |  ?   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   (  |  )   |  {   |  }   |   ~  |-------.    ,-------|   5  |   6  |   7  |   8  |   9  |      |
 * |------+------+------+------+------+------|  PgUp |    |  PgDw |------+------+------+------+------+------|
 * |      |   !  |  _   |   [  |  ]   |      |-------|    |-------|   0  |   1  |   2  |   3  |   4  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
//  KC_DQT
[_RAISE] = LAYOUT(
  KC_ESC,    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,    KC_F7,     KC_F8,     KC_F9,    KC_F10,   KC_DEL,
TD(TD_TAB_TCL),KC_GRV,KC_AT, KC_HASH,    KC_DLR,  KC_PERC,                       KC_CIRC,  KC_AMPR,   KC_ASTR,   KC_EXLM,  KC_QUES,  _______,
  _______,   KC_LPRN,  KC_RPRN, KC_LCBR, KC_RCBR, KC_TILD,                       KC_5,     KC_6,      KC_7,      KC_8,     KC_9,     _______,
  _______,   KC_EXLM , KC_UNDS, KC_LBRC, KC_RBRC, _______, KC_PGUP,   KC_PGDN,   KC_0,     KC_1,      KC_2,      KC_3,     KC_4,     _______,
                    _______, _______,  _______,  _______,  KC_DEL,    _______,  _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |sleep |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | Del  | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       RGB_TOG, RGB_VAD, RGB_VAI, XXXXXXX, RGB_SPI, RGB_SPD,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       RGB_MOD, RGB_HUI, RGB_SAI, XXXXXXX, RGB_HUD, RGB_SAD,
  XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_SW,RGB_M_X, RGB_M_B, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,     _______,  _______, _______, _______, _______
  ),


};

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    // 0 is left-half encoder,
    // 1 is right-half encoder
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif

//
// Tap dance setup
void dance_switch_lan_start (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
      register_code(KC_LSFT);
  } else {
      register_code(KC_LGUI);
      register_code(KC_SPC);
  }
}

void dance_switch_lan_finish (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
   unregister_code(KC_LSFT);
  } else {
    unregister_code(KC_LGUI);
    unregister_code(KC_SPC);
  }
}


void dance_switch_tab_start (tap_dance_state_t *state, void *user_data) {

      register_code(KC_LCTL);
      register_code(KC_TAB);

}

void dance_switch_tab_finish (tap_dance_state_t *state, void *user_data) {

    unregister_code(KC_LCTL);
    unregister_code(KC_TAB);

}
//
// Tab dance colection
tap_dance_action_t tap_dance_actions[] = {
    [TD_SFT_CPS]  = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
    [TD_SFT_LAN]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL,dance_switch_lan_start, dance_switch_lan_finish),
    [TD_TAB_TCL]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL,dance_switch_tab_start, dance_switch_tab_finish),
};

//
// Set color to RGB matrix
void set_rgb_solid_color(uint16_t h, uint8_t s, uint8_t v) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(h, s, v);
}

void set_default_rgb_mode(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
}

//
// Set layer colors
void set_layer_color(uint8_t layer) {
    switch (layer) {
        case _QWERTY:
            if (host_keyboard_led_state().caps_lock) {
                set_rgb_solid_color(HSV_PINK);
            } else {
                set_default_rgb_mode();
            }
            break;
        case _RAISE:
            set_rgb_solid_color(HSV_ORANGE);
            break;
        case _LOWER:
            set_rgb_solid_color(HSV_PURPLE);
            break;
        case _ADJUST:
            set_rgb_solid_color(HSV_RED);
            break;
        default:
            set_default_rgb_mode();
            break;
    }
}

//
// Handle layers properly
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    set_layer_color(get_highest_layer(state));
    return state;
}



// Suspend RGB matrix
/*
void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
}
*/
#include "lib/main.c"

