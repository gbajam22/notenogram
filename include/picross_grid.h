#ifndef PICROSS_GRID_H
#define PICROSS_GRID_H

#include <bn_array.h>
#include <bn_fixed_point.h>
#include "bn_keypad.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_map_cell_info.h"

class PicrossGrid
{
private:
    static bn::array<bn::array<int, 12>, 12> grid;
    static bn::fixed_point cursor;
public:
    PicrossGrid();
    void processKeyInput();
    bool checkSolution();
    void solve();
    ~PicrossGrid();
};


#endif // PICROSS_GRID_H
