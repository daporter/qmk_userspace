# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repository is

This is a **QMK userspace** repo — an external, standalone home for one person's keyboard keymap(s), built against a separately-cloned copy of `qmk_firmware` rather than living inside a fork of it. It contains no build toolchain of its own; it only supplies keymap sources, and delegates the actual compile to `qmk_firmware` via the `qmk` CLI or the top-level `Makefile`.

Currently there is exactly one build target, declared in `qmk.json`:

- Keyboard: `splitkb/aurora/sweep/rev1` (a 34-key, 3x5+2 split, converted to run on a Liatris/RP2040 controller — see `CONVERT_TO = liatris` in `rules.mk`)
- Keymap: `daporter`, at `keyboards/splitkb/aurora/sweep/rev1/keymaps/daporter/`

## Prerequisites / environment

Building requires the `qmk` CLI with two config values pointing at a local `qmk_firmware` checkout:

```
qmk config user.qmk_home=<path to qmk_firmware clone>
qmk config user.overlay_dir=<path to this repo>
```

The `.devcontainer/` sets this up automatically (clones `qmk_firmware` to `/workspaces/qmk_firmware` and configures both paths) — use it if there's no working `qmk` environment available locally.

## Common commands

```sh
# Compile the registered keymap
qmk compile -kb splitkb/aurora/sweep/rev1 -km daporter
# Equivalent, using the userspace Makefile (forwards to $QMK_FIRMWARE_ROOT)
make splitkb/aurora/sweep/rev1:daporter

# Compile every target listed in qmk.json
qmk userspace-compile

# Flash the converted (Liatris) controller
qmk flash -kb splitkb/aurora/sweep/rev1 -km daporter

# Manage qmk.json build_targets
qmk userspace-add -kb <keyboard> -km <keymap>
qmk userspace-remove -kb <keyboard> -km <keymap>
qmk userspace-list

# Regenerate the keymap diagram (see "Keymap diagram" below)
keymap draw keyboards/splitkb/aurora/sweep/rev1/keymaps/daporter/keymap.yaml > keymap.svg
```

There is no unit test suite or linter in this repo — correctness is verified by compiling and by exercising the keymap on real hardware. `.clang-format` (Google-based, 4-space indent, no tabs) and `.clangd` describe the expected C style/tooling for editor integration.

GitHub Actions (`.github/workflows/build_binaries.yaml`) builds every `qmk.json` target on push using QMK's reusable `qmk_userspace_build.yml`/`qmk_userspace_publish.yml` workflows and publishes firmware to Releases — there's no local CI config to replicate beyond `qmk userspace-compile`.

## Keymap architecture (`keyboards/splitkb/aurora/sweep/rev1/keymaps/daporter/`)

The keymap is split across several headers, each owning one layer (or one concern), and pulled together in `keymap.c`:

