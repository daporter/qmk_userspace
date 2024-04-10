#pragma once

#include QMK_KEYBOARD_H

// clang-format off
#define LP_O_COPY   LT(0, KC_O)     /* O on tap, Copy on long press */
#define LP_U_PASTE  LT(0, KC_U)     /* UV on tap, Paste on long press */
#define QU          LT(0, KC_NO)    /* A smart "qu" key */

enum custom_keycodes {
    ARROW = QK_USER,                /* A smart key for "->","=>" */
};
// clang-format on
