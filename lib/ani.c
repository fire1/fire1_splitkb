

static const char kpr_tl1 = 0xC6;
static const char kpr_tm1 = 0x8A;
static const char kpr_tm2 = 0xC9;
static const char kpr_ml1 = 0xAA;
static const char kpr_ml2 = 0xAB;
static const char kpr_mr1 = 0xCB;
static const char kpr_bl1 = 0x8C;
static const char kpr_br1 = 0xAC;
static const char kpr_br2 = 0xAD;
/**
 * @brief Animate keymap keypres
 *
 * @param keycode
 * @param record
 */
void animateKeymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && keycode < 40) {
        switch (keycode) {
            //
            // Master side
            case KC_ESC:
            case KC_1:
            case KC_Q:
                keymap[0] = kpr_tl1;
                break;

            case KC_2:
            case KC_3:
            case KC_W:
            case KC_E:
                keymap[0] = kpr_tm1;
                break;

            case KC_4:
            case KC_5:
            case KC_R:
            case KC_T:
                keymap[1] = kpr_tm2;
                break;

            case KC_A:
            case KC_S:
            case KC_LSFT:
                keymap[0] = kpr_ml1;
                break;

            case KC_D:
            case KC_F:
                keymap[1] = kpr_ml2;
                break;

            case KC_G:
                keymap[1] = kpr_mr1;
                break;

            case KC_Z:
            case KC_X:
                keymap[0] = kpr_bl1;
                break;

            case KC_C:
            case KC_V:
                keymap[0] = kpr_br1;
                break;

            case KC_B:
                keymap[1] = kpr_br2;
                break;

                //
                // Slave side
            case KC_N:
                keymap[2] = kpr_bl1;
                break;

            case KC_H:
                keymap[2] = kpr_ml1;
                break;

            case KC_6:
            case KC_Y:
                keymap[2] = kpr_tl1;
                break;

            case KC_7:
            case KC_8:
            case KC_U:
            case KC_I:
                keymap[2] = kpr_tm1;
                break;

            case KC_J:
            case KC_K:
                keymap[2] = 0xCA;
                break;

            case KC_DOT:
            case KC_COMM:
                keymap[3] = 0x8D;
                break;

            case KC_SLSH:
                keymap[3] = kpr_br2;
                break;

            case KC_L:
            case KC_SCLN:
                keymap[3] = kpr_mr1;
                break;

            case KC_O:
            case KC_P:
            case KC_9:
            case KC_0:
                keymap[3] = 0x8B;
                break;
            default:
                // For other keycodes, you might want to update the keymap accordingly
                break;
        }
    }
}
