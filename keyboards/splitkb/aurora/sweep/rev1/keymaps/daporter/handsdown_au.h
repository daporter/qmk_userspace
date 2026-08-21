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
 * Place these BASE keycodes on the keymap for variation independent spatial
 * referencing by key position.
 *
 * Base (alpha) layer Hands Down Gold (HRMs + thumb mods):
 * ╭─────────────────────╮   ╭──────────────────────╮
 * │  J   G   M   P   V  │   │  #$  .:  /\*  "?  '! │
 * │  R   S   N   D   B  │   │  ,;  A   E   I   H   │
 * │  X   F   L   C   W  │   │  -+  U   O   Y   K   │
 * ╰───────────╮  ⇧   T  │   │ spc  -  ╭───────────╯
 *             ╰─────────╯   ╰──────────╯
 *
 * Q & Z, and editing keys (Backspace, Delete, Tab, Enter, etc.), are
 * available via combos -- see combos.def. LH2 double-tap enables Caps Lock;
 * LH2 tap then RH1 tap enables Caps Word. LH2 tap disables whichever of the
 * two is on. RH2 tap one-shots L_AL2; RH2 hold is L_CFG.
 */

// clang-format off
#define BASE_LT4 KC_J
#define BASE_LT3 KC_G
#define BASE_LT2 KC_M
#define BASE_LT1 KC_P
#define BASE_LT0 KC_V
#define BASE_RT0 KC_HASH
#define BASE_RT1 KC_DOT
#define BASE_RT2 KC_SLASH
#define BASE_RT3 KC_DOUBLE_QUOTE
#define BASE_RT4 KC_QUOTE

#define BASE_LM4 LGUI_T(KC_R)
#define BASE_LM3 LALT_T(KC_S)
#define BASE_LM2 LCTL_T(KC_N)
#define BASE_LM1 LSFT_T(KC_D)
#define BASE_LM0 KC_B
#define BASE_RM0 KC_COMMA
#define BASE_RM1 RSFT_T(KC_A)
#define BASE_RM2 RCTL_T(KC_E)
#define BASE_RM3 LALT_T(KC_I)
#define BASE_RM4 RGUI_T(KC_H)

#define BASE_LB4 KC_X
#define BASE_LB3 KC_F
#define BASE_LB2 KC_L
#define BASE_LB1 KC_C
#define BASE_LB0 KC_W
#define BASE_RB0 KC_MINUS
#define BASE_RB1 KC_U
#define BASE_RB2 KC_O
#define BASE_RB3 KC_Y
#define BASE_RB4 KC_K

#define BASE_LH2 BASE_OSFT_TD
#define BASE_LH1 LT(L_NUM, KC_T)
#define BASE_RH1 BASE_SPACE
#define BASE_RH2 BASE_ALPHA2_TD

// clang-format on
