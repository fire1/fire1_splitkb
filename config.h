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
//#define RGBLIGHT_SLEEP
//#define RGB_DISABLE_WHEN_USB_SUSPENDED

#ifdef RGB_MATRIX_ENABLE
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define RGB_MATRIX_KEYPRESSES          // reacts to keypresses
#    define LED_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#    define LED_MATRIX_TIMEOUT 15000       // number of milliseconds to wait until led automatically turns off
#endif
/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT
