#include QMK_KEYBOARD_H
#include "features/achordion.h"

/**
 * Layer
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_layers.md
 */
enum layers
{
    DEFT, // Default
    NAVI, // Navigation & Mouse key
    SYMB, // Symbol
    NUMB, // Number
    FUNC, // Function
    GAME, // Game
};

/**
 * Macros
 * https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md
 */
enum keycodes
{
    PPY_SCR, // Ploopy nano scroll wheel
    PPY_DPI, // Ploopy nano change DPI
    PPY_RST, // Ploopy nano RESET
};

/**
 * Alias
 */
#define LTHUM_1 LT(NAVI, KC_TAB)  // Left Thumb 1
#define LTHUM_2 SFT_T(KC_SPC)     // Left Thumb 2
#define LTHUM_3 CTL_T(KC_ESC)     // Left Thumb 3
#define RTHUM_3 LT(FUNC, KC_DEL)  // Right Thumb 3
#define RTHUM_2 LT(SYMB, KC_ENT)  // Right Thumb 2
#define RTHUM_1 LT(NUMB, KC_BSPC) // Right Thumb 1
#define LHOME_1 LGUI_T(KC_A)      // Left Home Row 1
#define LHOME_2 LALT_T(KC_S)      // Left Home Row 2
#define LHOME_3 LCTL_T(KC_D)      // Left Home Row 3
#define LHOME_4 LSFT_T(KC_F)      // Left Home Row 4
#define RHOME_4 LSFT_T(KC_J)      // Right Home Row 4
#define RHOME_3 LCTL_T(KC_K)      // Right Home Row 3
#define RHOME_2 LALT_T(KC_L)      // Right Home Row 2
#define RHOME_1 LGUI_T(KC_QUOT)   // Right Home Row 1
#define TAB_CLS C(KC_W)           // Close Tab
#define TAB_RST C(S(KC_T))        // Restore Tab
#define WN_PREV C(G(KC_LEFT))     // Window Space Prev
#define WN_NEXT C(G(KC_RGHT))     // Window Space Nexts

/**
 * Combo keys
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
 */
const uint16_t PROGMEM zxcv_combo[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM comm_dot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(zxcv_combo, TG(GAME)),
    COMBO(comm_dot_combo, KC_LNG1),
    COMBO(xc_combo, KC_CAPS),
};

/**
 * Keymaps
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [DEFT] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LHOME_1, LHOME_2, LHOME_3, LHOME_4, KC_G,    KC_H,    RHOME_4, RHOME_3, RHOME_2, RHOME_1,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN,
                          LTHUM_1, LTHUM_2, LTHUM_3, RTHUM_3, RTHUM_2, RTHUM_1
    ),

    [NAVI] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______, KC_PGUP, KC_MUTE, KC_VOLD, KC_VOLU, KC_TAB,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        _______, _______, _______, _______, _______, _______, KC_HOME, WN_PREV, WN_NEXT, KC_END,
                          _______, _______, QK_BOOT, _______, _______, _______
    ),

    [SYMB] = LAYOUT_split_3x5_3(
        KC_LABK, KC_LCBR, KC_LPRN, KC_LBRC, KC_TILD, KC_CIRC, KC_RBRC, KC_RPRN, KC_RCBR, KC_RABK,
        KC_GRV,  KC_MINS, KC_PLUS, KC_EQL,  KC_DLR,  KC_HASH, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_BSLS, KC_SLSH, KC_ASTR, KC_UNDS, KC_PERC, KC_AT,   KC_PIPE, KC_AMPR, KC_QUES, KC_EXLM,
                          _______, _______, _______, _______, _______, _______
    ),

    [NUMB] = LAYOUT_split_3x5_3(
        _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______,
        _______, KC_4,    KC_5,    KC_6,    _______, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______,
                          _______, KC_0,    _______, QK_BOOT, _______, _______
    ),

    [FUNC] = LAYOUT_split_3x5_3(
        KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, _______, _______, _______, _______, _______,
        KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______
    ),

    [GAME] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_A,    KC_S,    KC_D,    KC_F,    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, KC_SPC,  _______, _______, _______, _______
    ),
    // clang-format on
};

/**
 * Custom Quantum Functions
 * https://github.com/qmk/qmk_firmware/blob/master/docs/custom_quantum_functions.md
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    // Feature - Accordion: https://getreuer.info/posts/keyboards/achordion/index.html
    if (!process_achordion(keycode, record))
    {
        return false;
    }

    switch (keycode)
    {
    case PPY_SCR:
        if (record->event.pressed)
        {
            SEND_STRING(SS_TAP(X_NUM) SS_TAP(X_NUM));
        }
        break;
    case PPY_DPI:
        if (record->event.pressed)
        {
            SEND_STRING(SS_TAP(X_SCRL) SS_TAP(X_SCRL));
        }
        break;
    case PPY_RST:
        if (record->event.pressed)
        {
            SEND_STRING(SS_TAP(X_NUM) SS_TAP(X_NUM) SS_TAP(X_SCRL) SS_TAP(X_SCRL));
        }
        break;
    }
    return true;
}

void matrix_scan_user(void)
{
    // Feature - Accordion: https://getreuer.info/posts/keyboards/achordion/index.html
    achordion_task();
}

// Feature - Accordion: https://getreuer.info/posts/keyboards/achordion/index.html
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record)
{
    switch (tap_hold_keycode)
    {
    case LTHUM_1:
    case LTHUM_2:
    case LTHUM_3:
    case RTHUM_1:
    case RTHUM_2:
    case RTHUM_3:
        return true;
    case LHOME_1:
    case LHOME_2:
    case LHOME_3:
    case LHOME_4:
        if (other_keycode == LTHUM_1 || other_keycode == LTHUM_2 || other_keycode == LTHUM_3)
        {
            return true;
        }
        break;
    case RHOME_1:
    case RHOME_2:
    case RHOME_3:
    case RHOME_4:
        if (other_keycode == RTHUM_1 || other_keycode == RTHUM_2 || other_keycode == RTHUM_3)
        {
            return true;
        }
        break;
    }
    return achordion_opposite_hands(tap_hold_record, other_record);
}
