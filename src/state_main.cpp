#include "state_main.h"

MainGame::MainGame() :
    GameState(), bg(buildBG()), map(bg.map()), //current_puzzle(puzzle_ref),
    frames2skip(0), offset(0), mistake_made(false), puzzle_solved(false), mistake_frame_counter(0),
    cursor_sprite(buildSprite(bn::sprite_items::cursor_pen, 0,0)),
    stamp(buildSprite(bn::sprite_items::stamp, -88,48)),
    notono_window(buildSprite(bn::sprite_items::notonochan, -56, -56)),
    //scribble_left(buildSprite(bn::sprite_items::scribble_star.tiles_item(), -88, 56)),
    scribble_right(buildSprite(bn::sprite_items::scribble_heart, 96, -64))
{
    notono_window->set_visible(false);
    stamp->set_visible(false);
    createPuzzle();
}

MainGame::MainGame(bn::array<bool, 144> &puzzle_ref) :
    GameState(), bg(buildBG()), map(bg.map()), //current_puzzle(puzzle_ref),
    frames2skip(0), offset(0), mistake_made(false), puzzle_solved(false), mistake_frame_counter(0),
    cursor_sprite(buildSprite(bn::sprite_items::cursor_pen, 0,0)),
    stamp(buildSprite(bn::sprite_items::stamp, -88,48)),
    notono_window(buildSprite(bn::sprite_items::notonochan, -56, -56)),
    //scribble_left(buildSprite(bn::sprite_items::scribble_star.tiles_item(), -88, 56)),
    scribble_right(buildSprite(bn::sprite_items::scribble_heart, 96, -64))
{
    stamp->set_visible(false);
    current_puzzle = puzzle_ref;
    solvePuzzle();
}

/*MainGame::MainGame(int x, int y, bn::array<bool, 144> &puzzle_ref) :
    GameState(x,y), bg(buildBG()), map(bg.map()), //current_puzzle(puzzle_ref),
    frames2skip(0), offset(0), mistake_made(false), puzzle_solved(false), mistake_frame_counter(0),
    cursor_sprite(bn::sprite_items::cursor_pen.create_sprite_optional(0,0)),
    stamp(bn::sprite_items::stamp.create_sprite_optional(88,48)),
    notono_window(bn::sprite_items::notonochan.create_sprite_optional(-56, -56)),
    scribble_left(bn::sprite_items::scribble_star.create_sprite_optional(-88, 56)),
    scribble_right(bn::sprite_items::scribble_heart.create_sprite_optional(96, -64))
{
    stamp->set_visible(false);
    current_puzzle = puzzle_ref;
}


MainGame::MainGame(int x, int y, bn::bg_palette_item const& palette, bn::array<bool, 144> &puzzle_ref) :
    GameState(x,y,palette) , bg(buildBG()), map(bg.map()), //current_puzzle(puzzle_ref),
    frames2skip(0), offset(0), mistake_made(false), puzzle_solved(false), mistake_frame_counter(0),
    cursor_sprite(bn::sprite_items::cursor_pen.create_sprite_optional(0,0)),
    stamp(bn::sprite_items::stamp.create_sprite_optional(88,48)),
    notono_window(bn::sprite_items::notonochan.create_sprite_optional(-56, -56)),
    scribble_left(bn::sprite_items::scribble_star.create_sprite_optional(-88, 56)),
    scribble_right(bn::sprite_items::scribble_heart.create_sprite_optional(96, -64))
{
    stamp->set_visible(false);
    current_puzzle = puzzle_ref;
}*/


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

        grid.create();
        cursor_sprite->set_position(tool::cellX2Screen(grid.getCursorX(),8), tool::cellY2Screen(grid.getCursorY(),8));
    }

void MainGame::solvePuzzle()
    {
        resetMap();
        PaperSheetPattern_Regular();
        refreshScreen(map);

        grid.solve();

        grid.updateHints(current_puzzle);

        redrawHints();
        refreshScreen(map);

        cursor_sprite->set_position(tool::cellX2Screen(grid.getCursorX(),8), tool::cellY2Screen(grid.getCursorY(),8));

        /*notono_window->set_position(-56, -56);
        scribble_left->set_position(-88, 56);
        scribble_right->set_position(96, -64);*/
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
        if (grid.creator_mode)
        {
            grid.updateHints(grid.getCurrentGrid());

            redrawHints();
        }
        else
        {
            if(grid.checkCurrentCell(current_puzzle))
            {
                two_frame_anim[0] = bn::create_sprite_animate_action_forever
                        (*notono_window, 5, bn::sprite_items::notonochan.tiles_item(), 2,3);
                mistake_made = true;
            }
            if(grid.checkSolution(current_puzzle))
            {
                bn::sound_items::yoku_dekimasita.play(0.6);
                two_frame_anim[0] = bn::create_sprite_animate_action_forever
                        (*notono_window, 5, bn::sprite_items::notonochan.tiles_item(), 4,5);
                stamp->set_visible(true);
            }
        }
        refreshScreen(map);
    }
    for (int i = 0; i < 3; ++i)
    {
        two_frame_anim[i].update();
    }
    if (grid.creator_mode)
    {
        if (bn::keypad::start_pressed())
        {
            bn::sram::write_offset(grid.getCurrentGrid(), offset);
        }
        if (bn::keypad::l_pressed())
        {
            offset = offset < 0 ? 288 : offset - 144;
            setCellTile(11, 11, 3+offset/144);
        }
        else if (bn::keypad::r_pressed())
        {
            offset = offset > 288 ? 0 : offset + 144;
            setCellTile(11, 11, 3+offset/144);
        }
    }
    else
    {
        if (mistake_made)
        {
            if (++mistake_frame_counter >= 60)
            {
                mistake_frame_counter = 0;
                two_frame_anim[0] = bn::create_sprite_animate_action_forever
                        (*notono_window, 5, bn::sprite_items::notonochan.tiles_item(), 0,1);
                mistake_made = false;
            }
        }
    }
    if (bn::keypad::select_pressed())
    {
        return 0;
    }
    cursor_sprite->set_position(tool::cellX2Screen(grid.getCursorX(), 8), tool::cellY2Screen(grid.getCursorY(),8));
}
