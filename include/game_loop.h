#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include "fade_transparency_effects.h"
#include "state_free_play_menu.h"
#include "state_main.h"
#include "state_main_timed.h"
#include "state_start_menu.h"
#include "state_story.h"

namespace loop
{
    void solve_puzzle(bn::array<bool, 144> const&);
    int solve_arcade_puzzle();
    void select_puzzle(bn::sprite_text_generator*);
    void make_puzzle(bn::sprite_text_generator*);
    void init_story_mode(bn::sprite_text_generator*);
    void menu(bn::sprite_text_generator*);
}

#endif // GAME_LOOP_H
