// Copyright 2023-2024 David Porter <david@daporter.net>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "features/tap_hold.h"

enum custom_keys {
    CK_QU = QK_USER,
};

// clang-format off
enum layers {
    L_BASE,
    L_AL2,
    L_SYM,
    L_NUM,
    L_NAV,
    L_CFG
};
// clang-format on

enum custom_tap_dances {
    TD_OSFT,   // see osft_td_* below: tap/double-tap/hold on BASE_LH2
    TD_ALPHA2, // see alpha2_td_* below: tap/hold on BASE_RH2
};

// Tap: one-shot shift. Double tap: Caps Word. Hold: L_NAV. See the osft_td_*
// tap dance callbacks below.
#define BASE_OSFT_TD TD(TD_OSFT)
// Tap: one-shot L_AL2. Hold: L_CFG. See the alpha2_td_* tap dance callbacks
// below.
#define BASE_ALPHA2_TD TD(TD_ALPHA2)

#define BASE_SPACE LT(L_SYM, KC_SPACE)

// Alpha layout (Night: https://valorance.net/night/).
#include "night.h"

#include "layers.h"

// combos.def uses layer-tap keys (e.g. BASE_LH1) and TG(L_NUM), both of
// which need enum layers, above, already declared.
#include "g/keymap_combo.h"

// Alpha Layer for a 34 key (3x5+2) form factor.
// ╭─────────────────────╮ ╭─────────────────────╮
// │ LT4 LT3 LT2 LT1 LT0 │ │ RT0 RT1 RT2 RT3 RT4 │
// │ LM4 LM3 LM2 LM1 LM0 │ │ RT0 RM1 RM2 RM3 RM4 │
// │ LB4 LB3 LB2 LB1 LB0 │ │ RB0 RB1 RB2 RB3 RB4 │
// ╰───────────╮ LH2 LH1 │ │ RH1 RH2 ╭───────────╯
//             ╰─────────╯ ╰─────────╯

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

    [L_BASE] = LAYOUT(
    BASE_LT4, BASE_LT3, BASE_LT2, BASE_LT1, BASE_LT0,     BASE_RT0, BASE_RT1, BASE_RT2, BASE_RT3, BASE_RT4,
    BASE_LM4, BASE_LM3, BASE_LM2, BASE_LM1, BASE_LM0,     BASE_RM0, BASE_RM1, BASE_RM2, BASE_RM3, BASE_RM4,
    BASE_LB4, BASE_LB3, BASE_LB2, BASE_LB1, BASE_LB0,     BASE_RB0, BASE_RB1, BASE_RB2, BASE_RB3, BASE_RB4,
                            BASE_LH2, BASE_LH1,     BASE_RH1, BASE_RH2),

    [L_AL2] = LAYOUT(
    AL2_LT4, AL2_LT3, AL2_LT2, AL2_LT1, AL2_LT0,     AL2_RT0, AL2_RT1, AL2_RT2, AL2_RT3, AL2_RT4,
    AL2_LM4, AL2_LM3, AL2_LM2, AL2_LM1, AL2_LM0,     AL2_RM0, AL2_RM1, AL2_RM2, AL2_RM3, AL2_RM4,
    AL2_LB4, AL2_LB3, AL2_LB2, AL2_LB1, AL2_LB0,     AL2_RB0, AL2_RB1, AL2_RB2, AL2_RB3, AL2_RB4,
                            AL2_LH2, AL2_LH1,     AL2_RH1, AL2_RH2),

    [L_SYM] = LAYOUT(
    SYM_LT4, SYM_LT3, SYM_LT2, SYM_LT1, SYM_LT0,     SYM_RT0, SYM_RT1, SYM_RT2, SYM_RT3, SYM_RT4,
    SYM_LM4, SYM_LM3, SYM_LM2, SYM_LM1, SYM_LM0,     SYM_RM0, SYM_RM1, SYM_RM2, SYM_RM3, SYM_RM4,
    SYM_LB4, SYM_LB3, SYM_LB2, SYM_LB1, SYM_LB0,     SYM_RB0, SYM_RB1, SYM_RB2, SYM_RB3, SYM_RB4,
                            SYM_LH2, SYM_LH1,     SYM_RH1, SYM_RH2),

    [L_NUM] = LAYOUT(
    NUM_LT4, NUM_LT3, NUM_LT2, NUM_LT1, NUM_LT0,     NUM_RT0, NUM_RT1, NUM_RT2, NUM_RT3, NUM_RT4,
    NUM_LM4, NUM_LM3, NUM_LM2, NUM_LM1, NUM_LM0,     NUM_RM0, NUM_RM1, NUM_RM2, NUM_RM3, NUM_RM4,
    NUM_LB4, NUM_LB3, NUM_LB2, NUM_LB1, NUM_LB0,     NUM_RB0, NUM_RB1, NUM_RB2, NUM_RB3, NUM_RB4,
                            NUM_LH2, NUM_LH1,     NUM_RH1, NUM_RH2),

    [L_NAV] = LAYOUT(
    NAV_LT4, NAV_LT3, NAV_LT2, NAV_LT1, NAV_LT0,     NAV_RT0, NAV_RT1, NAV_RT2, NAV_RT3, NAV_RT4,
    NAV_LM4, NAV_LM3, NAV_LM2, NAV_LM1, NAV_LM0,     NAV_RM0, NAV_RM1, NAV_RM2, NAV_RM3, NAV_RM4,
    NAV_LB4, NAV_LB3, NAV_LB2, NAV_LB1, NAV_LB0,     NAV_RB0, NAV_RB1, NAV_RB2, NAV_RB3, NAV_RB4,
                            NAV_LH2, NAV_LH1,     NAV_RH1, NAV_RH2),

    [L_CFG] = LAYOUT(
    CFG_LT4, CFG_LT3, CFG_LT2, CFG_LT1, CFG_LT0,     CFG_RT0, CFG_RT1, CFG_RT2, CFG_RT3, CFG_RT4,
    CFG_LM4, CFG_LM3, CFG_LM2, CFG_LM1, CFG_LM0,     CFG_RM0, CFG_RM1, CFG_RM2, CFG_RM3, CFG_RM4,
    CFG_LB4, CFG_LB3, CFG_LB2, CFG_LB1, CFG_LB0,     CFG_RB0, CFG_RB1, CFG_RB2, CFG_RB3, CFG_RB4,
                            CFG_LH2, CFG_LH1,     CFG_RH1, CFG_RH2),

    // clang-format on
};

