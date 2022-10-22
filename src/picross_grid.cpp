#include "picross_grid.h"

PicrossGrid::PicrossGrid()
{
    cursor_position[0] = (screen_cell_upper_limit + screen_cell_lower_limit)/2;
    cursor_position[1] = cursor_position[0];

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            grid[j][i] = false;
        }
        for (int j = 0; j < 6; ++j)
        {
            grid_hints_left.push_back(0);
            grid_hints_up.push_back(0);
        }
    }
}

int PicrossGrid::cellX2Screen()
{
    return (cursor_position[0] * 8) - (32 * 4) + 8;
}

int PicrossGrid::cellY2Screen()
{
    return (cursor_position[1] * 8) - (32 * 4) + 8;
}

int PicrossGrid::getCursorX()
{
    return cursor_position[0];
}

int PicrossGrid::getCursorY()
{
    return cursor_position[1];
}

//todo: continuous cell marking like in battle picross
bool PicrossGrid::processKeyInput(bn::regular_bg_map_cell& cell)
{
    bn::regular_bg_map_cell_info info(cell);
    if (bn::keypad::a_pressed())
    {
        int current_index = info.tile_index();
        int new_index = 1;
        if (current_index == 1 || current_index == 2)
        {
            new_index = 3;
            grid[cursor_position[0]-screen_cell_lower_limit][cursor_position[1]-screen_cell_lower_limit] = true;
        }
        else
        {
            grid[cursor_position[0]-screen_cell_lower_limit][cursor_position[1]-screen_cell_lower_limit] = false;
        }
        info.set_tile_index(new_index);
        cell = info.cell();
        return true;
    }
    else if (bn::keypad::b_pressed())
    {
        int current_index = info.tile_index();
        int new_index = 1;
        if (current_index == 1 || current_index == 3)
        {
            new_index = 2;
        }
        info.set_tile_index(new_index);
        cell = info.cell();
        return true;
    }
    else return false;
}

bool PicrossGrid::processDPadInput()
{
    if (bn::keypad::down_pressed())
    {
        if (cursor_position[1] < screen_cell_upper_limit)
        {
            ++cursor_position[1];
        }
        return true;
    }
    else if (bn::keypad::up_pressed())
    {
        if (cursor_position[1] > screen_cell_lower_limit)
        {
            --cursor_position[1];
        }
        return true;
    }
    if (bn::keypad::right_pressed())
    {
        if (cursor_position[0] < screen_cell_upper_limit)
        {
            ++cursor_position[0];
        }
        return true;
    }
    else if (bn::keypad::left_pressed())
    {
        if (cursor_position[0] > screen_cell_lower_limit)
        {
            --cursor_position[0];
        }
        return true;
    }
    return false;
}

void PicrossGrid::outputHints()
{
    /*int hint_index = 0;
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            if (grid_hints_up[0] == 0)
            {
                hint_index += j;
                j = 5;
            }
            else
            {
                bn::regular_bg_map_cell &current_cell = cells[item.cell_index(12+i, screen_cell_lower_limit-j)];
                bn::regular_bg_map_cell_info current_cell_info(current_cell);

                current_cell_info.set_tile_index(grid_hints_up[hint_index]+3);
                current_cell = current_cell_info.cell();
            }
        }
    }
    hint_index = 0;
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            if (grid_hints_up[0] == 0)
            {
                hint_index += j;
                j = 5;
            }
            else
            {
                bn::regular_bg_map_cell &current_cell = cells[item.cell_index(screen_cell_lower_limit-j, 12+i)];
                bn::regular_bg_map_cell_info current_cell_info(current_cell);

                current_cell_info.set_tile_index(grid_hints_left[hint_index]+3);
                current_cell = current_cell_info.cell();
            }
        }
    }*/
}

//only works when in creator mode
void PicrossGrid::updateHints()
{
    if (creator_mode)
    {
        grid_hints_left.clear();
        grid_hints_up.clear();

        for (int i = 0; i < 12; ++i)
        {
            int row_cell_counter = 0;
            int col_cell_counter = 0;

            int hint_counter_up = 0;
            int hint_counter_left = 0;
            for (int j = 11; j >= 0; --j)
            {
                if (!grid[i][j])
                {
                    if (row_cell_counter != 0)
                    {
                        grid_hints_up.push_back(row_cell_counter);
                        row_cell_counter = 0;
                        ++hint_counter_up;
                    }
                }
                else ++row_cell_counter;
                if (!grid[i][j])
                {
                    if (col_cell_counter != 0)
                    {
                        grid_hints_left.push_back(col_cell_counter);
                        col_cell_counter = 0;
                        ++hint_counter_left;
                    }
                }
                else ++col_cell_counter;
            }

            for (int j = 0; j < 6 - hint_counter_left; ++j)
            {
                grid_hints_left.push_back(0);
            }
            for (int j = 0; j < 6 - hint_counter_up; ++j)
            {
                grid_hints_up.push_back(0);
            }
        }
    }
}

void PicrossGrid::create()
{
    creator_mode = true;
}


