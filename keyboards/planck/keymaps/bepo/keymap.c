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


/* Pour programmer le machin :
 * - compiler
 *  $ make planck-rev4-bepo
 * - charger le nouveau code:
 *  # make planck-rev4-bepo-dfu
 * - faire un reset du clavier pour que le programmeur trouve le bootloader (cf.
 *   RESET dans le layer ADJUST).
 *

Pour obtenir les caractères '<' et '>' :
il faut _d'abord_ faire AltGr avant d'aller chercher '«' dans la layer RAISE.
 */

#include "planck.h"
#include "keymap_bepo.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _BEPO,
  _FN_LAYER,
  _LOWER,
  _RAISE,
  _NUMERIC,
  _ADJUST
};

enum planck_keycodes {
  BEPO = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMERIC,
  FN_KEY,
};

#define LT_TAB  LT(_FN_LAYER, KC_TAB)
#define LT_ESC  LT(_NUMERIC,  KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#if 0 /* JSON data for the keyboard layout editor! http://www.keyboard-layout-editor.com */
[

  [{a:7},"Esc / Num","B","É","P","O","È","^ / !","V","D","L","J","Z",
      { "x": 0.25, "f": 4, "w": 2, "d": true }, "BÉPO layer"
  ],
  ["Tab / Fn" , "A"   , "U"   , "I"   , "E"     , "     , / ;" , "C"     , "T"    , "S"    , "R"     , "N"             , "M"]         ,
  ["Shift"    , "À"   , "Y"   , "X"   , ". / :" , "K"   , "K"  , "M"     , "      , "      , "."     , "/"             , "Shift / W"] ,
  ["Ctrl"     , "App" , "Win" , "Alt" , "Lower" , {w:2} , ""   , "Raise" , "Bksp" , "RAlt" , "Shift" , "Ctrl / Enter"] ,

  [{y:0.5},"$/#","","","","","","","PgUp","↑","PgDn","PtScrn","DEL",
      { "x": 0.25, "f": 4, "w": 2, "d": true }, "FN layer"
  ],
  ["FN" , "Ctrl-A" , "Ctrl-T" , "Ctrl-L" , "Ctrl-S" , ""       , "Home" , "←"     , "↓" , "→" , "Ins" , "Del"] ,
  [""   , "Ctrl-W" , "Ctrl-X" , "Ctrl-C" , "Ctrl-V" , "Ctrl-K" , "End"  , ""      , ""  , ""  , ""    , ""]    ,
  [""   , ""       , ""       , ""       , "Lower"  , {w:2}    , ""     , "Raise" , ""  , ""  , ""    , ""]    ,

  [{y:0.5},"#","1","2","3","4","5","6","7","8","9","0","Bksp",
      { "x": 0.25, "f": 4, "w": 2, "d": true }, "lower layer"
  ],
  ["Alt tab","F1","F2","F3","F4","F5","F6","F7","F8","F9","F10","Ç"],
  ["","F11","F12","","","","","","","","",""],
  ["","","","","Lower",{w:2},"","Raise","Next","Vol-","Vol+","Play"],

  [{y:0.5},"$/#","guill","«","»","(",")","@","+","-","/","*","Bksp",
      { "x": 0.25, "f": 4, "w": 2, "d": true }, "raise layer"
  ],
  ["" , ""     , ""     , "trema",  ""      , ""    , "Home" , "PgUp"  , "↑" , "PgDn" , "=" , "%"],
  ["" , "mute" , "Vol-" , "Vol+" , ""      , ""    , "End"  , "←"     , "↓" , "→"    , ""  , ""] ,
  ["" , ""     , ""     , ""     , "Lower" , {w:2} , ""     , "Raise" , "←" , "↓"    , "→" , ""] ,


  [{y:0.5},"","","","","","","","7","8","9","/","Bksp",
      { "x": 0.25, "f": 4, "w": 2, "d": true }, "numeric layer"
  ],
  ["" , ""     , ""     , ""  , ""     , ""    , "" , "4" , "5" , "6" , "*" , "="]      ,
  ["" , "Home" , "PgUp" , "↑" , "PgDn" , ""    , "" , "1" , "2" , "3" , "+" , "Tab/Fn"] ,
  ["" , "End"  , "←"    , "↓" , "→"    , {w:2} , "" , "0" , "." , "   , "   , "-"       , "Enter"] ,

  [{y:0.5},"","Reset","Debug","","","","","","","","","",
      { "x": 0.25, "f": 4, "w": 2, "d": true }, "adjust layer"
  ],
  ["","BÉPO","NUMERC","Audon","Audoff","","","","","","",""],
  ["","Voice-","Voice+","Muson","Musoff","","","","","","",""],
  ["","","","","",{w:2},"","","","","",""]

]