- **`handsdown_vb.h`/`handsdown_au.h`/`handsdown_vf.h`/`night.h`** — alternative base alpha layers (`L_BASE`): Hands Down Vibranium b (active, e.g. `BASE_RM1 = RSFT_T(KC_A)`), Gold, Vibranium f, and Night (https://valorance.net/night/, not a Handsdown layout — same HRM/thumb-key scheme, dormant/unused so far). Each defines `BASE_<pos>` macros (e.g. `BASE_LT4`, `BASE_LM2`) named by _physical position_ (Left/Right, Top/Middle/Bottom row, column 0-4, plus `LH1/LH2`/`RH1/RH2` for the thumb keys) rather than by legend — the same convention as `SYM_*`/`NUM_*`/`NAV_*`/`CFG_*` in `layers.h`, with `BASE_` instead of a bare `B_` to avoid colliding with the `LB`/`RB` (bottom row) position suffixes — so the position grid in `keymap.c`'s `LAYOUT(...)` call stays stable even as the alpha arrangement changes. Switch variants by swapping which header `keymap.c` includes.
- **`layers.h`** — the other four layers (`L_SYM`, `L_NUM`, `L_NAV`, `L_CFG`), following the same `<prefix><pos>` naming convention (`SYM_*`, `NUM_*`, `NAV_*`, `CFG_*`, plus `AL2_*` for `L_AL2`). Each layer block is preceded by an ASCII-art diagram of the physical layout in a comment — keep these in sync when editing the `#define`s.
- **`features/tap_hold.[ch]`** — a small custom tap-hold engine, separate from QMK's built-in mod-tap/layer-tap. It calls back into `tap_hold()` (which keycodes opt in), `tap_hold_send_tap()`/`tap_hold_send_hold()` (what to send), and `tap_hold_timeout()` (per-key timing), all overridden as weak symbols and implemented in `keymap.c`. Used for keys with app-specific tap vs. hold output (e.g. `KC_EQUAL` taps `=` but holds to send `" == "`). Wired up via `process_tap_hold()` in `process_record_user()` and `tap_hold_matrix_scan()` in `matrix_scan_user()`.
- **`combos.def`** — combo definitions using `COMB(name, output, pos...)` / `SUBS(name, output, pos...)` X-macros, included via `#include "g/keymap_combo.h"` in `keymap.c`. `rules.mk` adds `VPATH += keyboards/gboards` so the build can locate the generator infrastructure this X-macro style depends on; `COMBO_ENABLE = yes` is required (also set in `rules.mk`).
- **`keymap.yaml`** — config for the third-party `keymap-drawer` tool (not run in CI); mirrors the layer/combo layout above for generating SVG diagrams. Keep in sync manually when `layers.h`/`handsdown_au.h`/`combos.def` change — see "Keymap diagram" below.
- **`keymap.json`** — declares community modules to enable (currently `getreuer/custom_shift_keys`, used for the `custom_shift_keys[]` table in `keymap.c` that remaps what Shift produces for specific keys, e.g. `Shift+,` → `;`).
- **`config.h`** — tap/hold tuning shared across home-row mods: `TAPPING_TERM`, `PERMISSIVE_HOLD`, `QUICK_TAP_TERM_PER_KEY`, `CHORDAL_HOLD`.
- **`rules.mk`** — feature flags (`MOUSEKEY_ENABLE`, `COMBO_ENABLE`, `CAPS_WORD_ENABLE`), the `features/tap_hold.c` source addition, and `CONVERT_TO = liatris`.

`keymap.c` itself wires these together: it declares the custom keycode/tap-dance enums (`CK_QU`, `TD_OSFT`/`TD_ALPHA2`), assembles the `keymaps[][MATRIX_ROWS][MATRIX_COLS]` array from the per-layer position macros, defines `custom_shift_keys[]`, and implements the QMK callbacks (`tap_hold*`, `process_record_user`, `caps_word_press_user`, `sentence_case_press_user`).

## Keymap diagram (`keymap.svg`)

`keymap.svg`, at the repo root, is a generated diagram rendered from `keymap.yaml` by the third-party [keymap-drawer](https://github.com/caksoylar/keymap-drawer) tool (`keymap` CLI, installed separately — not part of `qmk_firmware` or this repo's toolchain). It's committed so the layout is viewable directly on GitHub, and it's embedded in `README.md`.

There is no CI job or git hook that keeps `keymap.yaml`/`keymap.svg` current — **whenever a change touches layers, combos, or key legends** (`layers.h`, `handsdown_au.h`, `combos.def`, or `custom_shift_keys[]` in `keymap.c`), do both of the following as part of that same change:

1. Manually update `keymap.yaml` (`layers:`/`combos:` sections) to match — there's no generator from the C sources, so this is hand-maintained in parallel.
2. Regenerate the SVG and commit it alongside the source change:
    ```sh
    keymap draw keyboards/splitkb/aurora/sweep/rev1/keymaps/daporter/keymap.yaml > keymap.svg
    ```

## Community modules (`modules/getreuer/`)

A git submodule pinned to getreuer's community QMK modules repo. Only modules explicitly listed in a keymap's `keymap.json` (`"modules": [...]`) are compiled in — currently just `custom_shift_keys` for this keymap. (`achordion` was used previously but was dropped once its behavior was merged into QMK core — see git history if reintroducing similar per-mod behavior is needed.)
