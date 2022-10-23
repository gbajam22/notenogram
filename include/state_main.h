#ifndef STATE_MAIN_H
#define STATE_MAIN_H

#include "bn_core.h"
#include "bn_bg_palette_actions.h"
#include "bn_music_actions.h"

#include "picross_grid.h"
#include "picross_solutions.h"
#include "vn_text_output.h"

#include "bn_regular_bg_items_square.h"
#include "bn_sprite_items_cursor_pen.h"

namespace MainGame
{
    void solvePuzzle();
    void solvedScreen();
    void createPuzzle();
}

#endif // STATE_MAIN_H
