#include "state_main.h"

MainGame::MainGame(bn::sprite_text_generator *_t) :
    GameState(), bg(buildBG()), map(bg.map()), _text(_t),
    frames2skip(0), offset(0), mistake_made(false), puzzle_solved(false), frame_counter(0),
    cursor_sprite(buildSprite(bn::sprite_items::cursor_pen, 0,0)),
    stamp(buildSprite(bn::sprite_items::stamp, -68,48)),
    notono_window(buildSprite(bn::sprite_items::notonochan, -56, -56)),
    //scribble_left(buildSprite(bn::sprite_items::scribble_star.tiles_item(), -88, 56)),
    scribble_right(buildSprite(bn::sprite_items::scribble_heart, 96, -64))
{
    notono_window->set_visible(false);
    stamp->set_visible(false);

    createPuzzle();
}

MainGame::MainGame(bn::array<bool, 144> const &puzzle_ref) :
    GameState(), bg(buildBG()), map(bg.map()),
    frames2skip(0), offset(0), mistake_made(false), puzzle_solved(false), frame_counter(0),
    cursor_sprite(buildSprite(bn::sprite_items::cursor_pen, 0,0)),
    stamp(buildSprite(bn::sprite_items::stamp, -68,48)),
    notono_window(buildSprite(bn::sprite_items::notonochan, -56, -56)),
    //scribble_left(buildSprite(bn::sprite_items::scribble_star.tiles_item(), -88, 56)),
    scribble_right(buildSprite(bn::sprite_items::scribble_heart, 96, -64))
{
    stamp->set_visible(false);
    solvePuzzle(puzzle_ref);
}

void MainGame::redrawHints()
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (grid.grid_hints_up[6*i+j] > 0)
            {
                setCellTile(13+i, 12-j, grid.grid_hints_up[6*i+j]+3);
            }
            else setCellTile(13+i, 12-j, 1);
        }
    }
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            if (grid.grid_hints_left[6*i+j] > 0)
            {
                setCellTile(12-j, 13+i, grid.grid_hints_left[6*i+j]+3);
            }
            else setCellTile(12-j, 13+i, 1);
        }
    }
}

void MainGame::createPuzzle()
    {
        resetMap();
        PaperSheetPattern_Regular();
        refreshScreen(map);


        setCellTile(11, 11, 4);
        grid.create();
        cursor_sprite->set_position(tool::cellX2Screen(grid.getCursorX(),8), tool::cellY2Screen(grid.getCursorY(),8));
        _text.outputSingleLine(-60, -60, "press start to save!");
        _text.outputSingleLine(-60, -50, "selected slot");
    }

void MainGame::solvePuzzle(bn::array<bool, 144> const &_puzzle)
    {
        resetMap();
        PaperSheetPattern_Regular();
        refreshScreen(map);

        grid.solve();

        grid.updateHints(_puzzle);

        redrawHints();
        refreshScreen(map);

        cursor_sprite->set_position(tool::cellX2Screen(grid.getCursorX(),8), tool::cellY2Screen(grid.getCursorY(),8));
    }

int MainGame::updateState(bn::array<bool, 144> const &current_puzzle)
{
    if (
            !puzzle_solved &&
            ((grid.processDPadContinuousInput(frames2skip) &&
             grid.processKeyContinuousInput(retrieveCell(grid.getCursorX(),
                                                grid.getCursorY()))) ||
             grid.processKeyInput(retrieveCell(grid.getCursorX(),
                                                     grid.getCursorY())))
       )
    {
        if(grid.checkCurrentCell(current_puzzle))
        {
            two_frame_anim[0] = bn::create_sprite_animate_action_forever
                    (*notono_window, 5, bn::sprite_items::notonochan.tiles_item(), 2,3);
            mistake_made = true;
        }
        if(grid.checkSolution(current_puzzle))
        {
            bn::sound_items::yoku_dekimasita.play(1);
            two_frame_anim[0] = bn::create_sprite_animate_action_forever
                    (*notono_window, 5, bn::sprite_items::notonochan.tiles_item(), 4,5);
            puzzle_solved = true;
            if (frame_counter > 0)
            {
                frame_counter = 0;
                mistake_made = false;
            }
        }
        refreshScreen(map);
    }
    for (int i = 0; i < 2; ++i)
    {
        two_frame_anim[i].update();
    }
    if (puzzle_solved)
    {
        if (++frame_counter >= 40)
        {
            if (frame_counter > 200)
                return 0;
            else
            {
                //bn::sound_items::stamp.play(1);
                stamp->set_visible(true);
            }
        }
     }
    if (mistake_made)
    {
        if (++frame_counter >= 60)
        {
            frame_counter = 0;
            two_frame_anim[0] = bn::create_sprite_animate_action_forever
                    (*notono_window, 5, bn::sprite_items::notonochan.tiles_item(), 0,1);
            mistake_made = false;
        }
    }
    if (bn::keypad::select_pressed())
    {
        return 0;
    }
    cursor_sprite->set_position(tool::cellX2Screen(grid.getCursorX(), 8), tool::cellY2Screen(grid.getCursorY(),8));
    return -1;
}

int MainGame::updateState()
{
    if (
            (grid.processDPadContinuousInput(frames2skip) &&
             grid.processKeyContinuousInput(retrieveCell(grid.getCursorX(),
                                                grid.getCursorY()))) ||
             grid.processKeyInput(retrieveCell(grid.getCursorX(),
                                                     grid.getCursorY()))
       )
    {
        grid.updateHints(grid.getCurrentGrid());
        redrawHints();
        refreshScreen(map);
    }
    for (int i = 0; i < 2; ++i)
    {
        two_frame_anim[i].update();
    }
    if (bn::keypad::start_pressed())
    {
        //bn::sram::write_offset(grid.getCurrentGrid(), offset*144);
        tool::boolArray2UInt(grid.getCurrentGrid(), offset*18);
    }
    if (bn::keypad::l_pressed())
    {
        if (offset > 0) --offset;
        setCellTile(11, 11, 4+offset);
        refreshScreen(map);
    }
    else if (bn::keypad::r_pressed())
    {
        if (offset < 2) ++offset;
        setCellTile(11, 11, 4+offset);
        refreshScreen(map);
    }
    if (bn::keypad::select_pressed())
    {
        return 0;
    }
    cursor_sprite->set_position(tool::cellX2Screen(grid.getCursorX(), 8), tool::cellY2Screen(grid.getCursorY(),8));
    return -1;
}
