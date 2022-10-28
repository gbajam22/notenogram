#ifndef STATE_MAIN_H
#define STATE_MAIN_H

#include "bn_audio.h"
#include "bn_bg_palette_actions.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_builder.h"
#include "bn_sram.h"

#include "picross_grid.h"
#include "picross_solutions.h"
#include "state_base.h"
#include "vn_text_output.h"

#include "bn_sprite_items_cursor_pen.h"
#include "bn_sprite_items_notonochan.h"
#include "bn_sprite_items_scribble_heart.h"
#include "bn_sprite_items_scribble_star.h"
#include "bn_sprite_items_stamp.h"

class MainGame : public GameState
{
    bn::regular_bg_ptr bg;
    bn::regular_bg_map_ptr map;

    PicrossGrid grid;
    bn::optional<bn::sprite_ptr> cursor_sprite;
    bn::optional<bn::sprite_ptr> notono_window, /*scribble_left, */scribble_right, stamp;
    bn::array<bn::sprite_animate_action<2>, 2> two_frame_anim =
    {
        bn::create_sprite_animate_action_forever
                    (*notono_window, 5, bn::sprite_items::notonochan.tiles_item(), 0,1),
        //bn::create_sprite_animate_action_forever
                    //(*scribble_left, 11, bn::sprite_items::scribble_star.tiles_item(), 0,1),
        bn::create_sprite_animate_action_forever
                    (*scribble_right, 10, bn::sprite_items::scribble_heart.tiles_item(), 0,1)
    };

    //bn::array<bool, 144> &current_puzzle = 0;

    text _text;
    bool mistake_made, puzzle_solved;
    int frames2skip, offset, frame_counter;

    static constexpr int max_slot_offset = 36;

public:
    MainGame(bn::sprite_text_generator *);
    MainGame(bn::array<bool, 144> const &);
    //MainGame(int, int, bn::array<bool, 144> &);
    //MainGame(int, int, bn::bg_palette_item &, bn::array<bool, 144> &);

    bn::sprite_animate_action<2>& initAnimateActions(bn::sprite_ptr&, int);
    void redrawHints();

    void createPuzzle();
    void solvePuzzle(bn::array<bool, 144> const &);
    void showSolvedScreen();

    int updateState(bn::array<bool, 144> const &);
    int updateState();
};

#endif // STATE_MAIN_H
