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

/* Tap-hold configuration for home row mods. */
#define TAPPING_TERM            175
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/*
 * Enable the QK_MAKE key.  See:
 * https://docs.qmk.fm/#/quantum_keycodes?id=qmk-keycodes
 */
#define ENABLE_COMPILE_KEYCODE
