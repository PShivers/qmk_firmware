#include QMK_KEYBOARD_H
#include <stdint.h>

#ifndef SAFE_RANGE
#    define SAFE_RANGE 0x1000
#endif

#define _CANARY 0
#define _NUMFN 1
#define _SYMBOL 2
#define _NAV 3

enum custom_keycodes {
    CANARY = SAFE_RANGE,
    NUMFN,
    SYMBOL,
    NAV,
};

// Define the combo keys
enum combo_events { COMBO_CAPSLOCK, COMBO_LENGTH };

// Specify the keys for the combo
const uint16_t PROGMEM capslock_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};

// Define the combo actions
combo_t key_combos[COMBO_LENGTH] = {
    [COMBO_CAPSLOCK] = COMBO(capslock_combo, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_CANARY] = LAYOUT(
        KC_TAB, KC_W, KC_L, KC_Y, KC_P, KC_B,                       KC_Z, KC_F, KC_O, KC_U, KC_SCLN, KC_DEL,
        KC_BSPC, KC_C, KC_R, KC_S, LSFT_T(KC_T), MEH_T(KC_G),       KC_M, RSFT_T(KC_N), KC_E, KC_I, KC_A, KC_QUOT,
        KC_LSFT, KC_Q, KC_J, KC_V, KC_D, KC_K,                      KC_X, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LALT, LT(MO(_NUMFN), KC_ENT), LCTL_T(KC_SPC),            LT(MO(_NAV), KC_ENT), LT(MO(_SYMBOL), KC_DEL), KC_LGUI
    ),

    [_NUMFN] = LAYOUT(
        KC_ESC, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,               KC_NO, KC_7, KC_8, KC_9, KC_MEDIA_SELECT, KC_DEL,
        KC_BSPC, KC_F5, KC_F6, KC_F7, KC_F8, LCTL(KC_GRV),          KC_NO, KC_4, KC_5, KC_6, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
        KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, LCTL(KC_SLSH),         KC_NO, KC_1, KC_2, KC_3, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,
        LCTL(LGUI(KC_LEFT)), KC_TRNS, LCTL(LGUI(KC_RIGHT)),         KC_TRNS, KC_0, KC_TRNS
    ),  

    [_SYMBOL] = LAYOUT(
        KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_LBRC, KC_RBRC, KC_MINS, KC_SCLN, KC_DEL,
        KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 KC_NO, KC_LPRN, KC_RPRN, KC_EQL, KC_GT, KC_GRV,
        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 KC_NO, KC_LCBR, KC_RCBR, KC_DOT, KC_BSLS, KC_RSFT,
        KC_NO, KC_NO, KC_NO,                                        KC_NO, KC_TRNS, KC_NO
    ),

    [_NAV] = LAYOUT(
        KC_NO, KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO,             KC_NO, KC_PGDN, KC_UP, KC_PGUP, KC_ACL0, KC_ACL1,
        KC_NO, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,         LCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, LCTL(KC_RGHT), KC_ACL2,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_HOME, KC_NO, KC_END, KC_NO, LCA(KC_RGHT),
        KC_BTN2, KC_BTN3, KC_BTN1,                                  KC_TRNS, KC_NO, KC_NO
    ),
};