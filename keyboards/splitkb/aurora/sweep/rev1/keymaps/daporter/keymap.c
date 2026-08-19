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

#include "features/tap_hold.h"

#include "keycodes.h"
// Alpha layout: swap this include for "handsdown_vf.h" or "handsdown_vb.h"
// to switch to Hands Down Vibranium f/b instead of Hands Down Gold.
#include "handsdown_au.h"
#include "layers.h"

enum layers {
    // clang-format off
    L_HD,
    L_ALPHA2,
    L_SYM,
    L_NUM,
    L_NAV,
    L_CFG
    // clang-format on
};

// Must come after `enum layers`: combos.def uses layer-tap keys (e.g.
// HD_LH1) and TG(L_NUM), both of which need L_NUM/L_SYM/etc. declared.
#include "g/keymap_combo.h"

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

    [L_ALPHA2] = LAYOUT(
    LA2_LT4, LA2_LT3, LA2_LT2, LA2_LT1, LA2_LT0,     LA2_RT0, LA2_RT1, LA2_RT2, LA2_RT3, LA2_RT4,
    LA2_LM4, LA2_LM3, LA2_LM2, LA2_LM1, LA2_LM0,     LA2_RM0, LA2_RM1, LA2_RM2, LA2_RM3, LA2_RM4,
    LA2_LB4, LA2_LB3, LA2_LB2, LA2_LB1, LA2_LB0,     LA2_RB0, LA2_RB1, LA2_RB2, LA2_RB3, LA2_RB4,
                            LA2_LH2, LA2_LH1,     LA2_RH1, LA2_RH2),

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
    { KC_DOUBLE_QUOTE,  KC_EXCLAIM },
    { KC_QUOTE,         KC_QUESTION },
    { KC_COMMA,         KC_SEMICOLON },
    { KC_MINUS,         KC_PLUS },
    // clang-format on
};

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}

/*
 * Same as the QMK default, except KC_MINS is moved out of the shifted
 * group so it sends a literal `-` (e.g. FOO-BAR) instead of `_`.
 */
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

/*
 * Same as the QMK default, except it classifies keys by what they actually
 * send on this keymap. sentence_case_press_user() runs on the *raw* keymap
 * keycode, before custom_shift_keys remaps it (community modules run before
 * process_record_user; see quantum.c) -- so e.g. shifted KC_QUOTE (which
 * custom_shift_keys turns into "?") arrives here as plain KC_QUOTE, which
 * the QMK default always classifies as a quote, never as sentence-ending.
 * Mirror custom_shift_keys' table (keymap.c above) instead of the default's
 * US-ANSI assumptions (e.g. it assumes shifted KC_SLASH is "?"; here it's
 * "*", from custom_shift_keys).
 */
char sentence_case_press_user(uint16_t keycode, keyrecord_t *record, uint8_t mods) {
    switch (keycode) {
        // HD_OSFT_TD/HD_ALPHA2_TD (tap dance for one-shot shift/Caps Word/
        // Caps Lock/NAV on HD_LH2, one-shot L_ALPHA2/L_CFG on HD_RH2) don't
        // type anything themselves -- ignore them like core's own
        // QK_ONE_SHOT_MOD/QK_ONE_SHOT_LAYER ranges below, rather than
        // falling through to the "unrecognized key" branch, which would
        // wrongly reset Sentence Case state on every one-shot-shift tap
        // (e.g. arming shift for "!"/"?" via HD_LH2 mid-sentence).
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return '\0';
    }

    if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
        const bool shifted = mods & MOD_MASK_SHIFT;
        switch (keycode) {
            case KC_A ... KC_Z:
            case LP_QU: // taps/holds to Q or QU
                return 'a'; // Letter key.

            case HD_DOT: // unshifted '.'; shifted ':' (see custom_shift_keys)
                return !shifted ? '.' : '#';
            case KC_DOUBLE_QUOTE: // unshifted '"'; shifted '!' via custom_shift_keys
            case KC_QUOTE:        // unshifted '\''; shifted '?' via custom_shift_keys
                return shifted ? '.' : '\'';
            case KC_EXCLAIM: // '!' typed directly (SYM layer LM4, or combo_EXLM)
            case KC_QUESTION: // '?' typed directly (combo_QUES)
                return '.';

            case KC_1: // shifted '!' (real Shift, not custom_shift_keys)
                return shifted ? '.' : '#';
            case KC_2 ... KC_0: // 2 3 4 5 6 7 8 9 0
            case KC_AT ... KC_RPRN: // @ # $ % ^ & * ( )
            case KC_MINS ... KC_SCLN: // - = [ ] backslash ;
            case KC_UNDS ... KC_COLN: // _ + { } | :
            case KC_GRV:
            case KC_COMM:
            case KC_SLASH: // unshifted '/'; shifted '*' (not '?')
                return '#'; // Symbol key.

            case KC_SPC:
                return ' '; // Space key.
        }
    }

    // Otherwise clear Sentence Case to initial state.
    sentence_case_clear();
    return '\0';
}

