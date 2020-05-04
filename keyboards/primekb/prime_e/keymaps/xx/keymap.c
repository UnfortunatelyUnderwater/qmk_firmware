/* Copyright 2018 Holten Campbell
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

#define _AA 0
#define _BB 1
#define _CC 2

#define cad LCTL(LALT(KC_DEL))  // makes a key that sends Control+Alt+Delete with a single keypress.
#define mac_3 C(KC_F5)

//  Macro section  //
enum custom_keycodes {  // the safe_range is 100% needed for the first enum/ macro
  mac_1  = SAFE_RANGE,
  mac_2,
  mac_4
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    //case QMKBEST:
    //    if (record->event.pressed) {
    //    // when keycode QMKBEST is pressed
    //    SEND_STRING("QMK is the best thing ever!");
    //    } else {
    //    // when keycode QMKBEST is released
    //    }
    //    break;
    case mac_1:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("k")SS_LCTRL("u"));  //  uncomments code
      }
      break;
    case mac_2:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("k")SS_LCTRL("c"));  //  comments code
      }
      break;
    case mac_4:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_RIGHT) "{\n");  // makes new brackets in Visual Studio
                                            //  should be SEND_STRING(SS_TAP(X_RIGHT) "{\n");
                                           //   the send string keycodes don't have the 4-char aliases (they really should though)
                                          //    and there aren't any shifted ones  // SEND_STRING(SS_TAP(X_RIGHT) "{" SS_TAP(X_ENTER)); 
      }
      break;
  }
  return true;
};



/*  Layer 0  (Base Layer) (_AA)  
    ┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┬────┐
    │Tab │ Q  │ W  │ E  │ R  │ T  │    │ Y  │ U  │ I  │ O  │ P  │[ { │] } │
    ├─────┬────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┬───────┤
    │ MO1 │ A  │ S  │ D  │ F  │ G  │     │ H  │ J  │ K  │ L  │; : │ ' "   │
    ├────────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┤
    │ Shift  │ Z  │ X  │ C  │ V  │ B  │Ente│ N  │ M  │, < │. > │/ ? │Shift│  // I use a DO (or SA) profile key for the enter key
    ├─────┬─────┬──────┬─────┬────────┬──────────┬─────┬──────┬─────┬─────┤  // its taller, which makes it easy to press with my right thumb
    │ Ctrl│ Alt │      │ MO2 │Back sp │  Space   │TG(2)│      │ F11 │ Del │
    └─────┴─────┘      └─────┴────────┴──────────┴─────┘      └─────┴─────┘                                                                                             */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_AA] = LAYOUT(
		KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,          KC_Y,   KC_U,    KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC,
		MO(_BB),  KC_A,     KC_S,     KC_D,   KC_F,    KC_G,          KC_H,   KC_J,    KC_K,  KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT,  KC_Z,     KC_X,     KC_C,   KC_V,    KC_B,          KC_ENT, KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
		KC_LCTL,  KC_LALT,                    MO(_CC), KC_BSPC,	      KC_SPC, TG(_CC),                            KC_F11,  KC_DEL
    ),
    

/*  Layer 1 
    ┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┬────┐
    │OnFF│stat│grad│Rain│SWRL│Xmas│    │Alt │Tab │ Up │    │    │Del │Del │
    ├─────┬────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┬───────┤  // The left side is mostly RGB control
    │ XX  │mac1│mac2│Shft│Ctrl│    │     │Shft│Left│Down│Righ│Home│  End  │
    ├────────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┤
    │  Hue-  │Hue+│    │brea│step│ONOF│    │mac4│    │    │    │Del │Shift│
    ├─────┬─────┬──────┬─────┬────────┬──────────┬─────┬──────┬─────┬─────┤
    │ F13 │ F14 │      │     │        │   mac3   │Shift│      │     │     │
    └─────┴─────┘      └─────┴────────┴──────────┴─────┘      └─────┴─────┘                                                                                              */
    [_BB] = LAYOUT(
		RGB_TOG,   RGB_M_P,   RGB_M_G,   RGB_M_R,   RGB_M_SW,   RGB_M_X,          KC_LALT,   KC_TAB,    KC_UP,     KC_NO,     KC_NO,     KC_DEL,    KC_DEL,
		KC_NO,     mac_1,     mac_2,     KC_LSFT,   KC_LCTL,    KC_NO,            KC_NO,     KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_HOME,   KC_END,
		RGB_HUD,   RGB_HUI,   KC_NO,     BL_BRTG,   BL_STEP,    BL_TOGG,          KC_NO,     mac_4,     KC_NO,     KC_NO,     KC_NO,     KC_DEL,    KC_LSFT,
		KC_F13,    KC_F14,                          RGB_VAI,    RGB_SPI,  	      mac_3,     KC_LSFT,                                    KC_NO,     KC_NO
    ),  


