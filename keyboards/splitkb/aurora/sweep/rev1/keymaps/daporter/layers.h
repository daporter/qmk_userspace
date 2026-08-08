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

#pragma once

/*
 * L_SYM: Symbols and punctuation. Mirrored left/right of the natural QWERTY
 * position so that the highest-frequency brackets land on the opposite hand
 * from the thumb (Space) that holds this layer active.
 * ╭─────────────────╮   ╭─────────────────╮
 * │     ?  $  _  &  │   │  .  <  @  >  `  │
 * │  %  [  {  (  |  │   │  #  =  +  -  !  │
 * │     ]  }  )  ~  │   │  \  ^  *  /  :  │
 * ╰──────────╮      │   │      ╭──────────╯
 *            ╰──-───╯   ╰──────╯
 */

#define LS_LT4 _______
#define LS_LT3 KC_QUESTION
#define LS_LT2 KC_DOLLAR
#define LS_LT1 KC_UNDERSCORE
#define LS_LT0 KC_AMPERSAND
#define LS_RT0 KC_DOT
#define LS_RT1 KC_LEFT_ANGLE_BRACKET
#define LS_RT2 KC_AT
#define LS_RT3 KC_RIGHT_ANGLE_BRACKET
#define LS_RT4 KC_GRV

#define LS_LM4 KC_PERCENT
#define LS_LM3 KC_LEFT_BRACKET
#define LS_LM2 KC_LEFT_CURLY_BRACE
#define LS_LM1 KC_LEFT_PAREN
#define LS_LM0 KC_PIPE
#define LS_RM0 KC_HASH
#define LS_RM1 KC_EQUAL
#define LS_RM2 KC_PLUS
#define LS_RM3 KC_MINUS
#define LS_RM4 KC_EXCLAIM

#define LS_LB4 _______
#define LS_LB3 KC_RIGHT_BRACKET
#define LS_LB2 KC_RIGHT_CURLY_BRACE
#define LS_LB1 KC_RIGHT_PAREN
#define LS_LB0 KC_TILDE
#define LS_RB0 KC_BACKSLASH
#define LS_RB1 KC_CIRCUMFLEX
#define LS_RB2 KC_ASTERISK
#define LS_RB3 KC_SLASH
#define LS_RB4 KC_COLON

#define LS_LH2 _______
#define LS_LH1 _______
#define LS_RH1 _______
#define LS_RH2 _______

/*
 * L_NUM: Function keys and numbers.
 *
 * ╭───────────────────────╮   ╭─────────────────────╮
 * │  F10 F9  F8  F7  F13  │   │  /   7   8   9   -  │
 * │  F11 F3  F2  F1  F14  │   │  *   1   2   3   +  │
 * │  F12 F6  F5  F4  INS  │   │  ,   4   5   6   =  │
 * ╰────────────╮    L_NUM │   │  0   . ╭────────────╯
 *              ╰──────-───╯   ╰────────╯
 */

#define LN_LT4 KC_F10
#define LN_LT3 KC_F9
#define LN_LT2 KC_F8
#define LN_LT1 KC_F7
#define LN_LT0 KC_F13
#define LN_RT0 KC_SLASH
#define LN_RT1 KC_7
#define LN_RT2 KC_8
#define LN_RT3 KC_9
#define LN_RT4 KC_MINUS

#define LN_LM4 LGUI_T(KC_F11)
#define LN_LM3 LALT_T(KC_F3)
#define LN_LM2 LCTL_T(KC_F2)
#define LN_LM1 LSFT_T(KC_F1)
#define LN_LM0 KC_F14
#define LN_RM0 KC_ASTERISK
#define LN_RM1 RSFT_T(KC_1)
#define LN_RM2 RCTL_T(KC_2)
#define LN_RM3 RALT_T(KC_3)
#define LN_RM4 RGUI_T(KC_PLUS)

#define LN_LB4 KC_F12
#define LN_LB3 KC_F6
#define LN_LB2 KC_F5
#define LN_LB1 KC_F4
#define LN_LB0 KC_INSERT
#define LN_RB0 KC_COMMA
#define LN_RB1 KC_4
#define LN_RB2 KC_5
#define LN_RB3 KC_6
#define LN_RB4 KC_EQUAL

#define LN_LH2 _______
#define LN_LH1 _______
#define LN_RH1 KC_0
#define LN_RH2 KC_DOT

