#include "state_base.h"

GameState::GameState() :
    //cur_x(0), cur_y(0),
    bg_x(0), bg_y(0), //current_puzzle(puzzle::Custom),
    //common_palette(bn::regular_bg_items::square.palette_item()),
    //common_sprite_palette(bn::sprite_items::logo.palette_item()),
    item(cells[0], bn::size(columns, rows))
{
    resetMap();
}

GameState::GameState(int x, int y) :
    bg_x(x), bg_y(x), //current_puzzle(puzzle::Custom),cur_x(x), cur_y(y),
    //common_palette(bn::regular_bg_items::square.palette_item()),
    //common_sprite_palette(bn::sprite_items::logo.palette_item()),
    item(cells[0], bn::size(columns, rows))
{
    resetMap();
}

/*GameState::GameState(int x, int y, bn::bg_palette_item const& palette) :
    bg_x(x), bg_y(x), current_puzzle(puzzle::Custom),//cur_x(y), cur_y(y),
    common_palette(palette),
    common_sprite_palette(bn::sprite_items::logo.palette_item()),
    item(cells[0], bn::size(columns, rows))
{
    resetMap();
}*/

bn::regular_bg_ptr GameState::buildBG()
{
    bn::regular_bg_item i(bn::regular_bg_items::square.tiles_item(), bn::regular_bg_items::square.palette_item(), item);
    bn::regular_bg_builder builder(i);
    builder.set_position(bg_x, bg_y);
    return builder.release_build();
}

bn::optional<bn::sprite_ptr> GameState::buildSprite(const bn::sprite_item &s, int x, int y)
{
    bn::sprite_item i(s.shape_size(), s.tiles_item(), bn::sprite_items::logo.palette_item());
    bn::sprite_builder builder(i);
    builder.set_position(x, y);
    return builder.release_build_optional();
}

const bn::bg_palette_item GameState::getCommonPalette()
{
    return bn::regular_bg_items::square.palette_item();
}

/*void GameState::setCellTile(int tile_index)
{
    bn::regular_bg_map_cell &current_cell = cells[item.cell_index(cur_x, cur_y)];
    bn::regular_bg_map_cell_info current_cell_info(current_cell);
    current_cell_info.set_tile_index(tile_index);
    current_cell = current_cell_info.cell();
}*/
void GameState::setCellTile(int x, int y, int tile_index)
{
    bn::regular_bg_map_cell &current_cell = cells[item.cell_index(x, y)];
    bn::regular_bg_map_cell_info current_cell_info(current_cell);
    current_cell_info.set_tile_index(tile_index);
    current_cell = current_cell_info.cell();
}

bn::regular_bg_map_cell& GameState::retrieveCell(int x, int y)
{
    return cells[item.cell_index(x, y)];
}

void GameState::resetMap()
{
    bn::memory::clear(screen_cells, cells[0]);
}

void GameState::refreshScreen(bn::regular_bg_map_ptr &map)
{
    map.reload_cells_ref();
}

void GameState::scrollScreen(int x_delta, int y_delta, bn::regular_bg_ptr &bg)
{
    bg.set_x(bg.x() + x_delta);
    bg.set_y(bg.y() + y_delta);
    bg.set_position(bg_x, bg_y);
}

void GameState::PaperSheetPattern_Regular()
{
    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            int cell_number = 1;
            if (j < 2 || j > 29)
                cell_number = 32;
            if (j == 2)
                cell_number = 21;
            if (j == 25)
                cell_number = 16;
            if (j == 29)
                cell_number = 22;
            setCellTile(j, i, cell_number);
        }
    }
}
//title
void GameState::PaperSheetPattern_Scrollable()
{
    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            int cell_number = 1;
            setCellTile(j, i, cell_number);
        }
    }
}
//puzzle selection
void GameState::PaperSheetPattern_PuzzleSelection(int& low_limit, int& up_limit)
{
    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            int cell_number = 1;
            if (i < 7 || i > 24)
                cell_number = 32;
            if (i == 7)
            {
                cell_number = j & 1 ? 25 : 24;
            }
            if (i == 22)
                cell_number = 23;
            if (i >= low_limit && i <= up_limit && i & 1)
            {
                if (j == 15)
                    cell_number = 4;
                if (j == 17)
                    cell_number = 5;
                if (j == 19)
                    cell_number = 6;
            }
            setCellTile(j, i, cell_number);
        }
    }
}

GameState::~GameState()
{
    resetMap();
}
