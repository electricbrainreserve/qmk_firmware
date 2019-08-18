#ifndef EBR
#define EBR

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"


#define CTRLGRV LCTL(KC_GRV)
#define TTFLASH TT(_RESET)
#define TTFUNC TT(_FUNC)

typedef struct
{
    bool is_press_action;
    int state;
} ebr_tap;

enum ebr_tap_dance_keycodes
{
    SPC_ENT = 0,
    TLDQUAKE
};

#ifdef TAP_DANCE_ENABLE
#define SPCENT TD(SPC_ENT)
#define QUAKETRM TD(TLDQUAKE)
#else
#define SPCENT KC_1
#define QUAKETRM KC_1
#endif

enum ebr_layers
{
    _QWERTY = 0,
    _FUNC,
    _MACROS,
    _MIDI,
    _MUSIC,
    _RESET
}

#endif
