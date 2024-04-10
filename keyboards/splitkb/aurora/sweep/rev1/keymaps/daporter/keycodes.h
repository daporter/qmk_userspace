#pragma once

#include QMK_KEYBOARD_H

/*
 * We implement long-press keys by customising LT keys.  In the LT keycodes
 * below, the layer number is only a placeholder, and in some cases the
 * keycode is as well.
 */
// clang-format off
#define LP_QU       LT(0, KC_0)     /* "qu" on tap, "q" on long press */
#define LP_EQUAL    LT(0, KC_1)     /* "=" on tap, " == " on long press */
#define LP_NEQUAL   LT(0, KC_2)     /* "!" on tap, " != " on long press */
#define LP_ARROW    LT(0, KC_3)     /* "->" on tap, "=>" on long press */
#define LP_O_COPY   LT(0, KC_O)     /* O on tap, Copy on long press */
#define LP_U_PASTE  LT(0, KC_U)     /* UV on tap, Paste on long press */
// clang-format on
