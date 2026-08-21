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
 * AltGr on some OS layouts -- see BASE_RM3 in handsdown_au.h/vb.h for
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
#define BASE_LT4 KC_X
#define BASE_LT3 KC_W
#define BASE_LT2 KC_M
#define BASE_LT1 KC_G
#define BASE_LT0 KC_J
#define BASE_RT0 KC_HASH
#define BASE_RT1 KC_DOT
#define BASE_RT2 KC_SLASH
#define BASE_RT3 KC_DOUBLE_QUOTE
#define BASE_RT4 KC_QUOTE

#define BASE_LM4 LCTL_T(KC_S)
#define BASE_LM3 LALT_T(KC_C)
#define BASE_LM2 LGUI_T(KC_N)
#define BASE_LM1 LSFT_T(KC_T)
#define BASE_LM0 KC_K
#define BASE_RM0 KC_COMMA
#define BASE_RM1 RSFT_T(KC_A)
#define BASE_RM2 RGUI_T(KC_E)
#define BASE_RM3 LALT_T(KC_I)
#define BASE_RM4 RCTL_T(KC_H)

#define BASE_LB4 KC_F
#define BASE_LB3 KC_P
#define BASE_LB2 KC_L
#define BASE_LB1 KC_D
#define BASE_LB0 KC_V
#define BASE_RB0 KC_MINUS
#define BASE_RB1 KC_U
#define BASE_RB2 KC_O
#define BASE_RB3 KC_Y
#define BASE_RB4 KC_B

#define BASE_LH2 LT(L_NAV, KC_BACKSPACE)
#define BASE_LH1 LT(L_NUM, KC_R)
#define BASE_RH1 BASE_SPACE
#define BASE_RH2 LT(L_CFG, KC_ENTER)

// clang-format on