bool tap_hold(uint16_t keycode) {
    switch (keycode) {
        case LP_QU:
        case KC_EQUAL:
        case KC_EXCLAIM:
        case KC_AMPERSAND:
        case KC_PIPE:
            return true;
        default:
            return false;
    }
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
        case LP_QU:
            if (get_mods() & MOD_MASK_CAG) {
                tap_code16(KC_Q);
                break;
            }
            if (is_caps_word_on()) {
                send_string("QU");
            } else {
                tap_code16(KC_Q);
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_U);
            }
            break;
        default:
            tap_code16(keycode);
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    switch (keycode) {
        case LP_QU:
            if (is_caps_word_on())
                tap_code16(LSFT(KC_Q));
            else
                tap_code16(KC_Q);
            break;
        case KC_EQUAL:
            send_string(" == ");
            break;
        case KC_EXCLAIM:
            send_string_P(" != ");
            break;
        case KC_AMPERSAND:
            send_string(" && ");
            break;
        case KC_PIPE:
            send_string(" || ");
            break;
    }
}

// HD_OSFT_TD tap then RH1 tap, within this long, turns on Caps Word (see
// osft_td_finished/process_record_user below).
#define OSFT_SPACE_SEQ_TERM 300

static bool     osft_tap_pending = false;
static uint16_t osft_tap_time    = 0;

// Whether Caps Word was on when HD_OSFT_TD was last physically pressed.
// Captured here because core's caps_word processing runs *after*
// process_record_user but *before* process_tap_dance: it doesn't recognize
// tap-dance keycodes, so it always turns Caps Word off on press, before
// osft_td_finished ever sees it -- a live is_caps_word_on() check there
// would always read false.
static bool osft_press_caps_word_was_on = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_tap_hold(keycode, record)) return false;

    if (keycode == HD_OSFT_TD && record->event.pressed) {
        osft_press_caps_word_was_on = is_caps_word_on();
    }

    if (record->event.pressed) {
        if (keycode == HD_SPACE && record->tap.count && osft_tap_pending && timer_elapsed(osft_tap_time) < OSFT_SPACE_SEQ_TERM) {
            osft_tap_pending = false;
            clear_oneshot_mods(); // cancel the shift armed by the HD_OSFT_TD tap
            caps_word_on();
            return false;
        }
        osft_tap_pending = false;
    }

    return true;
}

/*
 * Tap dance for HD_OSFT_TD (currently HD_LH2): tap = one-shot shift, double
 * tap = Caps Lock, hold = L_NAV. A tap also starts (or ends) the
 * HD_OSFT_TD-then-RH1 Caps Word sequence handled above.
 *
 * A plain LT() can't do this: its tap argument must be a basic keycode (so
 * it can't send a one-shot mod), and it only has a tap/hold split, not a
 * double-tap. `state->pressed`, not `state->interrupted`, decides hold here
 * so that -- same as every other layer-tap key in this keymap -- pressing
 * another key while HD_OSFT_TD is still held resolves it as a hold
 * immediately, rather than waiting to see if HD_OSFT_TD itself gets tapped
 * again.
 */
