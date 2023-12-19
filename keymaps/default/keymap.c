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
        KC_ESC,    KC_1,    KC_2,   KC_3,    KC_4,     KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_BSPC,
        KC_TAB,    KC_Q,    KC_W,   KC_E,    KC_R,     KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_MINS,
TD(TD_SFT_LAN),    KC_A,    KC_S,   KC_D,    KC_F,     KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   MT(MOD_RSFT,  KC_QUOT),
        KC_LCTL,  KC_Z,    KC_X,   KC_C,    KC_V,     KC_B,   KC_F5,           KC_F6, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   TD(TD_SFT_CPS),
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
    _______,  KC_LCTL,  KC_MS_L, KC_MS_D, KC_MS_R, _______,                          KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, KC_END, _______,
    _______,  _______,  _______, KC_BTN2, KC_BTN1, _______, _______,       _______,  _______,  KC_HOME,  KC_LABK, KC_RABK, KC_BSLS, _______,
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
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, RGB_VAD, RGB_VAI, XXXXXXX, RGB_SPI, RGB_SPD,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       RGB_MOD, RGB_HUI, RGB_SAI, XXXXXXX, RGB_HUD, RGB_SAD,
  XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_SW,RGB_M_X, RGB_M_B, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,     _______,  _______, _______, _______, _______
  ),


};

#ifdef RGBLIGHT_ENABLE

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN);
}

void default_rgb_layer(void){
    rgb_matrix_mode_noeeprom(RGB_MATRIX_PIXEL_RAIN);
    //rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

//
// Suspend RGB feature
void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
}
#endif

//
// Handle layer
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    //
    // Change RGB colors from layer

    switch (get_highest_layer(state)) {
        case 0:
            default_rgb_layer();
            break;
        case _LOWER:
           // rgb_matrix_disable_noeeprom();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_TEAL);
            break;
        case _RAISE:
            //rgb_matrix_disable_noeeprom();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_YELLOW);


            break;
        case _ADJUST:
            //rgb_matrix_disable_noeeprom();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_TURQUOISE);
            break;

        }

#endif

#ifdef OLED_ENABLE
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
#endif

}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE


// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
//void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void set_oled_keys(uint16_t keycode, keyrecord_t *record);


#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  }

#ifdef OLED_ENABLE
// todo later
 // set_oled_keys(keycode, record);
#endif

  return true; // We didn't handle other keypresses
}

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

// Tab dance
tap_dance_action_t tap_dance_actions[] = {
    [TD_SFT_CPS]  = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_CAPS),
    [TD_SFT_LAN]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL,dance_switch_lan_start, dance_switch_lan_finish),
    [TD_TAB_TCL]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL,dance_switch_tab_start, dance_switch_tab_finish),
};




