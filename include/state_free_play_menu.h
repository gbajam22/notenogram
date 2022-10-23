#ifndef STATE_FREE_PLAY_MENU_H
#define STATE_FREE_PLAY_MENU_H

#include "bn_array.h"
#include "bn_core.h"
#include "bn_bg_palette_actions.h"
#include "bn_bg_palette_actions.h"
#include "bn_music_actions.h"
#include "bn_keypad.h"

#include "picross_grid.h"
#include "picross_solutions.h"
#include "vn_text_output.h"

#include "bn_regular_bg_items_square.h"
#include "bn_sprite_items_cursor_circle.h"

namespace PuzzleSelect
{
    bn::array<bool, 144> const& menu(bn::sprite_text_generator*);
}

#endif // STATE_FREE_PLAY_MENU_H
