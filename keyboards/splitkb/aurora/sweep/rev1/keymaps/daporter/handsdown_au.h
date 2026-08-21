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
 * two is on. RH2 tap one-shots L_ALPHA2; RH2 hold is L_CFG.
 */

// clang-format off
#define LB_LT4 KC_J
#define LB_LT3 KC_G
#define LB_LT2 KC_M
#define LB_LT1 KC_P
#define LB_LT0 KC_V
#define LB_RT0 KC_HASH
#define LB_RT1 KC_DOT
#define LB_RT2 KC_SLASH
#define LB_RT3 KC_DOUBLE_QUOTE
#define LB_RT4 KC_QUOTE

#define LB_LM4 LGUI_T(KC_R)
#define LB_LM3 LALT_T(KC_S)
#define LB_LM2 LCTL_T(KC_N)
#define LB_LM1 LSFT_T(KC_D)
#define LB_LM0 KC_B
#define LB_RM0 KC_COMMA
#define LB_RM1 RSFT_T(KC_A)
#define LB_RM2 RCTL_T(KC_E)
#define LB_RM3 LALT_T(KC_I)
#define LB_RM4 RGUI_T(KC_H)

#define LB_LB4 KC_X
#define LB_LB3 KC_F
#define LB_LB2 KC_L
#define LB_LB1 KC_C
#define LB_LB0 KC_W
#define LB_RB0 KC_MINUS
#define LB_RB1 KC_U
#define LB_RB2 KC_O
#define LB_RB3 KC_Y
#define LB_RB4 KC_K

#define LB_LH2 KEY_OSFT_TD
#define LB_LH1 LT(L_NUM, KC_T)
#define LB_RH1 KEY_SPACE
#define LB_RH2 KEY_ALPHA2_TD

// clang-format on
