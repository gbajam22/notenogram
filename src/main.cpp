#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_actions.h"

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

    //bn::bg_palettes::set_transparent_color(bn::color(0,0,0));

    /*bn::bg_palette_item common_palette(bn::regular_bg_items::square.palette_item());

    bn::fixed bg_x = 0;
    bn::fixed bg_y = 0;
    int cols = 32;
    int rows = 32;*/

    /*int screen_cells = cols*rows;

    bn::regular_bg_map_cell cells[screen_cells];
    bn::regular_bg_map_item map_item(cells[0], bn::size(cols, rows));

    bn::regular_bg_item item(bn::regular_bg_items::square.tiles_item(), common_palette,
                             map_item);

    //bn::regular_bg_ptr paper_bg = bn::regular_bg_items::square.create_bg(bg_x, bg_y);
    bn::regular_bg_ptr grid_bg = item.create_bg(0, 0);
    bn::regular_bg_map_ptr map = grid_bg.map();*/

    int script_ptr = 0;
    int line_ptr = 0;
    int symbol_ptr = 0;
    bool apply_effect = true;
    int current_line = 0;

    MainGame::solvePuzzle();
/*
    GameState state;
    PicrossGrid grid;

    state.PaperSheetPattern_Regular();
    bn::sprite_ptr cursor_sprite = bn::sprite_items::cursor_pen.create_sprite(grid.cellX2Screen(), grid.cellY2Screen());

    bn::regular_bg_map_cell& cell = state.cells[state.item.cell_index(grid.getCursorX(), grid.getCursorY())];

    while(true)
    {
        if (grid.processDPadInput())
        {
            cell = state.cells[state.item.cell_index(grid.getCursorX(), grid.getCursorY())];
        }
        if (grid.processKeyInput(cell))
        {
            state.refreshScreen();
        }
        cursor_sprite.set_position(grid.cellX2Screen(), grid.cellY2Screen());
        bn::core::update();
    }*/
}
