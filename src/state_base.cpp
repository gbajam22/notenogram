#include "state_base.h"

/*GameState::GameState() :
    bg_x(0), bg_y(0),
    common_palette(bn::regular_bg_items::square.palette_item()),
    item(cells[0], bn::size(columns, rows)), bg(buildBG()), map(bg.map())
{
    resetMap();
}

GameState::GameState(int x, int y) :
    bg_x(x), bg_y(y),
    common_palette(bn::regular_bg_items::square.palette_item()),
    item(cells[0], bn::size(columns, rows)), bg(buildBG()), map(bg.map())
{
    resetMap();
}

GameState::GameState(int x, int y, bn::bg_palette_item const& palette) :
    bg_x(x), bg_y(y),
    common_palette(palette),
    item(cells[0], bn::size(columns, rows)), bg(buildBG()), map(bg.map())
{
    resetMap();
}

bn::regular_bg_ptr GameState::buildBG()
{
    bn::regular_bg_item bg_item(bn::regular_bg_items::square.tiles_item(), common_palette, item);
    bn::regular_bg_builder builder(bg_item);
    builder.set_position(bg_x, bg_y);
    return builder.release_build();
}

bn::bg_palette_item GameState::getCommonPalette()
{
    return common_palette;
}

void GameState::PaperSheetPattern_Regular()
{
    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            bn::regular_bg_map_cell &current_cell = cells[item.cell_index(j, i)];
            bn::regular_bg_map_cell_info current_cell_info(current_cell);

            int cell_number = 1;
            if (j < 2 || j > 29)
                cell_number = 32;
            if (j == 2)
                cell_number = 21;
            if (j == 26)
                cell_number = 16;
            if (j == 29)
                cell_number = 22;
            current_cell_info.set_tile_index(cell_number);
            current_cell = current_cell_info.cell();
        }
    }
    refreshScreen();
}

void GameState::resetMap()
{
    bn::memory::clear(screen_cells, cells[0]);
}

void GameState::refreshScreen()
{
    map.reload_cells_ref();
}

void GameState::scrollScreen(int x_delta, int y_delta)
{
    bg_x += x_delta;
    bg_y += y_delta;
    bg.set_position(bg_x, bg_y);
}*/
