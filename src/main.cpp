#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_music_items.h"
#include "bn_sprite_actions.h"
#include "bn_vector.h"

#include "game_loop.h"

#include "kvalligraphy_8x8_variable.h"

#define PLAY_MENU 1
#define CREATE 2
#define CREDITS 3
#define PLAY 4
#define GO_BACK 0

int main()
{
    bn::core::init();

    bn::sprite_font font(bn::sprite_items::kvalligraphy_8x8, variable_8x8_sprite_font_utf8_characters,
                         variable_8x8_sprite_font_character_widths);
    bn::sprite_text_generator txt(font);
    bn::sprite_text_generator* text_ptr = &txt;

    bn::bg_palettes::set_transparent_color(bn::color(3, 3, 3));

    bn::music_items::mustard_loop.play(0.5);

    loop::menu(text_ptr);
}