const custom_shift_key_t custom_shift_keys[] = {
    // clang-format off
    { KC_DOT,      KC_COLON },
    { KC_QUOTE,    KC_DOUBLE_QUOTE },
    { KC_MINUS,    KC_SLASH },
    { KC_QUESTION, KC_EXCLAIM },
    { KC_COMMA,    KC_SEMICOLON },
    // clang-format on
};

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}

// Same as the QMK default, except KC_MINS is moved out of the shifted
// group so it sends a literal `-` (e.g. FOO-BAR) instead of `_`.
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

// Same as the QMK default, except it classifies keys by what they actually
// send on this keymap. sentence_case_press_user() runs on the *raw* keymap
// keycode, before custom_shift_keys remaps it (community modules run before
// process_record_user; see quantum.c) -- so e.g. shifted KC_QUOTE (which
// custom_shift_keys turns into "?") arrives here as plain KC_QUOTE, which
// the QMK default always classifies as a quote, never as sentence-ending.
// Mirror custom_shift_keys' table (keymap.c above) instead of the default's
// US-ANSI assumptions (e.g. it assumes shifted KC_SLASH is "?"; here it's
// "*", from custom_shift_keys).
char sentence_case_press_user(uint16_t keycode, keyrecord_t *record, uint8_t mods) {
    switch (keycode) {
        // BASE_OSFT_TD/BASE_ALPHA2_TD (tap dance for one-shot shift/Caps Word/
        // Caps Lock/NAV on BASE_LH2, one-shot L_AL2/L_CFG on BASE_RH2) don't
        // type anything themselves -- ignore them like core's own
        // QK_ONE_SHOT_MOD/QK_ONE_SHOT_LAYER ranges below, rather than
        // falling through to the "unrecognized key" branch, which would
        // wrongly reset Sentence Case state on every one-shot-shift tap
        // (e.g. arming shift for "!"/"?" via BASE_LH2 mid-sentence).
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return '\0';
    }

    if ((mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
        const bool shifted = mods & MOD_MASK_SHIFT;
        switch (keycode) {
            case KC_A ... KC_Z:
            case CK_QU:     // sends "qu"/"Qu"/"QU" (shift/Caps Word-aware)
                return 'a'; // Letter key.

            case KC_DOT: // unshifted '.'; shifted ':' (see custom_shift_keys)
                return !shifted ? '.' : '#';
            case KC_DOUBLE_QUOTE: // unshifted '"'; shifted '!' via custom_shift_keys
            case KC_QUOTE:        // unshifted '\''; shifted '?' via custom_shift_keys
                return shifted ? '.' : '\'';
            case KC_EXCLAIM:  // '!' typed directly (SYM layer LM4, or combo_EXLM)
            case KC_QUESTION: // '?' typed directly (combo_QUES)
                return '.';

            case KC_1: // shifted '!' (real Shift, not custom_shift_keys)
                return shifted ? '.' : '#';
            case KC_2 ... KC_0:       // 2 3 4 5 6 7 8 9 0
            case KC_AT ... KC_RPRN:   // @ # $ % ^ & * ( )
            case KC_MINS ... KC_SCLN: // - = [ ] backslash ;
            case KC_UNDS ... KC_COLN: // _ + { } | :
            case KC_GRV:
            case KC_COMM:
            case KC_SLASH:  // unshifted '/'; shifted '*' (not '?')
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
        case KC_EQUAL:
        case KC_EXCLAIM:
        case KC_AMPERSAND:
        case KC_PIPE:
            return true;
        default:
            return false;
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    switch (keycode) {
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

// BASE_OSFT_TD tap then RH1 tap, within this long, turns on Caps Word (see
// osft_td_finished/process_record_user below).
#define OSFT_SPACE_SEQ_TERM 300

static bool     osft_tap_pending = false;
static uint16_t osft_tap_time    = 0;

// Whether Caps Word was on when BASE_OSFT_TD was last physically pressed.
// Captured here because core's caps_word processing runs *after*
// process_record_user but *before* process_tap_dance: it doesn't recognize
// tap-dance keycodes, so it always turns Caps Word off on press, before
// osft_td_finished ever sees it -- a live is_caps_word_on() check there
// would always read false.
static bool osft_press_caps_word_was_on = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_tap_hold(keycode, record)) return false;

    if (keycode == CK_QU && record->event.pressed) {
        if (get_mods() & MOD_MASK_CAG) {
            tap_code16(KC_Q);
        } else if (is_caps_word_on()) {
            send_string("QU");
        } else {
            tap_code16(KC_Q);
            unregister_mods(MOD_MASK_SHIFT);
            tap_code16(KC_U);
        }
        return false;
    }

    if (keycode == BASE_OSFT_TD && record->event.pressed) {
        osft_press_caps_word_was_on = is_caps_word_on();
    }

    if (record->event.pressed) {
        if (keycode == BASE_SPACE && record->tap.count && osft_tap_pending && timer_elapsed(osft_tap_time) < OSFT_SPACE_SEQ_TERM) {
            osft_tap_pending = false;
            clear_oneshot_mods(); // cancel the shift armed by the BASE_OSFT_TD tap
            caps_word_on();
            return false;
        }
        osft_tap_pending = false;
    }

    return true;
}

// Tap dance for BASE_OSFT_TD (currently BASE_LH2): tap = one-shot shift, double
// tap = Caps Lock, hold = L_NAV. A tap also starts (or ends) the
// BASE_OSFT_TD-then-RH1 Caps Word sequence handled above.
//
// A plain LT() can't do this: its tap argument must be a basic keycode (so
// it can't send a one-shot mod), and it only has a tap/hold split, not a
// double-tap. `state->pressed`, not `state->interrupted`, decides hold here
// so that -- same as every other layer-tap key in this keymap -- pressing
// another key while BASE_OSFT_TD is still held resolves it as a hold
// immediately, rather than waiting to see if BASE_OSFT_TD itself gets tapped
// again.
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

// Tap dance for BASE_ALPHA2_TD (BASE_RH2): tap = one-shot L_AL2, hold =
// L_CFG. A plain LT() can't do this since OSL() isn't a basic keycode, so
// the tap arms the one-shot layer directly the same way QMK's own OSL()
// keycode does (see quantum/action.c): set_oneshot_layer() then
// clear_oneshot_layer_state(ONESHOT_PRESSED), both called here since by the
// time a plain tap is recognized the physical press and release have
// already happened.
//
// As with osft_td_classify, `state->pressed` (not `state->interrupted`)
// decides hold, so chording another key while RH2 is still held resolves
// it as a hold immediately.
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
            set_oneshot_layer(L_AL2, ONESHOT_START);
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
