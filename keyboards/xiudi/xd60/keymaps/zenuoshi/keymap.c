#include QMK_KEYBOARD_H

#include "layout_kc_60_ansi.h"
#include "zenuoshi.h"
// #include "wait.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;
bool                     default_layer_led_is_on;
#endif

enum LAYERS {
    _DVORAK,
    _QWERTY,
    _GAMING,
    _FN,
    // _STEP,
    // _CUSTOM,
};

enum keyboard_custom_keycodes {
    PLACEHOLDER = NEW_SAFE_RANGE,
    KC_EECONFIG_INIT,
    KC_RGB_DF_LAYER_TOGGLE,
};

#define LC_T(kc) LCTL_T(kc)
#define KC_LC_T(kc) LC_T(KC_##kc)
#define RC_T(kc) RCTL_T(kc)
#define KC_RC_T(kc) RC_T(KC_##kc)
#define KC_RGB_TOG KC_RGB_DF_LAYER_TOGGLE

#define KC_DV DF(_DVORAK)
#define KC_QW DF(_QWERTY)
#define KC_GM DF(_GAMING)

#define KC_SPACE_FN LT(_FN, KC_SPACE)
#define KC_STEP MO(_STEP)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // 0: Base Layer
  [_DVORAK] = LAYOUT_KC_60_ansi(
    ESC,   1,    2,    3,   4,   5,   6,   7,   8,    9,    0,  MINS,  EQL,   BSPC,
    TAB,    QUOT, COMM, DOT, P,   Y,   F,   G,   C,    R,    L,  LBRC,  RBRC,  BSLS,
    LCTL,    A,    O,    E,   U,   I,   D,   H,   T,    N,    S,  SLSH,         ENT,
    LSFT_F13, SCLN, Q,    J,   K,   X,   B,   M,   W,    V,    Z,            RSFT_F14,
    CAPS,  LGUI,  LALT,              SPACE_FN,                   RALT, RGUI, APP, RCTL
  ),

  [_QWERTY] = LAYOUT_KC_60_ansi(
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    ____, ____, ____,
    ____,   A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,       ____,
    ____,    Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,             ____,
    ____,  ____,  ____,                ____,                        ____, ____, ____, ____
    ),

  [_GAMING] = LAYOUT_KC_60_ansi(
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____,  Q,    W,    UP,    R,    T,    Y,    U,    I,    O,    P,    ____, ____, ____,
    ____,   A,    LEFT, DOWN,  RIGHT, G,    H,    J,    K,    L,    SCLN, QUOT,       ____,
    ____,    Z,    X,    C,     V,     B,    N,    M,    COMM, DOT,  SLSH,             ____,
    ____,  ____,  ____,                ____,                        ____, ____, ____, ____
    ),

  [_FN] = LAYOUT_KC_60_ansi(
    GRV,  F1,   F2,    F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  DEL,
    INS,   XXXX, XXXX,  XXXX, XXXX, XXXX, XXXX, HOME, UP, END, PGUP, XXXX, XXXX, RGB_TOG,
    ____,   LGUI, LALT,  LCTL, LSFT, LSC, XXXX, LEFT, DOWN, RGHT, PGDN, XXXX,       ____,
    ____,    MUTE, VOLD,  VOLU, PSCR, SCRL, PAUS, DV, QW, GM, XXXX,            ____,
    ____, ____, ____,                     ____,                   ____, ____, BOOT,   ____
  ),

//     [_STEP] = LAYOUT_KC_60_ansi(
//     XXXX,  XXXX,  XXXX, XXXX, XXXX, XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
//     XXXX,   XXXX, XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,
//     XXXX,   XXXX, XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,       XXXX,
//     XXXX,    XXXX, XXXX,  XXXX, XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,           XXXX,
//     XXXX, XXXX, XXXX,                     ____,                   XXXX, XXXX, ____,  XXXX
//   ),

//   [_CUSTOM] = LAYOUT_KC_60_ansi(
//     XXXX, DV,   GM,   PSCR, SLCK, PAUS, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, RESET,
//     XXXX,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, RGB_TOG,
//     ____,   XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,       ____,
//     ____,    MUTE,  VOLD,  VOLU,  XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX,          ____,
//     ____, ____, ____,                     ____,                  ____, ____, ____,    ____
//   )
};
// clang-format on

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_EECONFIG_INIT:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                eeconfig_init();
#endif
            }
            return false;
            break;

        case KC_RGB_DF_LAYER_TOGGLE:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                default_layer_led_is_on = !default_layer_led_is_on;
#endif
            }
            return false;
            break;
    }
    return true;
}

#ifdef RGBLIGHT_ENABLE
void default_layer_led(void) {
    if (default_layer_led_is_on) {
        uint8_t default_layer = biton32(default_layer_state);

        switch (default_layer) {
            case _DVORAK:
                rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
                break;

            case _QWERTY:
                rgblight_sethsv_noeeprom_green();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
                break;

            case _GAMING:
                rgblight_sethsv_noeeprom_yellow();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
                break;

            default:
                rgblight_sethsv_noeeprom_orange();
                rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
                break;
        }
    } else {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv_noeeprom(0x0000, 0x00, 0x00);
    }
}
#endif

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    default_layer_led_is_on = true;
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    uint32_t active_layer = biton32(state);

    switch (active_layer) {
        case _FN:
            rgblight_sethsv_noeeprom_red();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 2);
            break;

        default:
            default_layer_led();
            break;
    }
#endif

    return state;
}
