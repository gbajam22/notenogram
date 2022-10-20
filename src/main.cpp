#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_regular_bg_actions.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_map_cell_info.h"
#include "bn_sprite_actions.h"

#include "picross_grid.h"
#include "vn_text_output.h"

#include "bn_regular_bg_items_square.h"
#include "bn_sprite_items_cursor_circle.h"
#include "bn_sprite_items_cursor_eraser.h"
#include "bn_sprite_items_cursor_pen.h"
#include "kvalligraphy_8x8_variable.h"

bn::fixed sprite_x(int const &cursor_x, int const &cols)
{
    return (cursor_x * 8) - (cols * 4) + 8;
}

bn::fixed sprite_y(int const &cursor_y, int const &rows)
{
    return (cursor_y * 8) - (rows * 4) + 8;
}

int main()
{
    bn::core::init();

    bn::sprite_font font(bn::sprite_items::kvalligraphy_8x8, variable_8x8_sprite_font_utf8_characters,
                         variable_8x8_sprite_font_character_widths);
    bn::sprite_text_generator txt(font);
    bn::sprite_text_generator* text_ptr = &txt;

    //bn::bg_palettes::set_transparent_color(bn::color(0,0,0));

    bn::bg_palette_item common_palette(bn::regular_bg_items::square.palette_item());

    bn::fixed bg_x = 0;
    bn::fixed bg_y = 0;
    int cols = 32;
    int rows = 32;
    int spr_x = cols/2;
    int spr_y = rows/2;

    int screen_cells = cols*rows;

    bn::regular_bg_map_cell cells[screen_cells];
    bn::regular_bg_map_item map_item(cells[0], bn::size(cols, rows));

    bn::regular_bg_item item(bn::regular_bg_items::square.tiles_item(), common_palette,
                             map_item);

    //bn::regular_bg_ptr paper_bg = bn::regular_bg_items::square.create_bg(bg_x, bg_y);
    bn::regular_bg_ptr grid_bg = item.create_bg(0, 0);
    bn::regular_bg_map_ptr map = grid_bg.map();
    bn::sprite_ptr cursor_sprite = bn::sprite_items::cursor_pen.create_sprite(bg_x, bg_y);

    int script_ptr = 0;
    int line_ptr = 0;
    int symbol_ptr = 0;
    bool apply_effect = true;
    int current_line = 0;

    const bn::string_view test[] =
    {
        "Hello!",
        "This is sample text to test the text output class methods!",
        "As you can see, it can easily break long strings into several lines and output them with a neat typewriter effect.",
        "Of course, it also breaks really long strings of symbols like kfjndflkgnlskgjlksdjfjskdhfjkshfskfjfskdfhhghfjkghhdjskjghgjfhgfdfgdfggsdkfj",
        "Well, sort of. The last line is guaranteed to get cut to the line's predefined size (31 symbols, can be adjusted).",
        "This may look unnecessary, but it should be helpful for outputting text in Japanese, for example.",
        "Try pressing A while the text is still scrolling so that the text container manager outputs everything at once!"
    };

    text _text(test[script_ptr], text_ptr);
    bn::memory::clear(screen_cells, cells[0]);

    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            bn::regular_bg_map_cell_info cell_info(cells[map_item.cell_index(j, i)]);
            bn::regular_bg_map_cell& current_cell = cells[map_item.cell_index(j, i)];

            int cell_number = 1;
            if (j < 2 || j > 29)
                cell_number = 32;
            if (j == 2)
                cell_number = 21;
            if (j == 27)
                cell_number = 16;
            if (j == 29)
                cell_number = 22;
            cell_info.set_tile_index(cell_number);
            current_cell = cell_info.cell();
        }
    }
    map.reload_cells_ref();


    while(true)
    {
        if (apply_effect) apply_effect = _text.output_Typewriter(test[script_ptr], symbol_ptr, line_ptr, 0);
        if (bn::keypad::a_pressed())
        {
            if (!apply_effect)
            {
                line_ptr = 0;
                symbol_ptr = 0;
                if (++script_ptr >= 7)
                {
                    script_ptr = 0;
                }
                _text.redraw(test[script_ptr]);
                apply_effect = true;
            }
            else
            {
                apply_effect = _text.output_NoEffect(test[script_ptr]);
            }
            bn::regular_bg_map_cell_info cell_i(cells[map_item.cell_index(spr_x, spr_y)]);
            bn::regular_bg_map_cell& current_cell = cells[map_item.cell_index(spr_x, spr_y)];
            cell_i.set_tile_index(cell_i.tile_index() == 1 ? 3 : 1);
            current_cell = cell_i.cell();
            map.reload_cells_ref();
        }
        if (bn::keypad::b_pressed())
        {
            bn::regular_bg_map_cell_info cell_i(cells[map_item.cell_index(spr_x, spr_y)]);
            bn::regular_bg_map_cell& current_cell = cells[map_item.cell_index(spr_x, spr_y)];
            cell_i.set_tile_index(cell_i.tile_index() == 1 ? 2 : 1);
            current_cell = cell_i.cell();
            map.reload_cells_ref();
        }
        if (bn::keypad::down_pressed())
        {
            if (spr_y < 24)
                ++spr_y;
        }
        else if (bn::keypad::up_pressed())
        {
            if (spr_y > 13)
                --spr_y;
        }
        if (bn::keypad::right_pressed())
        {
            if (spr_x < 24)
                ++spr_x;
        }
        else if (bn::keypad::left_pressed())
        {
            if (spr_x > 13)
                --spr_x;
        }

        //bg_y += 0.3;
        //grid_bg.set_position(0, bg_y);
        cursor_sprite.set_position(sprite_x(spr_x, cols), sprite_y(spr_y, rows));
        bn::core::update();
    }
}