/*  Layer 2
    ┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┬────┐
    │ESC │1 ! │2 @ │3 # │4 $ │5 % │    │6 ^ │7 & │8 * │9 ( │0 ) │- _ │= + │
    ├─────┬────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┬───────┤
    │Caps │INS │    │    │    │ONOF│     │` ~ │\ | │    │    │    │       │
    ├────────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┤
    │  Mute  │back│next│alt<│alt>│CAD │P/S │    │    │    │ .  │File│Calc │
    ├─────┬─────┬──────┬─────┬────────┬──────────┬─────┬──────┬─────┬─────┤
    │Vol- │Vol+ │      │ XX  │PlayPaus│  Shift   │TG(0)│      │SCRd │SCRu │
    └─────┴─────┘      └─────┴────────┴──────────┴─────┘      └─────┴─────┘                                                                                              */
    [_CC] = LAYOUT(
		KC_ESC,   KC_1,      KC_2,          KC_3,      KC_4,         KC_5,             KC_6,      KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,
		KC_CAPS,  KC_INS,    KC_NO,         KC_NO,     KC_NO,        BL_TOGG,          KC_GRV,    KC_NUBS,  KC_NO,   KC_NO,   KC_NO,    KC_NO,
		KC_MUTE,  KC_MPRV,   KC_MNXT,  A(S(KC_COMM)),  A(S(KC_DOT)), cad,              KC_PSCR,   KC_NO,    KC_NO,   KC_NO,   KC_DOT,   KC_MYCM,  KC_CALC,
		KC_VOLD,  KC_VOLU,                             KC_NO,        KC_MPLY,	       KC_LSFT,   TG(_CC),                              KC_WH_D,  KC_WH_U
    ),
};

void matrix_init_user(void) {
  // Layer 1
  setPinOutput(B1);
  writePinLow(B1);
  // Layer 2
  setPinOutput(B2);
  writePinLow(B2);
  // Caps Lock ON
  setPinOutput(B3);
  writePinLow(B3);
}

void matrix_scan_user(void) {

}

// B1 is the top light, and B3 is the bottom light
void led_set_user(uint8_t usb_led) {
  //if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {  
  //  writePinHigh(B2);
  //} else {
  //  writePinLow(B2);
  //}
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {  // turns the bottom white LED on for caps lock
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }
/*
  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {   
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }*/

}

// turns the top white LED on for layer 1  and the middle LED on for layer 2
uint32_t layer_state_set_user(uint32_t state)
{
    switch(biton32(state)) {
    case _AA:
        writePinLow(B1);
        writePinLow(B2);
        break;
    case _BB:
        writePinHigh(B1);
        break;
    case _CC:
        writePinHigh(B2);
        break;
  }
  return state;
}


//void matrix_scan_user(void) { // if you have RGB LED's (2812) you can use this to have the color indicate the layer
//
//}
//
//void matrix_init_user(void) {
//  rgblight_enable();
//  rgblight_setrgb(0x00,  0x00,  0x00);
//};
//
//uint32_t layer_state_set_user(uint32_t state) {
//    switch (biton32(state)) {
//    case _AA:
//        rgblight_setrgb (0x7A, 0x00, 0xFF);// purple
//        break;
//    case _BB:
//        rgblight_setrgb (0x00, 0x00, 0xFF); // blue
//        break;
//    case _CC:
//        rgblight_setrgb (0xFF, 0xD9, 0x00); // gold
//        break;
//    }
//  return state;
//}




/*  Prime_E Spacing       4 spaces = 1u
    ┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┬────┐
    │ 1  │ 1  │ 1  │ 1  │ 1  │ 1  │    │ 1  │ 1  │ 1  │ 1  │ 1  │ 1  │ 1  │
    ├─────┬────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┬───────┤
    │1.25 │ 1  │ 1  │ 1  │ 1  │ 1  │     │ 1  │ 1  │ 1  │ 1  │ 1  │ 1.75  │
    ├────────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┤
    │  1.75  │ 1  │ 1  │ 1  │ 1  │ 1  │ 1  │ 1  │ 1  │ 1  │ 1  │ 1  │1.25 │
    ├─────┬─────┬──────┬─────┬────────┬──────────┬─────┬──────┬─────┬─────┤
    │1.25 │1.25 │      │1.25 │   2    │   2.25   │1.25 │      │1.25 │1.25 │
    └─────┴─────┘      └─────┴────────┴──────────┴─────┘      └─────┴─────┘
*/
/*  Prime_E Blank
    ┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┬────┐
    │    │    │    │    │    │    │    │    │    │    │    │    │    │    │
    ├─────┬────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┬───────┤
    │     │    │    │    │    │    │     │    │    │    │    │    │       │
    ├────────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┤
    │        │    │    │    │    │    │    │    │    │    │    │    │     │
    ├─────┬─────┬──────┬─────┬────────┬──────────┬─────┬──────┬─────┬─────┤
    │     │     │      │     │        │          │     │      │     │     │
    └─────┴─────┘      └─────┴────────┴──────────┴─────┘      └─────┴─────┘
*/
