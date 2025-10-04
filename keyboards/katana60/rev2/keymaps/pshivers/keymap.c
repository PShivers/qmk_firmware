/* Copyright 2019 rominronin
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
#include QMK_KEYBOARD_H

// Define layer names
enum layer_names {
    BASE, // Layer 0
    FUNC, // Layer 1 (for F-keys/NumPad)
    SYMB, // Layer 2 (Mouse Keys)
    MOUZ, // Layer 3 (Symbols/Brackets)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //
    // Layer 0: BASE - Canary/Colemak-DH Layout (15, 14, 14, 15, 12 = 70 Keys)
    //
    [BASE] = LAYOUT_1_a(
        KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  // Row 1 (15 keys)
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_PSCR, KC_PGUP, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_DEL,           // Row 2 (14 keys)
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_DEL,  KC_PGDN, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,           // Row 3 (14 keys)
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_HOME, KC_INS,  KC_END,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  // Row 4 (15 keys)
        KC_LGUI, KC_CAPS, KC_LALT, LT(1,KC_ENT), LCTL_T(KC_SPC), MEH(KC_NO), LT(3,KC_ENT), MO(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT           // Row 5 (12 keys)
    ),

    //
    // Layer 1: FUNC - F-Keys/Number Pad (15, 14, 14, 15, 12 = 70 Keys)
    //
    [FUNC] = LAYOUT_1_a(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   LCTL(KC_SLSH), KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, C(G(KC_LEFT)), KC_TRNS, C(G(KC_RIGHT)), KC_P0,   KC_TRNS, KC_0,    KC_TRNS, KC_TRNS, KC_LGUI
    ),

    //
    // Layer 2: MOUZ - Mouse Buttons/Movement (15, 14, 14, 15, 12 = 70 Keys)
    //
    [MOUZ] = LAYOUT_1_a(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MS_ACL0,
        KC_TRNS, KC_TRNS, MS_WHLU, MS_UP,   MS_WHLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, MS_WHLL, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLR, KC_TRNS, KC_TRNS, LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, LCTL(KC_RGHT), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_INS,  KC_END,  KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, MS_BTN3, MS_BTN2, MS_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    //
    // Layer 3: SYMB - Symbols/Brackets (15, 14, 14, 15, 12 = 70 Keys)
    //
    [SYMB] = LAYOUT_1_a(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LBRC, KC_RBRC, KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_EQL,  KC_GT,   KC_GRV,
        KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
