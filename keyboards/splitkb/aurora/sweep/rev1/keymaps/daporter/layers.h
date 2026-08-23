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

#pragma once

// L_SYM: Symbols and punctuation.
//
// ╭─────────────────╮   ╭─────────────────╮
// │  `  <  >  -  |  │   │  ^  {  }  $  \  │
// │  !  *  /  =  &  │   │  _  (  )  ;  "  │
// │  ~  +  [  ]  %  │   │  @  :  ,  .  '  │
// ╰──────────╮      │   │      ╭──────────╯
//            ╰──-───╯   ╰──────╯

#define SYM_LT4 KC_GRV
#define SYM_LT3 KC_LEFT_ANGLE_BRACKET
#define SYM_LT2 KC_RIGHT_ANGLE_BRACKET
#define SYM_LT1 KC_MINUS
#define SYM_LT0 KC_PIPE
#define SYM_RT0 KC_CIRCUMFLEX
#define SYM_RT1 KC_LEFT_CURLY_BRACE
#define SYM_RT2 KC_RIGHT_CURLY_BRACE
#define SYM_RT3 KC_DOLLAR
#define SYM_RT4 KC_BACKSLASH

#define SYM_LM4 KC_EXCLAIM
#define SYM_LM3 KC_ASTERISK
#define SYM_LM2 KC_SLASH
#define SYM_LM1 KC_EQUAL
#define SYM_LM0 KC_AMPERSAND
#define SYM_RM0 KC_UNDERSCORE
#define SYM_RM1 KC_LEFT_PAREN
#define SYM_RM2 KC_RIGHT_PAREN
#define SYM_RM3 KC_SEMICOLON
#define SYM_RM4 KC_DOUBLE_QUOTE

#define SYM_LB4 KC_TILDE
#define SYM_LB3 KC_PLUS
#define SYM_LB2 KC_LEFT_BRACKET
#define SYM_LB1 KC_RIGHT_BRACKET
#define SYM_LB0 KC_PERCENT
#define SYM_RB0 KC_AT
#define SYM_RB1 KC_COLON
#define SYM_RB2 KC_COMMA
#define SYM_RB3 KC_DOT
#define SYM_RB4 KC_QUOTE

#define SYM_LH2 _______
#define SYM_LH1 _______
#define SYM_RH1 _______
#define SYM_RH2 _______

// L_NUM: Function keys and numbers.
//
// ╭───────────────────────╮   ╭─────────────────────╮
// │  F10 F9  F8  F7  F13  │   │  /   7   8   9   -  │
// │  F11 F3  F2  F1  F14  │   │  *   1   2   3   +  │
// │  F12 F6  F5  F4  INS  │   │  ,   4   5   6   =  │
// ╰────────────╮    L_NUM │   │  0   . ╭────────────╯
//              ╰──────-───╯   ╰────────╯

#define NUM_LT4 KC_F10
#define NUM_LT3 KC_F9
#define NUM_LT2 KC_F8
#define NUM_LT1 KC_F7
#define NUM_LT0 KC_F13
#define NUM_RT0 KC_SLASH
#define NUM_RT1 KC_7
#define NUM_RT2 KC_8
#define NUM_RT3 KC_9
#define NUM_RT4 KC_MINUS

#define NUM_LM4 KC_F11
#define NUM_LM3 KC_F3
#define NUM_LM2 KC_F2
#define NUM_LM1 KC_F1
#define NUM_LM0 KC_F14
#define NUM_RM0 KC_ASTERISK
#define NUM_RM1 KC_1
#define NUM_RM2 KC_2
#define NUM_RM3 KC_3
#define NUM_RM4 KC_PLUS

#define NUM_LB4 KC_F12
#define NUM_LB3 KC_F6
#define NUM_LB2 KC_F5
#define NUM_LB1 KC_F4
#define NUM_LB0 KC_INSERT
#define NUM_RB0 KC_COMMA
#define NUM_RB1 KC_4
#define NUM_RB2 KC_5
#define NUM_RB3 KC_6
#define NUM_RB4 KC_EQUAL

