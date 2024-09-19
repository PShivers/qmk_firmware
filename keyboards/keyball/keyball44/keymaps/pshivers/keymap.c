/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_TAB   , KC_W     , KC_L     , KC_Y     , KC_P     , KC_B     ,                                        KC_Z     , KC_F     , KC_O     , KC_U     , KC_SCLN     , KC_DEL   ,
    KC_BSPC  , KC_C     , KC_R     , KC_S     , KC_T     , KC_G     ,                                        KC_M     , KC_N     , KC_E     , KC_I     , KC_A  , S(KC_7)  ,
    KC_LSFT  , KC_Q     , KC_J     , KC_V     , KC_D     , KC_K     ,                                        KC_X     , KC_H     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
              KC_LGUI, KC_LALT, LT(1,KC_ENT), LCTL_T(KC_SPC), MO(3),                                               MO(3), LT(2,KC_ENT), _______ , _______  , KC_PSCR
  ),

  [1] = LAYOUT_universal(
    _______ ,  KC_F9  , KC_F10    , KC_F11   , KC_F12    , _______    ,                         _______  , KC_7  , KC_8    , KC_9  , _______  , _______ ,
    _______ ,  KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_DEL ,                                   _______  , KC_4  , KC_5    , KC_6  , _______  , _______ ,
    _______ ,  KC_F1 , KC_F2 , KC_F3 , KC_F4  , _______ ,                                      _______  , KC_1  , KC_2    , KC_3  , _______  , _______ ,
                  _______  , _______ , _______  ,         _______  , _______  ,                   _______  , KC_0  , _______    , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______  ,_______, _______    , _______   ,_______   , _______ ,                                      _______, _______,KC_UP,_______,_______, _______  ,
    _______  ,_______, _______    , _______   ,_______   ,_______,                                        _______, KC_LEFT,KC_DOWN ,KC_RGHT,_______,_______,
    _______  ,_______, _______    , _______   ,_______   ,_______,                                        _______, _______,_______,_______,_______,_______,
                  _______ , _______  , _______  ,         _______  , _______  ,                   _______ , _______  , _______ , _______  , _______
  ),

  [3] = LAYOUT_universal(
     AML_TO  , SSNP_FRE   , SSNP_VRT  , SSNP_HOR  , _______  , _______  ,                                     _______  , _______  , _______  , _______ , _______ , _______  ,
     AML_I50  , SCRL_DVI  , CPI_I1K  , CPI_I100  , _______  , _______ ,                                     _______  , KC_BTN1  , KC_BTN2  , KC_BTN3  , _______  , _______  ,
     AML_D50 , SCRL_DVD  , CPI_D1K  , CPI_D100  , _______  , _______ ,                                     _______  , _______ , _______ , _______  , _______  , _______ ,
                   QK_BOOT  , KBC_RST  , KBC_SAVE  ,    _______  , _______  ,                _______  , _______  , _______       , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
