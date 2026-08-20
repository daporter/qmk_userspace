#pragma once

#include QMK_KEYBOARD_H

enum custom_keys {
    CK_QU = QK_USER,
};

enum custom_tap_dances {
    TD_OSFT,   // see osft_td_* in keymap.c: tap/double-tap/hold on HD_LH2
    TD_ALPHA2, // see alpha2_td_* in keymap.c: tap/hold on HD_RH2
};
