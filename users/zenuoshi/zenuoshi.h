#ifndef USERSPACE
#    define USERSPACE
#endif

#pragma once
#include "quantum.h"
#include "version.h"
#include "process_records.h"

#define BASE_LAYER 0

// #define _______ KC_TRNS
#define KC_____ _______
#define XXXX KC_NO
#define KC_XXXX XXXX
// #define KC_RBT QK_RBT

// #define KC_DVORAK DF(DVORAK)
// #define KC_QWERTY DF(QWERTY)
// #define KC_LOWER MO(LOWER)
// #define KC_LEFT_FN MO(LEFT_FN)
// #define KC_RAISE MO(RAISE)
// #define KC_RIGHT_FN MO(RIGHT_FN)
// #define KC_KEYPAD MO(KEYPAD)

// #define KC_BS_LOWER LT(_LOWER, KC_BSPC)
// #define KC_SPC_RAISE LT(_RAISE, KC_SPACE)
// #define KC_SPC_FN LT(_GAME_FN, KC_SPC)

#define KC_LSFTCTL (QK_LCTL | QK_LSFT)
#define KC_RSFTCTL (QK_RCTL | QK_RSFT)
#define KC_LALTCTL (QK_LALT | QK_LCTL)
#define KC_RALTCTL (QK_RALT | QK_RCTL)
#define KC_LSC KC_LSFTCTL
#define KC_RSC KC_RSFTCTL
#define KC_LAC KC_LALTCTL
#define KC_RAC KC_RALTCTL
#define KC_LMEH KC_MEH
#define KC_RMEH (QK_RCTL | QK_RSFT | QK_RALT)
#define KC_LHYPR KC_HYPR
#define KC_RHYPR (QK_RCTL | QK_RSFT | QK_RALT | QK_RGUI)
#define CTL(kc) (QK_RCTL | (kc))
#define KC_CTL(kc) CTL(KC_##kc)

#define KC_MS_BTN1 MS_BTN1
#define KC_MS_BTN2 MS_BTN2
#define KC_MS_WHLU MS_WHLU
#define KC_MS_WHLD MS_WHLD
#define KC_MS_UP MS_UP
#define KC_MS_DOWN MS_DOWN
#define KC_MS_LEFT MS_LEFT
#define KC_MS_RGHT MS_RGHT

#define KC_MO(layer) MO(layer)
#define KC_RESET QK_REBOOT
#define KC_BOOT QK_BOOT

#undef IS_COMMAND
#define IS_COMMAND() (keyboard_report->mods == (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT)))

#define ___KC_NUMBER_LEFT___ KC_1, KC_2, KC_3, KC_4, KC_5
#define ___KC_NUMBER_RIGHT___ KC_6, KC_7, KC_8, KC_9, KC_0

#define ___KC_DVORAK_L1___ KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y
#define ___KC_DVORAK_L2___ KC_A, KC_O, KC_E, KC_U, KC_I
#define ___KC_DVORAK_L3___ KC_SCLN, KC_Q, KC_J, KC_K, KC_X
#define ___KC_DVORAK_R1___ KC_F, KC_G, KC_C, KC_R, KC_L
#define ___KC_DVORAK_R2___ KC_D, KC_H, KC_T, KC_N, KC_S
#define ___KC_DVORAK_R3___ KC_B, KC_M, KC_W, KC_V, KC_Z
#define ___KC_QWERTY_L1___ KC_Q, KC_W, KC_E, KC_R, KC_T
#define ___KC_QWERTY_L2___ KC_A, KC_S, KC_D, KC_F, KC_G
#define ___KC_QWERTY_L3___ KC_Z, KC_X, KC_C, KC_V, KC_B
#define ___KC_QWERTY_R1___ KC_Y, KC_U, KC_I, KC_O, KC_P
#define ___KC_QWERTY_R2___ KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define ___KC_QWERTY_R3___ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 5
#undef MOUSEKEY_WHEEL_MAX
#define MOUSEKEY_WHEEL_MAX 1
#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 1
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 126

typedef struct {
    uint8_t  mod;
    uint16_t key;
    bool     pressed;
} mycombo_t;

enum MY_COMBO {
    SHIFT,
    CONTROL,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record);

void press_left_combo_key(uint8_t index);
void press_right_combo_key(uint8_t);
void release_left_combo_key(uint8_t);
void release_right_combo_key(uint8_t);

void action_left_combo_key(bool pressed, uint8_t index);
void action_right_combo_key(bool, uint8_t);

void lazy_action_left_combo_key(bool pressed, uint8_t index);
void lazy_action_right_combo_key(bool, uint8_t);

void tap_random_number_roman(void);
void tap_random_number(void);
void tap_random_roman(void);

void insert_line(void);
