#ifndef STATE_BASE_H
#define STATE_BASE_H

#include "bn_unique_ptr.h"
#include "bn_regular_bg_builder.h"

#include "picross_grid.h"

class GameState
{
    /*static const int columns = 32;
    static const int rows = 32;
    static const int screen_cells = columns*rows;
    bn::fixed bg_x, bg_y;

    bn::bg_palette_item common_palette;
    bn::regular_bg_map_ptr map;
    bn::regular_bg_ptr bg;

    static bn::optional<bn::sprite_ptr> cursor_sprite;

public:

    bn::regular_bg_map_cell cells[screen_cells];
    bn::regular_bg_map_item item;

    GameState();
    GameState(int, int);
    GameState(int, int, bn::bg_palette_item const&);

    bn::regular_bg_ptr buildBG();
    bn::bg_palette_item getCommonPalette();

    void resetMap();
    void refreshScreen();
    void scrollScreen(int, int);

    void PaperSheetPattern_Regular();
    void PaperSheetPattern_Holed();
    void PaperSheetPattern_VScrollable();
    void PaperSheetPattern_HScrollable();
    void PaperSheetPattern_VTorn();*/
};

#endif // STATE_BASE_H
