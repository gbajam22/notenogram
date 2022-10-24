#include "state_main.h"

namespace MainGame
{
    void createPuzzle()
    {
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
                    if (j < 2 || j > 29)
                        cell_number = 32;
                    if (j == 2)
                        cell_number = 21;
                    /*if (j == 3 && i % 5 == 0)
                        cell_number = 19;
                    if (j == 3 && i % 6 == 0)
                        cell_number = 20;*/
                    if (j == 25)
                        cell_number = 16;
                    if (j == 29)
                        cell_number = 22;
                    cell_info.set_tile_index(cell_number);
                    current_cell = cell_info.cell();
                }
            }
        map.reload_cells_ref();

        PicrossGrid grid;
        grid.create();
        bn::sprite_ptr cursor_sprite = bn::sprite_items::cursor_pen.create_sprite(grid.cellX2Screen(), grid.cellY2Screen());

        while(true)
        {
            grid.processDPadInput();
            if (grid.processKeyInput(cells[map_item.cell_index(
                                         grid.getCursorX(),
                                         grid.getCursorY())]))
            {
                grid.updateHints(grid.getCurrentGrid());

                for (int i = 0; i < 12; ++i)
                {
                    for (int j = 0; j < 6; ++j)
                    {
                        bn::regular_bg_map_cell &current_cell = cells[map_item.cell_index(13+i, 12-j)];
                        bn::regular_bg_map_cell_info current_cell_info(current_cell);
                        if (grid.grid_hints_up[6*i+j] > 0)
                        {
                            current_cell_info.set_tile_index(grid.grid_hints_up[6*i+j]+3);
                        }
                        else current_cell_info.set_tile_index(1);
                        current_cell = current_cell_info.cell();
                    }
                }
                for (int i = 0; i < 12; ++i)
                {
                    for (int j = 0; j < 6; ++j)
                    {
                        bn::regular_bg_map_cell &current_cell = cells[map_item.cell_index(12-j, 13+i)];
                        bn::regular_bg_map_cell_info current_cell_info(current_cell);
                        if (grid.grid_hints_left[6*i+j] > 0)
                        {
                            current_cell_info.set_tile_index(grid.grid_hints_left[6*i+j]+3);
                        }
                        else current_cell_info.set_tile_index(1);
                        current_cell = current_cell_info.cell();
                    }
                }

                map.reload_cells_ref();
            }
            cursor_sprite.set_position(grid.cellX2Screen(), grid.cellY2Screen());
            bn::core::update();
        }
    }

    void solvePuzzle(const bn::array<bool, 144> &p)
    {
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
                    if (j < 2 || j > 29)
                        cell_number = 32;
                    if (j == 2)
                        cell_number = 21;
                    /*if (j == 3 && i % 5 == 0)
                        cell_number = 19;
                    if (j == 3 && i % 6 == 0)
                        cell_number = 20;*/
                    if (j == 25)
                        cell_number = 16;
                    if (j == 29)
                        cell_number = 22;
                    cell_info.set_tile_index(cell_number);
                    current_cell = cell_info.cell();
                }
            }
        map.reload_cells_ref();

        PicrossGrid grid;
        grid.solve();

        grid.updateHints(p);

        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                bn::regular_bg_map_cell &current_cell = cells[map_item.cell_index(13+i, 12-j)];
                bn::regular_bg_map_cell_info current_cell_info(current_cell);
                if (grid.grid_hints_up[6*i+j] > 0)
                {
                    current_cell_info.set_tile_index(grid.grid_hints_up[6*i+j]+3);
                }
                else current_cell_info.set_tile_index(1);
                current_cell = current_cell_info.cell();
            }
        }
        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                bn::regular_bg_map_cell &current_cell = cells[map_item.cell_index(12-j, 13+i)];
                bn::regular_bg_map_cell_info current_cell_info(current_cell);
                if (grid.grid_hints_left[6*i+j] > 0)
                {
                    current_cell_info.set_tile_index(grid.grid_hints_left[6*i+j]+3);
                }
                else current_cell_info.set_tile_index(1);
                current_cell = current_cell_info.cell();
            }
        }

        bn::sprite_ptr cursor_sprite = bn::sprite_items::cursor_pen.create_sprite(grid.cellX2Screen(), grid.cellY2Screen());

        int frames2skip = 0;
        while(true)
        {
            //grid.processDPadInput();
            if (
                    (grid.processDPadContinuousInput(frames2skip) &&
                    grid.processKeyContinuousInput(cells[map_item.cell_index(
                                                       grid.getCursorX(),
                                                       grid.getCursorY())])) ||
                    grid.processKeyInput(cells[map_item.cell_index(
                                         grid.getCursorX(),
                                         grid.getCursorY())]))
            {
                map.reload_cells_ref();
                if(grid.checkSolution(p))
                {
                    bn::regular_bg_map_cell &current_cell = cells[map_item.cell_index(11,11)];
                    bn::regular_bg_map_cell_info current_cell_info(current_cell);
                    current_cell_info.set_tile_index(29);
                    current_cell = current_cell_info.cell();
                }
            }
            cursor_sprite.set_position(grid.cellX2Screen(), grid.cellY2Screen());
            bn::core::update();
        }
    }
}
