#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "bn_core.h"
#include "state_free_play_menu.h"
#include "state_main.h"
#include "state_start_menu.h"

namespace loop
{
    void solve_puzzle(bn::array<bool, 144> const&);
    void select_puzzle(bn::sprite_text_generator*);
    void make_puzzle(bn::sprite_text_generator*);
    void menu(bn::sprite_text_generator*);
}

#endif // GAME_LOOP_H