typedef enum {
    OSFT_TD_NONE,
    OSFT_TD_SINGLE_TAP,
    OSFT_TD_SINGLE_HOLD,
    OSFT_TD_DOUBLE_TAP,
} osft_td_state_t;

static osft_td_state_t osft_td_state = OSFT_TD_NONE;

static osft_td_state_t osft_td_classify(tap_dance_state_t *state) {
    if (state->count == 1) return state->pressed ? OSFT_TD_SINGLE_HOLD : OSFT_TD_SINGLE_TAP;
    if (state->count == 2) return OSFT_TD_DOUBLE_TAP;
    return OSFT_TD_NONE;
}

void osft_td_finished(tap_dance_state_t *state, void *user_data) {
    osft_td_state = osft_td_classify(state);
    switch (osft_td_state) {
        case OSFT_TD_SINGLE_TAP:
            // Caps Lock/Caps Word were already on: a plain tap turns them
            // back off (core caps_word processing already did so for Caps
            // Word, see osft_press_caps_word_was_on) instead of arming the
            // one-shot shift/RH1 sequence.
            if (host_keyboard_led_state().caps_lock) {
                tap_code(KC_CAPS_LOCK);
            } else if (!osft_press_caps_word_was_on) {
                set_oneshot_mods(MOD_BIT(KC_LSFT));
                osft_tap_pending = true;
                osft_tap_time    = timer_read();
            }
            break;
        case OSFT_TD_SINGLE_HOLD:
            layer_on(L_NAV);
            break;
        case OSFT_TD_DOUBLE_TAP:
            // Idempotent: a redundant double tap while already on shouldn't
            // toggle it back off.
            if (!host_keyboard_led_state().caps_lock) {
                tap_code(KC_CAPS_LOCK);
            }
            break;
        default:
            break;
    }
}

void osft_td_reset(tap_dance_state_t *state, void *user_data) {
    if (osft_td_state == OSFT_TD_SINGLE_HOLD) layer_off(L_NAV);
    osft_td_state = OSFT_TD_NONE;
}

/*
 * Tap dance for HD_ALPHA2_TD (HD_RH2): tap = one-shot L_ALPHA2, hold =
 * L_CFG. A plain LT() can't do this since OSL() isn't a basic keycode, so
 * the tap arms the one-shot layer directly the same way QMK's own OSL()
 * keycode does (see quantum/action.c): set_oneshot_layer() then
 * clear_oneshot_layer_state(ONESHOT_PRESSED), both called here since by the
 * time a plain tap is recognized the physical press and release have
 * already happened.
 *
 * As with osft_td_classify, `state->pressed` (not `state->interrupted`)
 * decides hold, so chording another key while RH2 is still held resolves
 * it as a hold immediately.
 */
typedef enum {
    ALPHA2_TD_NONE,
    ALPHA2_TD_TAP,
    ALPHA2_TD_HOLD,
} alpha2_td_state_t;

static alpha2_td_state_t alpha2_td_state = ALPHA2_TD_NONE;

static alpha2_td_state_t alpha2_td_classify(tap_dance_state_t *state) {
    if (state->count == 1) return state->pressed ? ALPHA2_TD_HOLD : ALPHA2_TD_TAP;
    return ALPHA2_TD_NONE;
}

void alpha2_td_finished(tap_dance_state_t *state, void *user_data) {
    alpha2_td_state = alpha2_td_classify(state);
    switch (alpha2_td_state) {
        case ALPHA2_TD_TAP:
            set_oneshot_layer(L_ALPHA2, ONESHOT_START);
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
        case ALPHA2_TD_HOLD:
            layer_on(L_CFG);
            break;
        default:
            break;
    }
}

void alpha2_td_reset(tap_dance_state_t *state, void *user_data) {
    if (alpha2_td_state == ALPHA2_TD_HOLD) layer_off(L_CFG);
    alpha2_td_state = ALPHA2_TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_OSFT]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, osft_td_finished, osft_td_reset),
    [TD_ALPHA2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alpha2_td_finished, alpha2_td_reset),
};
