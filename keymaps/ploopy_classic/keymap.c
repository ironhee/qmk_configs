#include QMK_KEYBOARD_H

/**
 * Layer
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_layers.md
 */
enum layers {
    DEFT, // Default
    FUNC, // Function
};

/**
 * Combo keys
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
 */
const uint16_t PROGMEM btn1_btn3_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(btn1_btn3_combo, KC_BTN3),
};

/**
 * Keymaps
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFT] = LAYOUT(KC_BTN1, KC_BTN3, KC_BTN2, OSL(FUNC), DRAG_SCROLL),
    [FUNC] = LAYOUT(KC_BTN4, QK_BOOT, KC_BTN5, DPI_CONFIG, _______),
};
