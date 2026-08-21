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
 * Ported from Hands Down Vibranium f
 * (https://raw.githubusercontent.com/moutis/HandsDown/main/handsdown/vf-config.h),
 * with home-row mods re-mirrored to match this keymap's handedness
 * convention instead of vf's (vf holds every home-row mod on the right-side
 * variant regardless of hand; here each hand holds its own side's mod,
 * except Alt, which stays LALT_T on both hands to avoid KC_RALT acting as
 * AltGr on some OS layouts -- see LB_RM3 in handsdown_au.h/vb.h for
 * precedent).
 *
 * vf natively puts L_NUM on the K home-row key and duplicates L_NAV across
 * both thumbs. To keep layers.h layout-agnostic, this file instead keeps our
 * "4 aux keys -> 4 distinct layers" convention: L_NUM moves to vf's own
 * thumb letter, R, in place of Gold's T.
 *
 * Base (alpha) layer Hands Down Vibranium f (HRMs + thumb mods):
 * ╭─────────────────────╮   ╭──────────────────────╮
 * │  X   W   M   G   J  │   │  #$  .:  /\*  "?  '! │
 * │  S   C   N   T   K  │   │  ,;  A   E   I   H  │
 * │  F   P   L   D   V  │   │  -+  U   O   Y   B  │
 * ╰───────────╮ bsp  R  │   │ spc  ret ╭───────────╯
 *             ╰─────────╯   ╰──────────╯
 *
 * Q & Z are available via combos.
 */

// clang-format off
#define LB_LT4 KC_X
#define LB_LT3 KC_W
#define LB_LT2 KC_M
#define LB_LT1 KC_G
#define LB_LT0 KC_J
#define LB_RT0 KC_HASH
#define LB_RT1 KC_DOT
#define LB_RT2 KC_SLASH
#define LB_RT3 KC_DOUBLE_QUOTE
#define LB_RT4 KC_QUOTE

#define LB_LM4 LCTL_T(KC_S)
#define LB_LM3 LALT_T(KC_C)
#define LB_LM2 LGUI_T(KC_N)
#define LB_LM1 LSFT_T(KC_T)
#define LB_LM0 KC_K
#define LB_RM0 KC_COMMA
#define LB_RM1 RSFT_T(KC_A)
#define LB_RM2 RGUI_T(KC_E)
#define LB_RM3 LALT_T(KC_I)
#define LB_RM4 RCTL_T(KC_H)

#define LB_LB4 KC_F
#define LB_LB3 KC_P
#define LB_LB2 KC_L
#define LB_LB1 KC_D
#define LB_LB0 KC_V
#define LB_RB0 KC_MINUS
#define LB_RB1 KC_U
#define LB_RB2 KC_O
#define LB_RB3 KC_Y
#define LB_RB4 KC_B

#define LB_LH2 LT(L_NAV, KC_BACKSPACE)
#define LB_LH1 LT(L_NUM, KC_R)
#define LB_RH1 KEY_SPACE
#define LB_RH2 LT(L_CFG, KC_ENTER)

// clang-format on