#endif

[_BEPO] = {
  {LT_ESC , BP_B   , BP_ECUT, BP_P   , BP_O  , BP_E_GRAVE, BP_DCRC, BP_V , BP_D   , BP_L   , BP_J   , BP_Z},
  {LT_TAB , BP_A   , BP_U   , BP_I   , BP_E  , BP_COMMA  , BP_C   , BP_T , BP_S   , BP_R   , BP_N   , BP_M},
  {KC_LSFT, BP_AGRV, BP_Y   , BP_X   , BP_DOT, BP_K      , BP_APOS, BP_Q , BP_G   , BP_H   , BP_F   , BP_W},
  {KC_LCTL, KC_APP , KC_LGUI, KC_LALT, LOWER , KC_SPC    , KC_SPC , RAISE, KC_BSPC, KC_RALT, KC_RSFT, RCTL_T(KC_ENT)}

  /* [Note:AG_SWAP]
   * Bootmagic options allow for example to swap Alt and Gui keys.  quite
   * disturbing!
   */
},

/* FN layer,  inspired by the Pok3r fn keys */
[_FN_LAYER] = {
  {BP_DLR , _______   , _______   , _______   , _______   , _______   , _______, KC_PGUP, KC_UP  , KC_PGDN, KC_PSCR , KC_DEL },
  {_______, LCTL(BP_A), LCTL(BP_T), LCTL(BP_L), LCTL(BP_S), _______   , KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS  , KC_DEL},
  {_______, LCTL(BP_W), LCTL(BP_X), LCTL(BP_C), LCTL(BP_V), LCTL(BP_K), KC_END , _______, _______, _______, _______ , _______},
  {_______, _______   , _______   , _______   , _______   , _______   , _______, _______, _______, _______, _______, _______}
},

[_LOWER] = {
  {KC_TILD,      BP_1   , BP_2   , BP_3   , BP_4   , BP_5   , BP_6   , BP_7   , BP_8   , BP_9   , BP_0   , KC_BSPC},
  {LALT(LT_TAB), KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , BP_CCED},
  {_______,      KC_F11 , KC_F12 , _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______,      _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

[_RAISE] = {
  {BP_DLR , BP_DQOT, BP_LGIL, BP_RGIL,       BP_LPRN, BP_RPRN, BP_AT  , BP_PLUS, BP_MINUS, BP_SLSH, BP_ASTR, KC_BSPC},
  {_______, _______, _______, BP_DEAD_TREMA, _______, _______, KC_HOME, KC_PGUP, KC_UP   , KC_PGDN, BP_EQL , BP_PERC},
  {_______, KC_MUTE, KC_VOLD, KC_VOLU,       _______, _______, KC_END , KC_LEFT, KC_DOWN , KC_RGHT, _______, _______},
  {_______, _______, _______, _______,       _______, _______, _______, _______, _______ , _______, _______, _______}
},

[_NUMERIC] = {
  {_______, _______, _______, _______, _______, _______, _______, BP_7   , BP_8   , BP_9   , BP_SLSH, KC_BSPC},
  {_______, KC_HOME, KC_PGUP, KC_UP  , KC_PGDN, _______, _______, BP_4   , BP_5   , BP_6   , BP_ASTR, KC_EQL },
  {_______, KC_END , KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______, BP_1   , BP_2   , BP_3   , BP_PLUS, LT_TAB },
  {_______, _______, _______, RAISE  , LOWER  , KC_SPC , KC_SPC , BP_0   , BP_DOT , BP_COMM, BP_MINS, KC_ENT }
},

[_ADJUST] = {
  {_______, _______, RESET  , DEBUG  , _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, BEPO   , NUMERIC, MU_MOD , AU_ON  , AU_OFF , _______, _______, _______, _______, _______, _______},
  {_______, MUV_DE , MUV_IN , MU_ON  , MU_OFF , _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, LOWER  , KC_SPC , KC_SPC , RAISE  , _______, _______, _______, _______}
}

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
