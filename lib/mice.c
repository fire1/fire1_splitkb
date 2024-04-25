

void pointing_device_init_user(void) {
    setPinInputHigh(ANALOG_JOYSTICK_X_AXIS_PIN);
    setPinInputHigh(ANALOG_JOYSTICK_Y_AXIS_PIN);
    if (!is_keyboard_master()) setPinInputHigh(ANALOG_JOYSTICK_CLICK_PIN);
}


// State
static int8_t delta_x = 0;
static int8_t delta_y = 0;

#define SCROLL_TIMEOUT 25
#define DELTA_X_THRESHOLD 60
#define DELTA_Y_THRESHOLD 15
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (pointer_scroll_enabled) {
        delta_x += mouse_report.x;
        delta_y += mouse_report.y;

        if (delta_x > DELTA_X_THRESHOLD) {
            mouse_report.h = 1;
            delta_x        = 0;
        } else if (delta_x < -DELTA_X_THRESHOLD) {
            mouse_report.h = -1;
            delta_x        = 0;
        }

        if (delta_y > DELTA_Y_THRESHOLD) {
            mouse_report.v = -1;
            delta_y        = 0;
        } else if (delta_y < -DELTA_Y_THRESHOLD) {
            mouse_report.v = 1;
            delta_y        = 0;
        }
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
/*
    if (!is_keyboard_master() && readPin(ANALOG_JOYSTICK_CLICK_PIN)) {
        mouse_report.buttons = pointing_device_handle_buttons(mouse_report.buttons, true, POINTING_DEVICE_BUTTON1);
    }
    */
    return mouse_report;
}
