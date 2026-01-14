#include QMK_KEYBOARD_H

#include "zenuoshi.h"
#include "layout_kc_ergodox76.h"

enum LAYER {
    _DVORAK,
    _QWERTY,
    _GAME_DV,
    _GAME_QW,
    _LEFT_FN,
    _RIGHT_FN,
    _GAME_FN,
    _KEYPAD,
    _SYSTEM,
};

#define KC_DVORAK DF(_DVORAK)
#define KC_QWERTY DF(_QWERTY)
#define KC_LEFT_FN MO(_LEFT_FN)
#define KC_RIGHT_FN MO(_RIGHT_FN)
#define KC_KEYPAD MO(_KEYPAD)
#define KC_GAME_DV DF(_GAME_DV)
#define KC_GAME_QW DF(_GAME_QW)
#define KC_GAME_FN MO(_GAME_FN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_KC_ergodox76(
    // left hand -->
    LBRC,   1,       2,       3,      4,      5,     GRV,
    SLSH,   QUOT,    COMM,    DOT,    P,      Y,     TAB,
    EQL,    A,       O,       E,      U,      I,
    LSFT,   SCLN,    Q,       J,      K,      X,     ESC,
    HOME,   PGUP,    PGDN,    END,    LEFT_FN,

                                            LCTL,     LALT,
                                                      LGUI,
                                    BSPC,   LSFT_F13, F13,

    // <-- right hand
    KEYPAD,  6,      7,        8,      9,      0,      RBRC,
    DEL,     F,      G,        C,      R,      L,      BSLS,
             D,      H,        T,      N,      S,      MINS,
    ENT,     B,      M,        W,      V,      Z,      RSFT,
                     RIGHT_FN, LEFT,   DOWN,   UP,     RIGHT,

    RALT,    RCTL,
    RGUI,
    F14,    RSFT_F14,    SPC
  ),

  [_QWERTY] = LAYOUT_KC_ergodox76(
    // left hand -->
    ____,   ____,   ____,   ____,   ____,   ____,  ____,
    ____,   Q,      W,      E,      R,      T,     ____,
    ____,   A,      S,      D,      F,      G,
    ____,   Z,      X,      C,      V,      B,     ____,
    ____,   ____,   ____,   ____,  ____,
                                         ____,  ____,
                                                ____,
                                  ____,  ____,  ____,
    // <-- right hand
    ____,   ____,   ____,   ____,   ____,   ____,   ____,
    ____,   Y,      U,      I,      O,      P,      ____,
            H,      J,      K,      L,      SCLN,   ____,
    ____,   N,      M,      COMM,   DOT,    QUOT,   ____,
                    ____,   ____,   ____,   ____,   ____,
    ____,   ____,
    ____,
    ____,   ____,   ____
  ),

  [_GAME_DV] = LAYOUT_KC_ergodox76(
    // left hand -->
    ____,   ____,  ____,  ____,  ____,   ____,     ____,
    ____,   ____,  ____,  ____,  ____,   ____,     ____,
    ____,   ____,  ____,  ____,  ____,   ____,
    ____,   ____,  ____,  ____,  ____,   ____,     ____,
    ____,   ____,  ____,  ____,  ____,

                                        ____,     ____,
                                                  XXXX,
                                SPC,    ____,     ____,
    // <-- right hand
    ____,   ____,   ____,   ____,   ____,   ____,   ____,
    ____,   ____,   ____,   ____,   ____,   ____,   ____,
            ____,   ____,   ____,   ____,   ____,   ____,
    ____,   ____,   ____,   ____,   ____,   ____,   ____,
                    ____,   ____,   ____,   ____,   ____,
    ____,   ____,
    XXXX,
    ____,   ____,   BSPC
  ),

  [_GAME_QW] = LAYOUT_KC_ergodox76(
    // left hand -->
    ____,   ____,   ____,   ____,   ____,   ____,  ____,
    TAB,    Q,      W,      UP,     R,      T,     H,
    ____,   A,      LEFT,   DOWN,   RIGHT,  G,
    ____,   Z,      X,      C,      V,      B,     ____,
    ____,   ____,   ____,   ____,   GAME_FN,
                                        ____,  ____,
                                               XXXX,
                                  SPC,  ____,  ____,
    // <-- right hand
    ____,   ____,   ____,   ____,   ____,   ____,   ____,
    ____,   Y,      U,      I,      O,      P,      ____,
            H,      J,      K,      L,      SCLN,   ____,
    ____,   N,      M,      COMM,   DOT,    QUOT,   ____,
                    XXXX,   ____,   ____,   ____,   ____,
    ____,   ____,
    XXXX,
    ____,   ____,   BSPC
  ),

  [_LEFT_FN] = LAYOUT_KC_ergodox76(
    // left hand -->
    XXXX,   F1,     F2,     F3,         F4,       F5,     F6,
    XXXX,   CTL(W), XXXX,   CTL(PGUP), CTL(PGDN), XXXX,   XXXX,
    XXXX,   LGUI,   LALT,   LSFT,      LCTL,      XXXX,
    XXXX,   XXXX,   XXXX,   LMEH,      LHYPR,     XXXX,   XXXX,
    XXXX,   XXXX,   XXXX,   XXXX,       ____,

                                            ____,   ____,
                                                    ____,
                                    ____,   ____,   ____,

    // <-- right hand
    ____,      F6,        F7,     F8,     F9,     F10,     F11,
    RANDOM,    CTL(PGUP), HOME,   UP,     END,    PGUP,    F12,
               CTL(PGDN), LEFT,   DOWN,   RIGHT,  PGDN,    F13,
    LNBRK,     XXXX,      PGUP,   DOWN,   PGDN,   XXXX,    F14,
                          ____,   XXXX,   XXXX,   XXXX,    XXXX,

    ____,      ____,
    APP,
    ____,      ____,   ____
  ),

  [_RIGHT_FN] = LAYOUT_KC_ergodox76(
    // left hand -->
    XXXX,     F1,         F2,      F3,      F4,       F5,       XXXX,
    XXXX,     MS_WH_UP,   MS_BTN2, MS_UP,   MS_BTN1,  XXXX,     XXXX,
    XXXX,     MS_WH_DOWN, MS_LEFT, MS_DOWN, MS_RIGHT, XXXX,
    XXXX,     XXXX,       XXXX,    XXXX,    XXXX,     XXXX,     XXXX,
    ____,     XXXX,       XXXX,    XXXX,    ____,

                                                    ____,       ____,
                                                                ____,
                                          ____,     ____,       ____,

    // <-- right hand
    ____,   XXXX,   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
    XXXX,   XXXX,   XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
            XXXX,   RCTL,    RSFT,    RALT,    RGUI,    XXXX,
    XXXX,   XXXX,   RHYPR,   RMEH,    XXXX,    XXXX,    XXXX,
                    XXXX,    XXXX,    XXXX,    XXXX,    ____,

    ____,   ____,
    ____,
    ____,   ____,   ____
  ),

    [_GAME_FN] = LAYOUT_KC_ergodox76(
    // left hand -->
    XXXX,     F1,      F2,       F3,      F4,       F5,         F6,
    XXXX,     PGUP,    HOME,     E,       END,      XXXX,       XXXX,
    XXXX,     PGDN,    S,        D,       F,        XXXX,
    XXXX,     XXXX,    XXXX,     XXXX,    XXXX,     XXXX,       XXXX,
    ____,     XXXX,    XXXX,     XXXX,    ____,

                                                    ____,       ____,
                                                                ____,
                                          ____,     ____,       ____,

    // <-- right hand
    ____,   F6,     F7,     F8,      F9,      F10,     F11,
    XXXX,   XXXX,   XXXX,   XXXX,    XXXX,    XXXX,    F12,
            XXXX,   RCTL,   RSFT,    RALT,    RGUI,    XXXX,
    XXXX,   XXXX,   RHYPR,  RMEH,    XXXX,    XXXX,    XXXX,
                    XXXX,   XXXX,    XXXX,    XXXX,    ____,

    ____,   ____,
    ____,
    ____,   ____,   ____
  ),

  [_KEYPAD] = LAYOUT_KC_ergodox76(
    // left hand -->
    DVORAK,   XXXX,    XXXX,    XXXX,      XXXX,    XXXX,    XXXX,
    QWERTY,   XXXX,    XXXX,    XXXX,      XXXX,    XXXX,    XXXX,
    GAME_DV,  XXXX,    XXXX,    XXXX,      XXXX,    XXXX,
    GAME_QW,  XXXX,    XXXX,    XXXX,      XXXX,    XXXX,    XXXX,
    XXXX,   XXXX,    XXXX,    XXXX,      XXXX,

                                                  ____,   ____,
                                                          XXXX,
                                          ____,   ____,   ____,

    // <-- right hand
    ____,      CALC,    PEQL,   PSLS,    PAST,    XXXX,   DVORAK,
    XXXX,      NUM,     P7,     P8,      P9,      PMNS,   QWERTY,
               XXXX,    P4,     P5,      P6,      PPLS,   GAME_DV,
    XXXX,      XXXX,    P1,     P2,      P3,      PENT,   GAME_QW,
                        XXXX,   P0,      PDOT,    XXXX,   XXXX,

    XXXX,      XXXX,
    XXXX,
    ____,      BSPC,    P0
  ),

  [_SYSTEM] = LAYOUT_KC_ergodox76(
    // left hand -->
    XXXX,    XXXX,    XXXX,    PSCR,   SCRL,   PAUS,   XXXX,
    INS,     XXXX,    XXXX,    XXXX,   XXXX,   XXXX,   XXXX,
    CAPS,    XXXX,    XXXX,    XXXX,   XXXX,   XXXX,
    XXXX,    MUTE,    VOLD,    VOLU,   XXXX,   XXXX,   XXXX,
    XXXX,    XXXX,    XXXX,    XXXX,   XXXX,

                                               ____,   ____,
                                                       ____,
                                       ____,   ____,   ____,

    // <-- right hand
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    RESET,
    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    VERSION,
             XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    BOOT,
    XXXX,    XXXX,    XXXX,    MPRV,    MNXT,    MPLY,    XXXX,
                      XXXX,    XXXX,    XXXX,    XXXX,    XXXX,

    ____,    ____,
    ____,
    ____,    ____,    ____
  ),
};
// clang-format on

void keyboard_post_init_user(void) {
#ifdef ERGODOX_EZ_H
    ergodox_right_led_1_set(LED_BRIGHTNESS_HI / 6);
    ergodox_right_led_2_set(LED_BRIGHTNESS_HI / 2);
    ergodox_right_led_3_set(LED_BRIGHTNESS_HI / 2);

    ergodox_led_all_off();
#endif
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef ERGODOX_EZ_H
    if (state & (1UL << BASE_LAYER)) {
        ergodox_right_led_1_off();
    } else {
        ergodox_right_led_1_on();
    }
#endif

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LEFT_FN, _RIGHT_FN, _SYSTEM);

#ifdef ERGODOX_EZ_H
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t active_layer = biton32(state);
    switch (active_layer) {
        case _LEFT_FN:
        case _GAME_DV:
        case _GAME_QW:
        case _KEYPAD:
            ergodox_right_led_3_on();
            break;

        case _RIGHT_FN:
            ergodox_right_led_2_on();
            break;

        case _SYSTEM:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
    }
#endif

    return state;
}
