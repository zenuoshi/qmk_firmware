#include "zenuoshi.h"

mycombo_t combos[][2] = {
    [SHIFT]   = {{MOD_BIT(KC_LSFT), KC_F13}, {MOD_BIT(KC_RSFT), KC_F14}},
    [CONTROL] = {{MOD_BIT(KC_LCTL), KC_F15}, {MOD_BIT(KC_RCTL), KC_F16}},
};

#define CURRENT(key_bit) (key_bit >> 1)
#define OPPOSITE(key_bit) (CURRENT(key_bit) ^ 0b01)

#define LEFT_SIDE (1u << 0)
#define RIGHT_SIDE (1u << 1)

static void        __press_combo_key(uint8_t, uint8_t);
static void        __release_combo_key(uint8_t, uint8_t);
static void        __lazy_action_combo_key(bool, uint8_t, uint8_t);
inline static bool is_mods_on(uint8_t);
inline static bool is_mods_off(uint8_t);

inline void press_left_combo_key(uint8_t index) {
    __press_combo_key(index, LEFT_SIDE);
}
inline void release_left_combo_key(uint8_t index) {
    __release_combo_key(index, LEFT_SIDE);
}
inline void press_right_combo_key(uint8_t index) {
    __press_combo_key(index, RIGHT_SIDE);
}
inline void release_right_combo_key(uint8_t index) {
    __release_combo_key(index, RIGHT_SIDE);
}
inline void action_left_combo_key(bool pressed, uint8_t index) {
    if (pressed) {
        press_left_combo_key(index);
    } else {
        release_left_combo_key(index);
    }
}
inline void action_right_combo_key(bool pressed, uint8_t index) {
    if (pressed) {
        press_right_combo_key(index);
    } else {
        release_right_combo_key(index);
    }
}

static void __press_combo_key(uint8_t index, uint8_t key_bit) {
    mycombo_t* activated_key_state = &(combos[index])[CURRENT(key_bit)];
#ifdef ENABLE_MY_COMBO
    mycombo_t* opposite_key_state = &(combos[index])[OPPOSITE(key_bit)];

    activated_key_state->pressed = true;

    if (opposite_key_state->pressed) {
        add_key(activated_key_state->key);
    } else {
        add_mods(activated_key_state->mod);
    }
#else
    add_mods(activated_key_state->mod);
#endif

    send_keyboard_report();
}

static void __release_combo_key(uint8_t index, uint8_t key_bit) {
    mycombo_t* activated_key_state = &(combos[index])[CURRENT(key_bit)];
#ifdef ENABLE_MY_COMBO
    mycombo_t* opposite_key_state = &(combos[index])[OPPOSITE(key_bit)];

    activated_key_state->pressed = false;

    if (is_mods_on(activated_key_state->mod)) {
        del_mods(activated_key_state->mod);
    } else {
        del_key(activated_key_state->key);
    }

    if (opposite_key_state->pressed && is_mods_off(opposite_key_state->mod)) {
        del_key(opposite_key_state->key);
        add_mods(opposite_key_state->mod);
    }

#else
    del_mods(activated_key_state->mod);
#endif

    send_keyboard_report();
}

inline void lazy_action_left_combo_key(bool pressed, uint8_t index) {
    __lazy_action_combo_key(pressed, index, LEFT_SIDE);
}

inline void lazy_action_right_combo_key(bool pressed, uint8_t index) {
    __lazy_action_combo_key(pressed, index, RIGHT_SIDE);
}

static void __lazy_action_combo_key(bool pressed, uint8_t index, uint8_t key_bit) {
    mycombo_t* activated_key_state = &(combos[index])[CURRENT(key_bit)];
    mycombo_t* opposite_key_state  = &(combos[index])[OPPOSITE(key_bit)];

    if (pressed) {
        activated_key_state->pressed = true;
        add_mods(activated_key_state->mod);
    } else { // when released
        activated_key_state->pressed = false;
        del_mods(activated_key_state->mod);
        if (opposite_key_state->pressed) {
            register_code(opposite_key_state->key);
        }
    }

    send_keyboard_report();
}

inline static bool is_mods_on(uint8_t mods) {
    return get_mods() & mods;
}
inline static bool is_mods_off(uint8_t mods) {
    return !is_mods_on(mods);
}

void tap_random_number_roman(void) {
#if defined(__AVR_ATmega32U4__)
    uint8_t key = (TCNT0 + TCNT1 + TCNT3 + TCNT4) % 62;
#else
    uint8_t key = rand() % 62;
#endif
    switch (key) {
        case 0 ... 25:
            register_code(KC_LSFT);
            register_code(key + KC_A);
            unregister_code(key + KC_A);
            unregister_code(KC_LSFT);
            break;
        case 26 ... 51:
            register_code(key - 26 + KC_A);
            unregister_code(key - 26 + KC_A);
            break;
        case 52:
            register_code(KC_0);
            unregister_code(KC_0);
            break;
        case 53 ... 61:
            register_code(key - 53 + KC_1);
            unregister_code(key - 53 + KC_1);
            break;
    }
}

void tap_random_roman(void) {
#if defined(__AVR_ATmega32U4__)
    uint8_t key = (TCNT0 + TCNT1 + TCNT3 + TCNT4) % 52;
#else
    uint8_t key = rand() % 52;
#endif
    switch (key) {
        case 0 ... 25:
            register_code(KC_LSFT);
            register_code(key + KC_A);
            unregister_code(key + KC_A);
            unregister_code(KC_LSFT);
            break;
        case 26 ... 51:
            register_code(key - 26 + KC_A);
            unregister_code(key - 26 + KC_A);
            break;
    }
}

void tap_random_number(void) {
#if defined(__AVR_ATmega32U4__)
    uint8_t key = (TCNT0 + TCNT1 + TCNT3 + TCNT4) % 10;
#else
    uint8_t key = rand() % 10;
#endif
    switch (key) {
        case 0:
            register_code(KC_0);
            unregister_code(KC_0);
            break;
        case 1 ... 9:
            register_code(key - 1 + KC_1);
            unregister_code(key - 1 + KC_1);
            break;
    }
}

void insert_line(void) {
    uint8_t mods_state = get_mods();
    clear_mods();

    if (mods_state & MOD_LCTL) {
        if (mods_state & MOD_LSFT) {
            SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_ENTER) SS_TAP(X_UP));
        } else {
            SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
        }
    }
}
