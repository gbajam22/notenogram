#ifndef STATE_FREE_PLAY_MENU_H
#define STATE_FREE_PLAY_MENU_H

#include "bn_core.h"
#include "bn_bg_palette_actions.h"
#include "bn_bg_palette_actions.h"
//#include "bn_music_items.h"
#include "bn_keypad.h"
#include "bn_string.h"

#include "state_base.h"
#include "picross_solutions.h"
#include "vn_text_output.h"

#include "bn_regular_bg_items_square.h"
#include "bn_sprite_items_cursor_circle.h"
#include "bn_sprite_items_scribble_star.h"

class PuzzleSelect : public GameState
{
    bn::regular_bg_ptr bg;
    bn::regular_bg_map_ptr map;

    bn::array<int, 2> cursor_position = {15, 13};
    bn::optional<bn::sprite_ptr> cursor_sprite, scribble_left;
    /*bn::sprite_animate_action<2> two_frame_anim = bn::create_sprite_animate_action_forever
                        (*scribble_left, 11, bn::sprite_items::scribble_star.tiles_item(), 0,1);*/
    bn::array<bool, 3> slots_occupied = {0};

    int menu_hrz_lower_limit, menu_hrz_upper_limit,
        menu_vrt_lower_limit, menu_vrt_upper_limit;

    text _text;

    //bn::array<bool, 144> const* selected_puzzle;

public:
    PuzzleSelect(bn::sprite_text_generator*);
    //PuzzleSelect(int, int, bn::sprite_text_generator*);
    //PuzzleSelect(int, int, bn::bg_palette_item const&, bn::sprite_text_generator*);
    void showMenu();
    int updateState() override;
};

#endif // STATE_FREE_PLAY_MENU_H
