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

#ifdef RGB_MATRIX_ENABLE
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#endif
/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT
