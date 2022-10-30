#ifndef STATE_START_H
#define STATE_START_H

#include "bn_blending_actions.h"
#include "bn_blending_fade_alpha.h"
#include "bn_sprite_animate_actions.h"

#include "state_base.h"
#include "vn_text_output.h"

#include "bn_regular_bg_items_title.h"
#include "bn_sprite_items_logo_butano.h"
#include "bn_sprite_items_scribble_star.h"
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

    int foreground_x = 222;

    const bn::string_view credits[7] =
    {
        "Press A to skip credit text, B to exit to main menu!",
        "Also, visit notabug.org/lv10groove/notenogram for details and source code/assets!",
        "Programming, inbuilt puzzles, art assets and sounds by kva64 (kva64.itch.io)",
        "Butano engine by GValiente (gvaliente.itch.io, github.com/GValiente)",
        "BGM by congus-bongus (soundcloud.com/congus-bongus, ModArchive ID 85757)",
        "Original GBA Jam 2022 logo designs by GBA Jam 2022 hosts (details at github.com/gbajam22/gbajam22.github.io)",
        "This text will now be displayed from the beginning..."
    };

    int script_ptr,line_ptr,symbol_ptr;

public:
    int refresh_counter = 0;
    bool displaying_logo1, displaying_logo2, displaying_credits, returning_from_state;

    MainMenu(bn::sprite_text_generator*);
    void initScrollingBG();
    void displayIntro();
    void displayMainMenu();
    void displayCredits();

    int updateState();
    void toggleStateVisibility(bool) override;
    void toggleFadeEffect() override;
};

#endif // STATE_START_H
