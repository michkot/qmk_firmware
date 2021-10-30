/* Copyright 2020 null-ll
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

#include "basketweave_s.h"

const uint16_t APP = KC_APP; // or  KC_PSCR !;
const uint16_t PSCR = KC_INS;
const uint16_t INS = KC_INS; // not rly!

const uint16_t L1orCL = LT(1,KC_CAPS);
const uint16_t L1orAPP = LT(1, APP);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_default(  /* base */
     /* esc       `        1        2        3        4        5        6        7        8        9        0        -        =       bspc            */
      KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, INS,
     /* ins     tab        Q        W        E        R        T        Y        U        I        O        P        [        ]        \              */
      KC_HOME, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
     /* rotary  caps       A        S        D        F        G        H        J        K        L        ;        '       enter                    */
      KC_END,  L1orCL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_MUTE,
     /*         shift      Z        X        C        V        B        B        N        M        ,        .        /       shift     up             */
               KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
     /*         ctrl      win      alt     space              fn               space              alt      ctrl              left     down     right  */
               KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,           L1orAPP,          KC_SPC,           KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RIGHT
    ),

  [1] = LAYOUT_default(  /* fn */
     /* esc       `        1        2        3        4        5        6        7        8        9        0        -        =       bspc            */
      KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_MPRV,
     /* ins     tab        Q        W        E        R        T        Y        U        I        O        P        [        ]        \              */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAUS, PSCR,    KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT,
     /* rotary  caps       A        S        D        F        G        H        J        K        L        ;        '       enter                    */
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_MPLY,
     /*         shift      Z        X        C        V        B        B        N        M        ,        .        /       shift     up             */
               KC_TRNS, KC_TRNS, KC_TRNS, KC_CALC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,
     /*         ctrl      win      alt     space              fn               space              alt      ctrl              left     down     right  */
               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_HOME, KC_PGDN, KC_END
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)){
    case 1: {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    default: {
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
    }
    return true;
}
