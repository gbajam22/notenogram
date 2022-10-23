#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_actions.h"

#include "state_free_play_menu.h"
#include "state_main.h"
#include "vn_text_output.h"

#include "bn_regular_bg_items_square.h"
#include "bn_sprite_items_cursor_circle.h"
#include "bn_sprite_items_cursor_eraser.h"
#include "bn_sprite_items_cursor_pen.h"
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
}
