#ifndef STATE_BASE_H
#define STATE_BASE_H

#include "bn_blending_fade_alpha.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_builder.h"
#include "bn_sprite_builder.h"

#include "picross_grid.h"
#include "picross_solutions.h"
#include "tools.h"

#include "bn_regular_bg_items_square.h"
#include "bn_sprite_items_logo.h"

class GameState
{
    static constexpr int columns = 32;
    static constexpr int rows = 32;
    static constexpr int screen_cells = 32*32;
    int bg_x, bg_y;

    bn::regular_bg_map_cell cells[32*32];
    bn::regular_bg_map_item item;

public:

    GameState();
    GameState(int, int);
    GameState(int, int, bn::bg_palette_item const&);

    bn::regular_bg_ptr buildBG();
    bn::optional<bn::sprite_ptr> buildSprite(const bn::sprite_item &, int, int);
    const bn::bg_palette_item getCommonPalette();

    //void setCellTile(int);
    void setCellTile(int, int, int);

    bn::regular_bg_map_cell& retrieveCell(int, int);

    void resetMap();
    void refreshScreen(bn::regular_bg_map_ptr &);
    void scrollScreen(int, int, bn::regular_bg_ptr &);

    void PaperSheetPattern_Regular();
    void PaperSheetPattern_Holed();
    void PaperSheetPattern_Scrollable();
    void PaperSheetPattern_PuzzleSelection(int&, int&);

    //virtual int updateState() = 0;
    virtual void toggleStateVisibility(bool) = 0;
    virtual void toggleFadeEffect() = 0;

    ~GameState();
};

#endif // STATE_BASE_H
