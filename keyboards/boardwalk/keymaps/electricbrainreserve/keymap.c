/*
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

enum ebr_tap_dance_keycodes { SPC_ENT, TLDQUAKE };

enum ebr_layers { _QWERTY, _FUNC, _MACROS, _RESET };

#define CTRLGRV LCTL(KC_GRV)
#define SPCENT TD(SPC_ENT)
#define QUAKETRM TD(TLDQUAKE)

qk_tap_dance_action_t tap_dance_actions[] = {
  [SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
  [TLDQUAKE] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, CTRLGRV)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 0
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │  =   │   1  │   2  │   3  │   4  │   5  │ Esc  │  Del │   6  │   7  │   8  │   9  │   0  │  -   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  \   │   Q  │   W  │   E  │   R  │   T  │PrtScn│  [   │   Y  │   U  │   I  │   O  │   P  │  ]   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   A  │   S  │   D  │   F  │   G  │TT(2) │ Home │   H  │   J  │   K  │   L  │   ;  │   '  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Shft │   Z  │   X  │   C  │   V  │   B  │TT(1) │ End  │   N  │   M  │   ,  │   .  │   /  │ Shft │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Gui  │ Alt  │ Ctrl │   `  │     Bksp    │ Space/Enter │ Left │ Down │  Up  │ Right│      │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */

 [_QWERTY] = LAYOUT_ortho_hhkb(
		KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5, KC_ESC,   KC_DEL,  KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
		KC_BSLS, KC_Q,    KC_W,    KC_E,    KC_R,     KC_T, KC_PSCR,  KC_LBRC, KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    KC_RBRC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G, TT(_RESET), 	  KC_HOME, KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B, TT(_FUNC), 	  KC_END,  KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
		         KC_LGUI, KC_LALT, KC_LCTL, QUAKETRM, 	KC_BSPC, 		      SPCENT,    KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
	),

/* 1
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Null │  F1  │  F2  │  F3  │  F4  │  F5  │  F11 │  F12 │  F6  │  F7  │  F8  │  F9  │  F10 │OSL(2)│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Null │ Null │ Ld S+│ Ld S-│Ld Sp+│Ld Sp-│ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Null │ Null │ Ld H+│ Ld H-│ Ld V+│ Ld V-│      │ Null │ Null │ Prev │ Vol- │ Vol+ │ Next │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │Ld Tog│ Ld M+│ Ld M-│ Null │     Null    │     Null    │ Prev │ Vol- │ Vol+ │ Next │      │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */

[_FUNC] = LAYOUT_ortho_hhkb(
		_______, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F11,  KC_F12, KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
		_______, _______,   _______,   _______,    _______,   _______,   _______,   _______,  _______, _______,   _______,   _______,   _______,  _______,
		_______, _______,   RGB_SAI, RGB_SAD,  RGB_SPI, RGB_SPD, _______,   _______,  _______, _______,   _______,   _______,   _______,  _______,
		_______, _______,   RGB_HUI, RGB_HUD,  RGB_VAI, RGB_VAD, _______, _______,  _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
			     RGB_TOG, RGB_MOD, RGB_RMOD, _______,   	  _______,   		       _______, 	 _______, 	KC_PGDN, KC_PGUP, _______),

/* 2
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Reset│ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Null │ Null │ Null │ Null │ Null │ Null │      │ Null │ Null │ Null │ Null │ Null │ Null │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Null │ Null │ Null │ Null │ Null │ Null │      │ Null │ Null │ Null │ Null │ Null │ Null │ Null │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ Null │ Null │ Null │ Null │	   Null     │	  Null    │	Null │ Null │ Null │ Null │      │
 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 */

[_RESET] = LAYOUT_ortho_hhkb(
		RESET, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
			     _______, _______, _______, _______,     _______, 		     _______, 	 _______, _______, _______, _______)
};
