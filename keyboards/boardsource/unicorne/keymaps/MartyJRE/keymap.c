#include <keyboard.h>

// layers
enum {
    BASE = 0,
    LOWER = 1,
    RAISE = 2,
    TRI = 3,
    REF
};

// tap dances
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR); // Default animation
    rgb_matrix_sethsv(HSV_GOLD); // Replace HSV_RED with your desired color
}
#endif


void tap_dance_tap_hold_reset(tap_dance_state_t *state __attribute__((unused)), void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
            #ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
                ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

enum {
    TD_Q = 0,
    TD_W,
    TD_R,
    TD_T,
    TD_A,
    TD_S,
    TD_D,
    TD_F,
    TD_G,
    TD_H,
    TD_J,
    TD_K,
    TD_Z,
    TD_X,
    TD_C,
    TD_V,
    TD_B,
    TD_N,
    TD_M,
    TD_SLASH,
};

enum {
    M_REN = SAFE_RANGE,
    M_SIG,
    M_CONST,
    M_FIELD,
    M_PARAM,
    M_MET,
    M_INL,
	M_CLONE_UP,
	M_CLONE_DOWN,
	M_MEH_RIGHT,
	M_MEH_LEFT,
};

tap_dance_action_t tap_dance_actions[] = {
        [TD_Q] = ACTION_TAP_DANCE_TAP_HOLD(KC_Q, RGUI(KC_Q)),
        [TD_W] = ACTION_TAP_DANCE_TAP_HOLD(KC_W, RGUI(KC_W)),
        [TD_R] = ACTION_TAP_DANCE_TAP_HOLD(KC_R, RGUI(KC_R)),
        [TD_T] = ACTION_TAP_DANCE_TAP_HOLD(KC_T, RGUI(KC_T)),
        [TD_A] = ACTION_TAP_DANCE_TAP_HOLD(KC_A, RGUI(KC_A)),
        [TD_S] = ACTION_TAP_DANCE_TAP_HOLD(KC_S, RGUI(KC_S)),
        [TD_D] = ACTION_TAP_DANCE_TAP_HOLD(KC_D, KC_LBRC),
        [TD_F] = ACTION_TAP_DANCE_TAP_HOLD(KC_F, KC_LPRN),
        [TD_G] = ACTION_TAP_DANCE_TAP_HOLD(KC_G, KC_LCBR),
        [TD_H] = ACTION_TAP_DANCE_TAP_HOLD(KC_H, KC_RCBR),
        [TD_J] = ACTION_TAP_DANCE_TAP_HOLD(KC_J, KC_RPRN),
        [TD_K] = ACTION_TAP_DANCE_TAP_HOLD(KC_K, KC_RBRC),
        [TD_Z] = ACTION_TAP_DANCE_TAP_HOLD(KC_Z, RGUI(KC_Z)),
        [TD_X] = ACTION_TAP_DANCE_TAP_HOLD(KC_X, RGUI(KC_X)),
        [TD_C] = ACTION_TAP_DANCE_TAP_HOLD(KC_C, RGUI(KC_C)),
        [TD_V] = ACTION_TAP_DANCE_TAP_HOLD(KC_V, RGUI(KC_V)),
        [TD_B] = ACTION_TAP_DANCE_TAP_HOLD(KC_B, RGUI(KC_B)),
        [TD_N] = ACTION_TAP_DANCE_TAP_HOLD(KC_N, KC_LGUI),
        [TD_M] = ACTION_TAP_DANCE_TAP_HOLD(KC_M, RGUI(KC_M)),
        [TD_SLASH] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLASH, RGUI(KC_SLASH)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case M_REN:
            if (record->event.pressed) {
                SEND_STRING(
                        SS_DOWN(X_LCTL)
                        SS_DOWN(X_LALT)
                        SS_DOWN(X_LSFT)
                        SS_TAP(X_R)
                        SS_UP(X_LCTL)
                        SS_UP(X_LALT)
                        SS_UP(X_LSFT)
                        SS_DELAY(100)
                        SS_TAP(X_R)
                );
            }
            break;
        case M_SIG:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_LCTL)
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_LSFT)
                    SS_TAP(X_C)
                    SS_UP(X_LCTL)
                    SS_UP(X_LALT)
                    SS_UP(X_LSFT)
                    SS_DELAY(100)
                    SS_TAP(X_S)
                );
            }
            break;
        case M_CONST:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_LCTL)
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_LSFT)
                    SS_TAP(X_R)
                    SS_UP(X_LCTL)
                    SS_UP(X_LALT)
                    SS_UP(X_LSFT)
                    SS_DELAY(100)
                    SS_TAP(X_C)
                );
            }
            break;
        case M_FIELD:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_LCTL)
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_LSFT)
                    SS_TAP(X_R)
                    SS_UP(X_LCTL)
                    SS_UP(X_LALT)
                    SS_UP(X_LSFT)
                    SS_DELAY(100)
                    SS_TAP(X_F)
                );
            }
            break;
        case M_PARAM:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_LCTL)
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_LSFT)
                    SS_TAP(X_R)
                    SS_UP(X_LCTL)
                    SS_UP(X_LALT)
                    SS_UP(X_LSFT)
                    SS_DELAY(100)
                    SS_TAP(X_P)
                );
            }
            break;
        case M_MET:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_LCTL)
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_LSFT)
                    SS_TAP(X_R)
                    SS_UP(X_LCTL)
                    SS_UP(X_LALT)
                    SS_UP(X_LSFT)
                    SS_DELAY(100)
                    SS_TAP(X_M)
                );
            }
            break;
        case M_INL:
            if (record->event.pressed) {
                SEND_STRING(
                    SS_DOWN(X_LGUI)
                    SS_DOWN(X_LALT)
                    SS_TAP(X_N)
                    SS_UP(X_LGUI)
                    SS_UP(X_LALT)
                );
            }
            break;
		case M_CLONE_UP:
			if (record->event.pressed) {
				SEND_STRING(
                    SS_DOWN(X_LCTL)
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_LSFT)
					SS_TAP(X_UP)
                    SS_UP(X_LCTL)
                    SS_UP(X_LALT)
                    SS_UP(X_LSFT)
				);
			}
			break;
		case M_CLONE_DOWN:
			if (record->event.pressed) {
				SEND_STRING(
                    SS_DOWN(X_LCTL)
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_LSFT)
					SS_TAP(X_DOWN)
                    SS_UP(X_LCTL)
                    SS_UP(X_LALT)
                    SS_UP(X_LSFT)
				);
			}
			break;
		case M_MEH_LEFT:
			if (record->event.pressed) {
				SEND_STRING(
                    SS_DOWN(X_LCTL)
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_LSFT)
					SS_TAP(X_LEFT)
                    SS_UP(X_LCTL)
                    SS_UP(X_LALT)
                    SS_UP(X_LSFT)
				);
			}
			break;
		case M_MEH_RIGHT:
			if (record->event.pressed) {
				SEND_STRING(
                    SS_DOWN(X_LCTL)
                    SS_DOWN(X_LALT)
                    SS_DOWN(X_LSFT)
					SS_TAP(X_RIGHT)
                    SS_UP(X_LCTL)
                    SS_UP(X_LALT)
                    SS_UP(X_LSFT)
				);
			}
			break;
        case TD(TD_Q):
        case TD(TD_W):
        case TD(TD_R):
        case TD(TD_T):
        case TD(TD_A):
        case TD(TD_S):
        case TD(TD_D):
        case TD(TD_F):
        case TD(TD_G):
        case TD(TD_H):
        case TD(TD_J):
        case TD(TD_K):
        case TD(TD_Z):
        case TD(TD_X):
        case TD(TD_C):
        case TD(TD_V):
        case TD(TD_B):
        case TD(TD_N):
        case TD(TD_M):
        case TD(TD_SLASH):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;
        default:
            break;
    }
    return true;
}

