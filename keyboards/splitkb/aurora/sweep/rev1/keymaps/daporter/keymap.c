/* Copyright 2023-2024 David Porter <david@daporter.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "features/achordion.h"
#include "features/custom_shift_keys.h"

#include "handsdown_au.h"
#include "layers.h"

enum layers {
    // clang-format off
    L_HD,
    L_SYM,
    L_NUM,
    L_NAV,
    L_CFG
    // clang-format on
};

/*
 * Alpha Layer for a 34 key (3x5+2) form factor.
 * ╭─────────────────────╮ ╭─────────────────────╮
 * │ LT4 LT3 LT2 LT1 LT0 │ │ RT0 RT1 RT2 RT3 RT4 │
 * │ LM4 LM3 LM2 LM1 LM0 │ │ RT0 RM1 RM2 RM3 RM4 │
 * │ LB4 LB3 LB2 LB1 LB0 │ │ RB0 RB1 RB2 RB3 RB4 │
 * ╰───────────╮ LH2 LH1 │ │ RH1 RH2 ╭───────────╯
 *             ╰─────────╯ ╰─────────╯
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

    [L_HD] = LAYOUT(
    HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0,     HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4,
    HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0,     HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4,
    HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0,     HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4,
                            HD_LH2, HD_LH1,     HD_RH1, HD_RH2),

    [L_SYM] = LAYOUT(
    LS_LT4, LS_LT3, LS_LT2, LS_LT1, LS_LT0,     LS_RT0, LS_RT1, LS_RT2, LS_RT3, LS_RT4,
    LS_LM4, LS_LM3, LS_LM2, LS_LM1, LS_LM0,     LS_RM0, LS_RM1, LS_RM2, LS_RM3, LS_RM4,
    LS_LB4, LS_LB3, LS_LB2, LS_LB1, LS_LB0,     LS_RB0, LS_RB1, LS_RB2, LS_RB3, LS_RB4,
                            LS_LH2, LS_LH1,     LS_RH1, LS_RH2),

    [L_NUM] = LAYOUT(
    LN_LT4, LN_LT3, LN_LT2, LN_LT1, LN_LT0,     LN_RT0, LN_RT1, LN_RT2, LN_RT3, LN_RT4,
    LN_LM4, LN_LM3, LN_LM2, LN_LM1, LN_LM0,     LN_RM0, LN_RM1, LN_RM2, LN_RM3, LN_RM4,
    LN_LB4, LN_LB3, LN_LB2, LN_LB1, LN_LB0,     LN_RB0, LN_RB1, LN_RB2, LN_RB3, LN_RB4,
                            LN_LH2, LN_LH1,     LN_RH1, LN_RH2),

    [L_NAV] = LAYOUT(
    LV_LT4, LV_LT3, LV_LT2, LV_LT1, LV_LT0,     LV_RT0, LV_RT1, LV_RT2, LV_RT3, LV_RT4,
    LV_LM4, LV_LM3, LV_LM2, LV_LM1, LV_LM0,     LV_RM0, LV_RM1, LV_RM2, LV_RM3, LV_RM4,
    LV_LB4, LV_LB3, LV_LB2, LV_LB1, LV_LB0,     LV_RB0, LV_RB1, LV_RB2, LV_RB3, LV_RB4,
                            LV_LH2, LV_LH1,     LV_RH1, LV_RH2),

    [L_CFG] = LAYOUT(
    LC_LT4, LC_LT3, LC_LT2, LC_LT1, LC_LT0,     LC_RT0, LC_RT1, LC_RT2, LC_RT3, LC_RT4,
    LC_LM4, LC_LM3, LC_LM2, LC_LM1, LC_LM0,     LC_RM0, LC_RM1, LC_RM2, LC_RM3, LC_RM4,
    LC_LB4, LC_LB3, LC_LB2, LC_LB1, LC_LB0,     LC_RB0, LC_RB1, LC_RB2, LC_RB3, LC_RB4,
                            LC_LH2, LC_LH1,     LC_RH1, LC_RH2),

    // clang-format on
};

const custom_shift_key_t custom_shift_keys[] = {
    // clang-format off
    { HD_HASH,          KC_DOLLAR  },
    { HD_DOT,           KC_COLON },
    { KC_SLASH,         KC_ASTERISK },
    { KC_DOUBLE_QUOTE,  KC_QUESTION },
    { KC_QUOTE,         KC_EXCLAIM },
    { KC_COMMA,         KC_SEMICOLON },
    { KC_MINUS,         KC_PLUS },
    { KC_BACKSPACE,     KC_DELETE  },
    // clang-format on
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// clang-format off
const uint16_t PROGMEM combo_HD_Q[]     = { HD_LT3, HD_LT2,             COMBO_END };
const uint16_t PROGMEM combo_HD_Z[]     = { HD_LT2, HD_LT1,             COMBO_END };
const uint16_t PROGMEM combo_APP[]      = { HD_LT1, HD_LT0,             COMBO_END };

const uint16_t PROGMEM combo_EQL[]      = { HD_RT1, HD_RT2,             COMBO_END };

const uint16_t PROGMEM combo_ESC[]      = { HD_LM3, HD_LM2,             COMBO_END };
const uint16_t PROGMEM combo_STAB[]     = { HD_LM3, HD_LM2, HD_LM1,     COMBO_END };
const uint16_t PROGMEM combo_TAB[]      = { HD_LM2, HD_LM1,             COMBO_END };

const uint16_t PROGMEM combo_HD_SCLN[]  = { HD_RM0, HD_RM1,             COMBO_END };

const uint16_t PROGMEM combo_CAPS[]     = { HD_LM2, HD_RM2,             COMBO_END };
const uint16_t PROGMEM combo_CAPW[]     = { HD_LM1, HD_RM1,             COMBO_END };

const uint16_t PROGMEM combo_UNDS[]     = { HD_RB1, HD_RB3,             COMBO_END };
const uint16_t PROGMEM combo_TILD[]     = { HD_RB1, HD_RB4,             COMBO_END };
// clang-format on

combo_t key_combos[] = {
    // clang-format off
    COMBO(combo_HD_Q,       KC_Q),
    COMBO(combo_HD_Z,       KC_Z),
    COMBO(combo_APP,        KC_APPLICATION),
    COMBO(combo_EQL,        KC_EQUAL),
    COMBO(combo_ESC,        KC_ESCAPE),
    COMBO(combo_STAB,       LSFT(KC_TAB)),
    COMBO(combo_TAB,        KC_TAB),
    COMBO(combo_HD_SCLN,    KC_SEMICOLON),
    COMBO(combo_CAPS,       KC_CAPS_LOCK),
    COMBO(combo_CAPW,       QK_CAPS_WORD_TOGGLE),
    COMBO(combo_UNDS,       KC_UNDERSCORE),
    COMBO(combo_TILD,       KC_TILDE),
    // clang-format on
};

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    /*
     * Allow same-hand chords if the held modifier is a thumb key, since I find
     * them necessary.
     */
    switch (tap_hold_keycode) {
        case HD_LH1:
        case HD_LH2:
        case HD_RH1:
        case HD_RH2:
            return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }

    if (!process_achordion(keycode, record)) {
        return false;
    }

    return true;
}
