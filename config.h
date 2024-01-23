// Copyright 2023 Angel Zaprianov (@fire1)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//
// Oled custom font
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define OLED_FONT_H "lib/font.c"
#endif

#define TAPPING_TERM 240
#define TAPPING_TERM_PER_KEY
// #define RGBLIGHT_SLEEP
// #define RGB_DISABLE_WHEN_USB_SUSPENDED

#ifdef RGB_MATRIX_ENABLE
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
// #    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #    define RGB_MATRIX_KEYPRESSES          // reacts to keypresses
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_PIXEL_RAIN
// #    define RGBLIGHT_DEFAULT_SPD 6               //lower for slower
#    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#    define RGB_MATRIX_TIMEOUT 1800000     // 30min / number of milliseconds to wait until led automatically turns off
#endif
/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT
#ifdef POINTING_DEVICE_ENABLE
#    define SPLIT_POINTING_ENABLE // enables transmitting the pointing device status to the master side of the split keyboard
#    define ANALOG_JOYSTICK_X_AXIS_PIN F4
#    define ANALOG_JOYSTICK_Y_AXIS_PIN B6
#    define ANALOG_JOYSTICK_CLICK_PIN B2
#    define ANALOG_JOYSTICK_AXIS_MIN 300
#    define ANALOG_JOYSTICK_AXIS_MAX 1010
#    define ANALOG_JOYSTICK_SPEED_REGULATOR 18
#    define ANALOG_JOYSTICK_READ_INTERVAL 10
#    define POINTING_DEVICE_RIGHT
#    define POINTING_DEVICE_INVERT_X
#    define POINTING_DEVICE_INVERT_Y
#    define ANALOG_JOYSTICK_SPEED_MAX 3
#endif
