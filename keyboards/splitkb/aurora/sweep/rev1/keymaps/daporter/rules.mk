# Copyright 2023-2024 David Porter <david@daporter.net>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Convert from Elite-C to standard RP2040.
CONVERT_TO = promicro_rp2040

# Ensure compatibility with the rp2040 bootloader.
BOOTLOADER = rp2040

COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes

SRC += features/achordion.c
SRC += features/custom_shift_keys.c

VPATH += keyboards/gboards      # Allows easier combo definitions
