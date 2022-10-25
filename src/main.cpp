#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_actions.h"

#include "state_start_menu.h"
#include "vn_text_output.h"

#include "kvalligraphy_8x8_variable.h"

int main()
{
    bn::core::init();

    bn::sprite_font font(bn::sprite_items::kvalligraphy_8x8, variable_8x8_sprite_font_utf8_characters,
                         variable_8x8_sprite_font_character_widths);
    bn::sprite_text_generator txt(font);
    bn::sprite_text_generator* text_ptr = &txt;
    MainGame::solvePuzzle(PuzzleSelect::menu(text_ptr));
    //MainGame::createPuzzle();

    /*bool weh = true;

    bn::fixed x = 0;
    bn::fixed y = 0;

    MainMenu::setScrollingScreen(x,y);
    MainMenu::menu(weh,text_ptr);*/
}
