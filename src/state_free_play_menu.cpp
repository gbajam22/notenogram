#include "state_free_play_menu.h"

namespace PuzzleSelect
{
    int cellX2Screen(int x, int spr_delta)
    {
        return (x * 8) - (32 * 4) + spr_delta;
    }

    int cellY2Screen(int y, int spr_delta)
    {
        return (y * 8) - (32 * 4) + spr_delta;
    }

    bn::array<bool, 144> const& menu(bn::sprite_text_generator* stg)
    {
        bn::array<int, 2> cursor_position;
        cursor_position[0] = 15;
        cursor_position[1] = 13;
        bn::bg_palette_item common_palette(bn::regular_bg_items::square.palette_item());

            bn::fixed bg_x = 0;
            bn::fixed bg_y = 0;
            int cols = 32;
            int rows = 32;

        int screen_cells = cols*rows;

        bn::regular_bg_map_cell cells[screen_cells];
        bn::regular_bg_map_item map_item(cells[0], bn::size(cols, rows));

        bn::regular_bg_item item(bn::regular_bg_items::square.tiles_item(), common_palette,
                                 map_item);

        bn::regular_bg_ptr grid_bg = item.create_bg(0, 0);
        bn::regular_bg_map_ptr map = grid_bg.map();

        bn::memory::clear(screen_cells, cells[0]);
        //GameState state;
        //state.PaperSheetPattern_Regular();

        for (int i = 0; i < cols; ++i)
            {
                for (int j = 0; j < rows; ++j)
                {
                    bn::regular_bg_map_cell_info cell_info(cells[map_item.cell_index(j, i)]);
                    bn::regular_bg_map_cell& current_cell = cells[map_item.cell_index(j, i)];

                    int cell_number = 1;
                    if (i < 6 || i > 24)
                        cell_number = 32;
                    if (i == 21)
                        cell_number = 23;
                    if (i == 13 || i == 15 || i == 17 || i == 19)
                    {
                        if (j == 15)
                            cell_number = 4;
                        if (j == 17)
                            cell_number = 5;
                        if (j == 19)
                            cell_number = 6;
                    }
                    cell_info.set_tile_index(cell_number);
                    current_cell = cell_info.cell();
                }
            }
        map.reload_cells_ref();

        text _text(stg);

        _text.outputSingleLine(cellX2Screen(10, 4), cellY2Screen(9, 4), "Choose a puzzle");

        _text.outputSingleLine(cellX2Screen(6, 4), cellY2Screen(13, 4), "things");
        _text.outputSingleLine(cellX2Screen(6, 4), cellY2Screen(15, 4), "nature");
        _text.outputSingleLine(cellX2Screen(6, 4), cellY2Screen(17, 4), "kanji");
        _text.outputSingleLine(cellX2Screen(6, 4), cellY2Screen(19, 4), "portraits");

        while(true)
        {
            if (bn::keypad::down_pressed())
            {
                if (cursor_position[1] < 19)
                {
                    cursor_position[1]+=2;
                }
            }
            else if (bn::keypad::up_pressed())
            {
                if (cursor_position[1] > 13)
                {
                    cursor_position[1]-=2;
                }
            }
            if (bn::keypad::right_pressed())
            {
                if (cursor_position[0] < 19)
                {
                    cursor_position[0]+=2;
                }
            }
            else if (bn::keypad::left_pressed())
            {
                if (cursor_position[0] > 15)
                {
                    cursor_position[0]-=2;
                }
            }
            if (bn::keypad::a_pressed())
            {
                switch(cursor_position[1])
                {
                case 13:
                    switch(cursor_position[0])
                    {
                    case 15:
                        return puzzle::Things_Gameboy;
                    case 17:
                        return puzzle::Things_Giftbox;
                    case 19:
                        return puzzle::Things_Notepad;
                    default:
                        break;
                    }
                    break;
                case 15:
                    switch(cursor_position[0])
                    {
                    case 15:
                        return puzzle::Nature_4LClover;
                    case 17:
                        return puzzle::Nature_Flower;
                    case 19:
                        return puzzle::Nature_Lagomorph;
                    default:
                        break;
                    }
                    break;
                case 17:
                    switch(cursor_position[0])
                    {
                    case 15:
                        return puzzle::Kanji_Cat;
                    case 17:
                        return puzzle::Kanji_Congrats;
                    case 19:
                        return puzzle::Kanji_Flower;
                    default:
                        break;
                    }
                    break;
                case 19:
                    switch(cursor_position[0])
                    {
                    case 15:
                        return puzzle::Portrait_Nyra;
                    case 17:
                        return puzzle::Portrait_Tooru;
                    case 19:
                        return puzzle::Portrait_Yuuji;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
            }
            else if (bn::keypad::b_pressed())
            {

            }

            bn::sprite_ptr cursor_sprite = bn::sprite_items::cursor_circle.create_sprite(cellX2Screen(cursor_position[0], 8), cellY2Screen(cursor_position[1], 8));
            bn::core::update();
        }
    }
}