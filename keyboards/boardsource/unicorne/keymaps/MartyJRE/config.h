// Copyright 2023 MartyJRE
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Include the default config.h settings
#include "../../config.h"

// Override TAPPING_TERM to make the keyboard more responsive
#undef TAPPING_TERM
#define TAPPING_TERM 150

// Make Shift and other modifier keys more responsive
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// Increase the debounce time for better key recognition
#define DEBOUNCE 10

// Enable retro tapping for better modifier key behavior
#define RETRO_TAPPING

// Enable hold on other key press for better modifier behavior
#define HOLD_ON_OTHER_KEY_PRESS