#define NUM_LH2 _______
#define NUM_LH1 _______
#define NUM_RH1 KC_0
#define NUM_RH2 KC_DOT

// L_NAV: Keyboard navigation. The left home row is transparent -- mods are
// reached via the alpha layer's own home-row mods, held concurrently with
// this layer's key (LH2).
// ╭──────────────────────────────────╮   ╭──────────────────────────────╮
// │            ⇤    ⇥                │   │  ⇞   ⇱    ↑    ⇲        │
// │                     ln↑          │   │  ⇟   ←    ↓    →        │
// │                     ln↓          │   │      wd←   wd→          │
// ╰────────────────────────╮         │   │           ╭──────────────────╯
//                          ╰─────────╯   ╰───────────╯

#define NAV_LT4 _______
#define NAV_LT3 C(KC_PAGE_UP)
#define NAV_LT2 C(KC_PAGE_DOWN)
#define NAV_LT1 _______
#define NAV_LT0 _______
#define NAV_RT0 KC_PAGE_UP
#define NAV_RT1 KC_HOME
#define NAV_RT2 KC_UP
#define NAV_RT3 KC_END
#define NAV_RT4 _______

#define NAV_LM4 _______
#define NAV_LM3 _______
#define NAV_LM2 _______
#define NAV_LM1 SELECT_LINE_UP
#define NAV_LM0 _______
#define NAV_RM0 KC_PAGE_DOWN
#define NAV_RM1 KC_LEFT
#define NAV_RM2 KC_DOWN
#define NAV_RM3 KC_RIGHT
#define NAV_RM4 _______

#define NAV_LB4 _______
#define NAV_LB3 _______
#define NAV_LB2 _______
#define NAV_LB1 SELECT_LINE
#define NAV_LB0 _______
#define NAV_RB0 _______
#define NAV_RB1 SELECT_WORD_BACK
#define NAV_RB2 SELECT_WORD
#define NAV_RB3 _______
#define NAV_RB4 _______

#define NAV_LH2 _______
#define NAV_LH1 _______
#define NAV_RH1 _______
#define NAV_RH2 _______

// L_CFG: Keyboard configuration. Both hands are transparent -- mods are
// reached via the alpha layer's own home-row mods, held concurrently with
// this layer's key (RH2).
// ╭─────────────────────────╮   ╭─────────────────────╮
// │     Menu  Caps   CW     │   │                     │
// │                         │   │                     │
// │                         │   │  BOOT               │
// ╰──────────────╮          │   │         ╭───────────╯
//                ╰──────────╯   ╰─────────╯

#define CFG_LT4 _______
#define CFG_LT3 KC_APPLICATION
#define CFG_LT2 KC_CAPS_LOCK
#define CFG_LT1 CW_TOGG
#define CFG_LT0 _______
#define CFG_RT0 _______
#define CFG_RT1 _______
#define CFG_RT2 _______
#define CFG_RT3 _______
#define CFG_RT4 _______

#define CFG_LM4 _______
#define CFG_LM3 _______
#define CFG_LM2 _______
#define CFG_LM1 _______
#define CFG_LM0 _______
#define CFG_RM0 _______
#define CFG_RM1 _______
#define CFG_RM2 _______
#define CFG_RM3 _______
#define CFG_RM4 _______

#define CFG_LB4 _______
#define CFG_LB3 _______
#define CFG_LB2 _______
#define CFG_LB1 _______
#define CFG_LB0 _______
#define CFG_RB0 QK_BOOT
#define CFG_RB1 _______
#define CFG_RB2 _______
#define CFG_RB3 _______
#define CFG_RB4 _______

#define CFG_LH2 _______
#define CFG_LH1 _______
#define CFG_RH1 _______
#define CFG_RH2 _______
