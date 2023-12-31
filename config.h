// Copyright 2023 Angel Zaprianov (@fire1)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
/*
#define SPLIT_HAND_PIN F4
#define OLED_DISPLAY_128X32
#define SPLIT_OLED_ENABLE
#define RGBLIGHT_LAYERS
#define RGB_MATRIX_LED_COUNT 70
#define DRIVER_LED_TOTAL 70

//
// RGB Matrix setup
#define RGB_MATRIX_KEYPRESSES                                   // reacts to keypresses
#define RGB_MATRIX_KEYRELEASES                                  // reacts to keyreleases (instead of keypresses)
#define RGB_DISABLE_AFTER_TIMEOUT 0                             // number of ticks to wait until disabling effects
#define RGB_DISABLE_WHEN_USB_SUSPENDED false                    // turn off effects when suspended
#define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16                           // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200                       // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT     // Sets the default mode, if none has bggggggeen set
*/
#ifdef OLED_ENABLE
#    define OLED_FONT_H "lib/glcdfont.c"
#endif

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define OLED_DISPLAY_128X32

#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
/*
// Try to get the rgb lights to turn off when the computer is sleeping. Doesn't seem to work reliably.
#define RGBLIGHT_SLEEP
// Enable lighting layers
#define RGBLIGHT_LAYERS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//#define RGBLIGHT_ENABLE

#define RGB_MATRIX_CYCLE_PINWHEEL
*/
// #define RGBLIGHT_EFFECT_KNIGHT
//  #define RGBLIGHT_EFFECT_CHRISTMAS
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT
