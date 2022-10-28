#ifndef STATE_START_H
#define STATE_START_H

#include "bn_blending_actions.h"
#include "bn_blending_fade_alpha.h"

#include "state_base.h"
#include "vn_text_output.h"

#include "bn_regular_bg_items_title.h"
//#include "bn_sprite_items_logo.h"
#include "bn_sprite_items_logo_butano.h"
#include "bn_sprite_items_cursor_pen.h"

class MainMenu : public GameState
{
    bn::regular_bg_ptr bg_pattern;
    bn::regular_bg_ptr bg_foreground;
    bn::regular_bg_map_ptr map;

    static constexpr int lower_bound = 20;
    static constexpr int upper_bound = 52;
    static constexpr int x_coord = 54;

    bn::array<int, 2> cursor_position = {x_coord, lower_bound};
    bn::optional<bn::sprite_ptr> cursor_sprite, logo;

    text _text;

    bool displaying_logo1, displaying_logo2, displaying_credits, returning_from_state;
    int logo_visibility = 0;
    int refresh_counter = 0;
    int foreground_x = -200;

    bn::string_view credits[5] =
    {
        "Press A to skip credit text, START to exit to main menu! Also, check out CREDITS.md for details!"
        "Programming, puzzles, art assets, voiceover, sounds -- kva64 (code distributed under zlib license, art and sounds - CC-BY-4.0)",
        "Engine -- Butano by GValiente (zlib license)",
        "Music -- congusbongus (CC0)",
        "Original GBA Jam 2022 logo design -- "
    };
    int script_ptr = 0;
    int line_ptr = 0;
    int symbol_ptr = 0;

public:
    MainMenu(bn::sprite_text_generator*);
    void initScrollingBG();
    void displaySplashLogos();
    void displayMainMenu();
    void displayCredits();
    int menu();
    int updateState();
};

#endif // STATE_START_H
