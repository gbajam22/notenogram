#include "game_loop.h"
namespace loop
{

    void solve_puzzle(bn::array<bool, 144> const& puzzle)
    {
        MainGame _actual_picross(puzzle);
        while (_actual_picross.updateState(puzzle) != 0)
        {
            bn::core::update();
        }
    }

    void select_puzzle(bn::sprite_text_generator* _t)
    {
        PuzzleSelect _puzzle_select(_t);
        int option = 1;
        while (option != 0)
        {
            option = _puzzle_select.updateState();
            if(option == 4)
            {
                solve_puzzle(_puzzle_select.getSelectedPuzzle());
            }
            bn::core::update();
        }
    }

    void make_puzzle(bn::sprite_text_generator* _t)
    {
        MainGame _actual_picross(_t);
        while (_actual_picross.updateState() != 0)
        {
            bn::core::update();
        }
    }

    void menu(bn::sprite_text_generator* _t)
    {
        MainMenu _menu(_t);
        while (1)
        {
            switch(_menu.updateState())
            {
            case 1:
                select_puzzle(_t);
                break;
            case 2:
                make_puzzle(_t);
                break;
            default:
                break;

            }
            bn::core::update();
        }
    }
}
