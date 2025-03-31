#include "process_records.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_RANDOM:
            if (record->event.pressed) {
                tap_random_number_roman();
            }
            return false;

        case KC_VERSION:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP "@" QMK_VERSION);
            }
            return false;

        case KC_LSFT_F13:
            if (record->event.pressed) {
                press_left_combo_key(SHIFT);
            } else {
                release_left_combo_key(SHIFT);
            }
            return false;

        case KC_RSFT_F14:
            if (record->event.pressed) {
                press_right_combo_key(SHIFT);
            } else {
                release_right_combo_key(SHIFT);
            }
            return false;

        case KC_LNBRK:
            if (record->event.pressed) {
                insert_line();
            }
            return false;
    }

    return true;
}
