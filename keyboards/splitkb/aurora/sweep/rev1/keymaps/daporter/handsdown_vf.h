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
 * HD alpha keycodes with any hold-taps/custom keycodes.
 *
 * Ported from Hands Down Vibranium f
 * (https://raw.githubusercontent.com/moutis/HandsDown/main/handsdown/vf-config.h),
 * with home-row mods re-mirrored to match this keymap's handedness
 * convention instead of vf's (vf holds every home-row mod on the right-side
 * variant regardless of hand; here each hand holds its own side's mod,
 * except Alt, which stays LALT_T on both hands to avoid KC_RALT acting as
 * AltGr on some OS layouts -- see HD_I in handsdown_au.h for precedent).
 *
 * vf natively puts L_NUM on the K home-row key and duplicates L_NAV across
 * both thumbs. To keep layers.h layout-agnostic, this file instead keeps our
 * "4 aux keys -> 4 distinct layers" convention: L_NUM moves to vf's own
 * thumb letter, R, in place of Gold's T.
 */

// clang-format off
#define HD_A RSFT_T(KC_A)
#define HD_B KC_B
#define HD_C LALT_T(KC_C)
#define HD_D KC_D
#define HD_E RGUI_T(KC_E)
#define HD_F KC_F
#define HD_G KC_G
#define HD_H RCTL_T(KC_H)
#define HD_I LALT_T(KC_I)
#define HD_J KC_J
#define HD_K KC_K
#define HD_L KC_L
#define HD_M KC_M
#define HD_N LGUI_T(KC_N)
#define HD_O KC_O
#define HD_P KC_P
#define HD_R LT(L_NUM, KC_R)
#define HD_S LCTL_T(KC_S)
#define HD_T LSFT_T(KC_T)
#define HD_U KC_U
#define HD_V KC_V
#define HD_W KC_W
#define HD_X KC_X
#define HD_Y KC_Y

#define HD_HASH         KC_HASH
#define HD_DOT          KC_DOT
#define HD_SLASH        KC_SLASH
#define HD_DOUBLE_QUOTE KC_DOUBLE_QUOTE
#define HD_QUOTE        KC_QUOTE
#define HD_COMMA        KC_COMMA
#define HD_MINUS        KC_MINUS
#define HD_SPACE        LT(L_SYM, KC_SPACE)
#define HD_BACKSPACE    LT(L_NAV, KC_BACKSPACE)
#define HD_ENTER        LT(L_CFG, KC_ENTER)

/*
 * Place these HD keycodes on the keymap for variation independent spatial
 * referencing by key position.
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

#define HD_LT4 HD_X
#define HD_LT3 HD_W
#define HD_LT2 HD_M
#define HD_LT1 HD_G
#define HD_LT0 HD_J
#define HD_RT0 HD_HASH
#define HD_RT1 HD_DOT
#define HD_RT2 HD_SLASH
#define HD_RT3 HD_DOUBLE_QUOTE
#define HD_RT4 HD_QUOTE

#define HD_LM4 HD_S
#define HD_LM3 HD_C
#define HD_LM2 HD_N
#define HD_LM1 HD_T
#define HD_LM0 HD_K
#define HD_RM0 HD_COMMA
#define HD_RM1 HD_A
#define HD_RM2 HD_E
#define HD_RM3 HD_I
#define HD_RM4 HD_H

#define HD_LB4 HD_F
#define HD_LB3 HD_P
#define HD_LB2 HD_L
#define HD_LB1 HD_D
#define HD_LB0 HD_V
#define HD_RB0 HD_MINUS
#define HD_RB1 HD_U
#define HD_RB2 HD_O
#define HD_RB3 HD_Y
#define HD_RB4 HD_B

#define HD_LH2 HD_BACKSPACE
#define HD_LH1 HD_R
#define HD_RH1 HD_SPACE
#define HD_RH2 HD_ENTER

// clang-format on
