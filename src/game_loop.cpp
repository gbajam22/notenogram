#include "game_loop.h"
namespace loop
{
    void solve_puzzle(bn::array<bool, 144> const& puzzle)
    {
        MainGame _actual_picross(puzzle);
        bn::core::update();
        while (_actual_picross.updateState(puzzle) != 0)
        {
            bn::core::update();
        }
    }

    int solve_arcade_puzzle()
    {
        ArcadeGame _story_picross;
        bn::core::update();
        int result = -1;
        while (result == -1)
        {
            result = _story_picross.updateState();
            bn::core::update();
        }
        return result;
    }

    void select_puzzle(bn::sprite_text_generator* _t)
    {
        PuzzleSelect _puzzle_select(_t);
        int option = 1;
        bn::core::update();
        while (option != 0)
        {
            option = _puzzle_select.updateState();
            if(option == 4)
            {
                _puzzle_select.toggleStateVisibility(false);
                solve_puzzle(_puzzle_select.getSelectedPuzzle());
                _puzzle_select.toggleStateVisibility(true);
            }
            bn::core::update();
        }
    }

    void make_puzzle(bn::sprite_text_generator* _t)
    {
        MainGame _actual_picross(_t);
        bn::core::update();
        while (_actual_picross.updateState() != 0)
        {
            bn::core::update();
        }
    }

    void init_story_mode(bn::sprite_text_generator* _t)
    {
        StoryMode _story_mode(_t);
        bn::core::update();
        int option = 1;
        while (option != 0)
        {
            _story_mode.setOptionalBG();
            option = _story_mode.updateState();
            if(option == 4)
            {
                _story_mode.toggleStateVisibility(false);
                _story_mode.setTextOutputOptions(solve_arcade_puzzle());
                _story_mode.toggleStateVisibility(true);
            }
            bn::core::update();
        }
    }

    void menu(bn::sprite_text_generator* _t)
    {
        MainMenu _menu(_t);
        while (1)
        {
            if (_menu.returning_from_state)
            {
                _menu.toggleStateVisibility(true);
                _menu.returning_from_state = false;
            }

            if (_menu.displaying_logo1 || _menu.displaying_logo2)
            {
                fx::introLogoFade(_menu.refresh_counter);
            }

            switch(_menu.updateState())
                {
                case 1:
                    _menu.returning_from_state = true;
                    select_puzzle(_t);
                    break;
                case 2:
                    _menu.returning_from_state = true;
                    make_puzzle(_t);
                    break;
                case 3:
                    _menu.displaying_credits = true;
                    break;
                case 5:
                    _menu.returning_from_state = true;
                    init_story_mode(_t);
                    break;
                default:
                    break;
                }
            bn::core::update();
        }
    }
}
