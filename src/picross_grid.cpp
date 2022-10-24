#include "picross_grid.h"

PicrossGrid::PicrossGrid()
{
    cursor_position[0] = (screen_cell_upper_limit + screen_cell_lower_limit)/2;
    cursor_position[1] = cursor_position[0];

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            grid[12*i+j] = false;
            if (j < 6)
            {
                grid_hints_left.push_back(0);
                grid_hints_up.push_back(0);
            }
        }
    }
}
//todo: separate helper/toolkit class for coordinate conversion
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
            grid[cursor_position[0]-screen_cell_lower_limit+12*(cursor_position[1]-screen_cell_lower_limit)] = true;
        }
        else
        {
            grid[cursor_position[0]-screen_cell_lower_limit+12*(cursor_position[1]-screen_cell_lower_limit)] = false;
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
            grid[cursor_position[0]-screen_cell_lower_limit+12*(cursor_position[1]-screen_cell_lower_limit)] = false;
        }
        info.set_tile_index(new_index);
        cell = info.cell();
        return true;
    }
    else return false;
}

bool PicrossGrid::processKeyContinuousInput(bn::regular_bg_map_cell& cell)
{
    bn::regular_bg_map_cell_info info(cell);
    if (bn::keypad::a_held())
    {
        int current_index = info.tile_index();
        if (current_index == 1)
        {
            grid[cursor_position[0]-screen_cell_lower_limit+12*(cursor_position[1]-screen_cell_lower_limit)] = true;
            info.set_tile_index(3);
            cell = info.cell();
        }
        return true;
    }
    else if (bn::keypad::b_held())
    {
        int current_index = info.tile_index();
        if (current_index == 1)
        {
            info.set_tile_index(2);
            cell = info.cell();
        }
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

bool PicrossGrid::processDPadContinuousInput(int &frames2skip)
{
    if (bn::keypad::down_pressed() || (bn::keypad::down_held() && frames2skip == 20))
    {
        if (cursor_position[1] < screen_cell_upper_limit)
        {
            ++cursor_position[1];
            frames2skip = 0;
        }
        return true;
    }
    else if (bn::keypad::up_pressed() || (bn::keypad::up_held() && frames2skip == 20))
    {
        if (cursor_position[1] > screen_cell_lower_limit)
        {
            --cursor_position[1];
            frames2skip = 0;
        }
        return true;
    }
    if (bn::keypad::left_pressed() || (bn::keypad::left_held() && frames2skip == 20))
        {
            if (cursor_position[0] > screen_cell_lower_limit)
            {
                --cursor_position[0];
                frames2skip = 0;
            }
            return true;
        }
    else if (bn::keypad::right_pressed() || (bn::keypad::right_held() && frames2skip == 20))
    {
        if (cursor_position[0] < screen_cell_upper_limit)
        {
            ++cursor_position[0];
            frames2skip = 0;
        }
        return true;
    }
    if (bn::keypad::a_held())
    {

    }
    ++frames2skip;
    return false;
}


//for on-screen hints, true if wrong cell is marked
bool PicrossGrid::checkCurrentCell(bn::array<bool, 144> const &solution)
{
    return grid[12*cursor_position[1]+cursor_position[0]] && !solution[12*cursor_position[1]+cursor_position[0]];
}

//for solution overall, true if 100% correct
bool PicrossGrid::checkSolution(bn::array<bool, 144> const &solution)
{
    for (int i = 0; i < 144; ++i)
    {
        if (grid[i] != solution[i]) return false;
    }
    return true;
}

bn::array<bool, 144> const &PicrossGrid::getCurrentGrid()
{
    return grid;
}

void PicrossGrid::drawHints(bn::regular_bg_map_cell& cells)
{

}

void PicrossGrid::updateHints(bn::array<bool, 144> const &_grid)
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
                if (_grid[12*j+i]) ++col_cell_counter;
                if (!_grid[12*j+i] || j == 0)
                {
                    if (col_cell_counter > 0)
                    {
                        grid_hints_up.push_back(col_cell_counter);
                        ++hint_counter_up;
                        col_cell_counter = 0;
                    }
                }
                if (_grid[12*i+j]) ++row_cell_counter;
                if (!_grid[12*i+j] || j == 0)
                {
                    if (row_cell_counter > 0)
                    {
                        grid_hints_left.push_back(row_cell_counter);
                        ++hint_counter_left;
                        row_cell_counter = 0;
                    }
                }
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

void PicrossGrid::create()
{
    creator_mode = true;
}

void PicrossGrid::solve()
{
    creator_mode = false;
}

void PicrossGrid::resetGrid()
{
    grid_hints_left.clear();
    grid_hints_up.clear();

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            grid[12*i+j] = false;
        }
    }
}

PicrossGrid::~PicrossGrid()
{
    grid_hints_left.clear();
    grid_hints_up.clear();
}