// layout
const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] =
LAYOUT_split_3x6_3(
        KC_DEL, TD(TD_Q), TD(TD_W), KC_E, TD(TD_R), TD(TD_T), LT(REF, KC_Y), KC_U, KC_I, KC_O, KC_P, KC_BACKSLASH,
        MT(MOD_LCTL, KC_ESCAPE), TD(TD_A), TD(TD_S), TD(TD_D), TD(TD_F), TD(TD_G), TD(TD_H), TD(TD_J), TD(TD_K), KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, TD(TD_Z), TD(TD_X), TD(TD_C), TD(TD_V), TD(TD_B), TD(TD_N), TD(TD_M), KC_COMM, KC_DOT, TD(TD_SLASH), KC_RSFT,
        TL_LOWR, MT(MOD_RGUI, KC_SPC), KC_BACKSPACE, MT(MOD_LGUI, KC_TAB), MT(MOD_LALT, KC_ENTER), TL_UPPR
),
[LOWER] =
LAYOUT_split_3x6_3(
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_GRAVE, KC_EQUAL, KC_TRNS, KC_TRNS, KC_MINUS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[RAISE] =
LAYOUT_split_3x6_3(
        KC_TRNS, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_LGUI, KC_TRNS, KC_TRNS, KC_MEH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[TRI] =
LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_CLONE_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, M_MEH_LEFT, KC_LGUI, RALT(RGUI(KC_LEFT)), LALT(LGUI(KC_RIGHT)), KC_TAB, M_MEH_RIGHT, LALT(KC_ENTER), LALT(LSFT(KC_ENTER)), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_CLONE_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[REF] =
LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M_REN, KC_TRNS, KC_TRNS, KC_TRNS, M_INL, KC_TRNS, M_PARAM, KC_TRNS,
        KC_TRNS, KC_TRNS, M_SIG, KC_TRNS, M_FIELD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, M_CONST, KC_TRNS, KC_TRNS, KC_TRNS, M_MET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};