/*
 * L_NAV: Keyboard navigation.
 * ╭──────────────────────────────────╮   ╭──────────────────────────────╮
 * │       ⇧⇥   ⇥              │   │        ⇱    ⇞    ⇟    ⇲  │
 * │  ❖      ⎇      ⌃      ⇧        │   │  ^G   ←    ↑    ↓    →   │
 * │                             │   │  undo  copy  pste  cut  ^A  │
 * ╰────────────────────────╮         │   │           ╭──────────────────╯
 *                          ╰─────────╯   ╰───────────╯
 */

#define LV_LT4 _______
#define LV_LT3 _______
#define LV_LT2 LCTL(LSFT(KC_TAB))
#define LV_LT1 LCTL(KC_TAB)
#define LV_LT0 _______
#define LV_RT0 _______
#define LV_RT1 KC_HOME
#define LV_RT2 KC_PAGE_UP
#define LV_RT3 KC_PAGE_DOWN
#define LV_RT4 KC_END

#define LV_LM4 KC_LGUI
#define LV_LM3 KC_LALT
#define LV_LM2 KC_LCTL
#define LV_LM1 KC_LSFT
#define LV_LM0 _______
#define LV_RM0 LCTL(KC_G)
#define LV_RM1 KC_LEFT
#define LV_RM2 KC_UP
#define LV_RM3 KC_DOWN
#define LV_RM4 KC_RIGHT

#define LV_LB4 _______
#define LV_LB3 _______
#define LV_LB2 _______
#define LV_LB1 _______
#define LV_LB0 _______
/* No dedicated redo key: NAV + LV_LM1 (shift) + RB0 already composes to
 * Ctrl+Shift+Z, since held real mods stack with a modded keycode's own. */
#define LV_RB0 LCTL(KC_Z)
#define LV_RB1 LCTL(KC_C)
#define LV_RB2 LCTL(KC_V)
#define LV_RB3 LCTL(KC_X)
#define LV_RB4 LCTL(KC_A)

/* LV_LH2 is unreachable: it's the same physical key that holds NAV active
 * (HD_BACKSPACE = LT(L_NAV, KC_BACKSPACE)), so it can never be looked up
 * again while held. */
#define LV_LH2 _______
#define LV_LH1 _______
#define LV_RH1 LCTL(KC_BACKSPACE)
#define LV_RH2 SELWORD

/*
 * L_CFG: Keyboard configuration + modifier chording. The home row is a
 * mirrored set of plain (non-tap-hold) mods, so any combination can be held
 * simultaneously or sustained across several taps without the tap-hold
 * races/chordal-hold restrictions that apply to the base layer's home-row
 * mods -- needed for chords like Emacs's C-M-f, or sequences like C-c C-x.
 * ╭─────────────────────────╮   ╭─────────────────────╮
 * │     Menu  Caps   CW     │   │                     │
 * │  ❖    ⎇     ⌃     ⇧     │   │  ⇧    ⌃    ⎇    ❖  │
 * │  BOOT                   │   │                     │
 * ╰──────────────╮          │   │         ╭───────────╯
 *                ╰──────────╯   ╰─────────╯
 */

#define LC_LT4 _______
#define LC_LT3 KC_APPLICATION
#define LC_LT2 KC_CAPS_LOCK
#define LC_LT1 CW_TOGG
#define LC_LT0 _______
#define LC_RT0 _______
#define LC_RT1 _______
#define LC_RT2 _______
#define LC_RT3 _______
#define LC_RT4 _______

#define LC_LM4 KC_LGUI
#define LC_LM3 KC_LALT
#define LC_LM2 KC_LCTL
#define LC_LM1 KC_LSFT
#define LC_LM0 _______
#define LC_RM0 _______
#define LC_RM1 KC_RSFT
#define LC_RM2 KC_RCTL
#define LC_RM3 KC_RALT
#define LC_RM4 KC_RGUI

#define LC_LB4 QK_BOOT
#define LC_LB3 _______
#define LC_LB2 _______
#define LC_LB1 _______
#define LC_LB0 _______
#define LC_RB0 _______
#define LC_RB1 _______
#define LC_RB2 _______
#define LC_RB3 _______
#define LC_RB4 _______

#define LC_LH2 _______
#define LC_LH1 _______
#define LC_RH1 _______
#define LC_RH2 _______
