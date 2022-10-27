#ifndef PICROSS_GRID_H
#define PICROSS_GRID_H

#include <bn_array.h>
#include <bn_fixed_point.h>
#include "bn_keypad.h"
#include "bn_vector.h"

#include "bn_sound_items.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_map_cell_info.h"

class PicrossGrid
{
private:
    bn::array<bool, 144> grid;

    bn::array<int, 2> cursor_position;
    static constexpr int screen_cell_upper_limit = 24;
    static constexpr int screen_cell_lower_limit = 13;


public:

    bn::vector<int, 6*12> grid_hints_up;
    bn::vector<int, 6*12> grid_hints_left;
    bool creator_mode = false;

    PicrossGrid();

    int cellX2Screen();
    int cellY2Screen();

    int getCursorX();
    int getCursorY();

    bool processKeyInput(bn::regular_bg_map_cell&);
    bool processKeyContinuousInput(bn::regular_bg_map_cell&);
    bool processDPadInput();
    bool processDPadContinuousInput(int&);

    bn::array<bool, 144> const &getCurrentGrid();
    void updateHints(bn::array<bool, 144> const &);

    bool checkCurrentCell(bn::array<bool, 144> const &solution);
    bool checkSolution(bn::array<bool, 144> const &);
    void solve();
    void create();

    void resetGrid();
    ~PicrossGrid();
};


#endif // PICROSS_GRID_H
