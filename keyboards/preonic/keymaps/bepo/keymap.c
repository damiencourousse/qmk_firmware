/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "keymap_bepo.h"

enum preonic_layers {
  _BEPO,
  _FN_LAYER,
  _LOWER,
  _RAISE,
  _NUMERIC,
  _ADJUST
};

enum preonic_keycodes {
  BEPO = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMERIC,
  FN_KEY,
};

#define LT_ESC_FN  LT(_FN_LAYER, KC_ESC)
#define LT_ESC_NUM LT(_NUMERIC , KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BEPO] = LAYOUT_preonic_grid( \
  LT_ESC_NUM, KC_1 , KC_2   , KC_3   , KC_4,   KC_5      , KC_6   , KC_7 , KC_8   , KC_9   , KC_0   , KC_BSPC, \
  KC_TAB  , BP_B   , BP_ECUT, BP_P   , BP_O  , BP_E_GRAVE, BP_DCRC, BP_V , BP_D   , BP_L   , BP_J   , BP_Z,    \
  LT_ESC_FN,  BP_A , BP_U   , BP_I   , BP_E  , BP_COMMA  , BP_C   , BP_T , BP_S   , BP_R   , BP_N   , BP_M,    \
  KC_LSFT , BP_AGRV, BP_Y   , BP_X   , BP_DOT, BP_K      , BP_APOS, BP_Q , BP_G   , BP_H   , BP_F   , BP_W,    \
  KC_LCTL , KC_APP , KC_LGUI, KC_LALT, LOWER , KC_SPC    , KC_SPC , RAISE, KC_BSPC, KC_RALT, KC_RSFT, RCTL_T(KC_ENT) \
),

[_FN_LAYER] = LAYOUT_preonic_grid(
  BP_DLR       , KC_1      , KC_2      , KC_3      , KC_4      , KC_5      , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL , \
  LSFT(BP_DLR) , KC_SYSTEM_WAKE, KC_SYSTEM_SLEEP, _______   , _______   , _______   , _______, KC_PGUP, KC_UP  , KC_PGDN, KC_PSCR, _______, \
  _______      , LCTL(BP_A), LCTL(BP_T), LCTL(BP_L), LCTL(BP_S), _______   , KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS , _______, \
  _______      , LCTL(BP_W), LCTL(BP_X), LCTL(BP_C), LCTL(BP_V), LCTL(BP_K), KC_END , _______, _______, _______, _______, _______, \
  _______      , _______   , _______   , _______   , LOWER     , KC_SPC    , KC_SPC , RAISE  , _______, _______, _______, _______ \
),

[_LOWER] = LAYOUT_preonic_grid( \
  BP_DLR      , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , BP_CCED, \
  LSFT(BP_DLR), KC_F11 , KC_F12 , _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  LALT(KC_TAB), KC_PGDN, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______     , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, _______, _______, _______, _______, _______, \
  _______     , _______, _______, _______, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_preonic_grid( \
  BP_DLR , BP_DQOT, BP_LGIL, BP_RGIL,      BP_LPRN, BP_RPRN, BP_AT  , BP_PLUS, BP_MINUS, BP_SLSH, BP_ASTR, KC_BSPC, \
  LSFT(BP_DLR),BP_DQOT, BP_LGIL, BP_RGIL,  BP_LPRN, BP_RPRN, BP_AT  , BP_PLUS, BP_MINUS, BP_SLSH, BP_ASTR, KC_DEL , \
  _______, _______, _______, BP_DEAD_TREMA,_______, _______, _______, KC_HOME, KC_PGUP , KC_PGDN, BP_EQL , BP_PERC, \
  _______, KC_MUTE, KC_VOLD, KC_VOLU,      _______, _______, _______, KC_LEFT, KC_DOWN , KC_UP  , KC_RGHT, KC_END , \
  _______, _______, _______, _______,      _______, _______, _______, _______, _______ , _______, _______, _______
),

[_NUMERIC] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, BP_7   , BP_8   , BP_9   , BP_SLSH, _______, \
  _______, KC_HOME, KC_PGUP, KC_UP  , KC_PGDN, _______, _______, BP_4   , BP_5   , BP_6   , BP_ASTR, _______, \
  _______, KC_END , KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, BP_1   , BP_2   , BP_3   , BP_PLUS, KC_TAB , \
  _______, _______, _______, RAISE  , _______, _______, _______, BP_0   , BP_DOT , BP_COMMA,KC_MINUS, KC_ENT
),

[_ADJUST] =  LAYOUT_preonic_grid( \
  _______, _______, RESET  , DEBUG  , _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, BEPO   , NUMERIC, MU_MOD , AU_ON  , AU_OFF , _______, _______, _______, _______, _______, _______, \
  _______, MUV_DE , MUV_IN , MU_ON  , MU_OFF , _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, LOWER  , KC_SPC , KC_SPC , RAISE  , _______, _______, _______, _______
),

};


#ifdef AUDIO_ENABLE

#define SOUND_BEPO \
    E__NOTE(_GS6 ),  \
    E__NOTE(_A6  ),  \
    S__NOTE(_REST),  \
    ED_NOTE(_E7  ),  \
    S__NOTE(_REST),  \
    ED_NOTE(_A7  ),

#define SOUND_BEPO_GOODBYE \
    E__NOTE(_A6  ),  \
    E__NOTE(_GS6 ),  \
    S__NOTE(_REST),  \
    ED_NOTE(_A6  ),  \
    S__NOTE(_REST),  \
    ED_NOTE(_E6  ),

float bepo_song[][2]     = SONG(SOUND_BEPO);
float bepo_gb_song[][2]  = SONG(SOUND_BEPO_GOODBYE);

#define SOUND_NUMERIC \
    E__NOTE(_FS7  ), \
    S__NOTE(_REST),  \
    E__NOTE(_DS7  ), \
    S__NOTE(_REST),  \
    E__NOTE(_E7  ),  \
    S__NOTE(_REST),  \
    E__NOTE(_A6  ),

float bepo_numeric[][2]  = SONG(SOUND_NUMERIC);

#endif  /* AUDIO_ENABLE */

/*
 https://docs.qmk.fm/#/custom_quantum_functions?id=example-process_record_user-implementation

 When you want to override the behavior of an existing key, or define
 the behavior for a new key, you should use the process_record_kb()
 and process_record_user() functions. These are called by QMK during
 key processing before the actual key event is handled. If these
 functions return true QMK will process the keycodes as usual. That
 can be handy for extending the functionality of a key rather than
 replacing it. If these functions return false QMK will skip the
 normal key handling, and it will be up to you to send any key up or
 down events that are required.

 These function are called every time a key is pressed or released.
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BEPO:
      if (record->event.pressed) {
        print("mode just switched to BÉPO\n");
        set_single_persistent_default_layer(_BEPO);
#if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
        PLAY_SONG(bepo_song);
#endif
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case NUMERIC:
      if (record->event.pressed) {
        print("mode just switched to NUMERIC\n");
        set_single_persistent_default_layer(_NUMERIC);
#if defined(AUDIO_ENABLE) && defined(DEFAULT_LAYER_SONGS)
        PLAY_SONG(bepo_numeric);
#endif
      }
      return false;
      break;
  }
  return true;
}
