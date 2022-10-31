#include "state_main_timed.h"

ArcadeGame::ArcadeGame() : MainGame(puzzle::Story_Mode_Puzzle),
    completion_time(0), time_limit(800), completion_time_delta(0), one_second_frames(0),
            mistake_counter(0), crossed_square_counter(0), longest_coloring_time_delta(0)
{}

ArcadeGame::ArcadeGame(int limit) : MainGame(puzzle::Story_Mode_Puzzle),
    completion_time(0), time_limit(limit), completion_time_delta(0), one_second_frames(0),
            mistake_counter(0), crossed_square_counter(0), longest_coloring_time_delta(0)
{}

int ArcadeGame::GradeCalculator()
{
    int result = 1;

    if (mistake_counter > 0)
    {
        result = mistake_counter < 5 ? result + 2 : result + 3;
    }

    completion_time_delta = time_limit - completion_time;

    if (completion_time_delta <= 0 || completion_time >= time_limit - 100)
    {
        result += 3;
    }
    else if (completion_time_delta <= completion_time && completion_time < time_limit - 100)
    {
        result += 2;
    }
    BN_LOG("RESULTING RANK ", result);
    return result;
}

int ArcadeGame::updateState()
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
        if(grid.checkCurrentCell(puzzle::Story_Mode_Puzzle))
        {
            two_frame_anim[0] = bn::create_sprite_animate_action_forever
                    (*notono_window, 5, bn::sprite_items::notonochan.tiles_item(), 2,3);
            mistake_made = true;
            ++mistake_counter;
            time_limit -= 60;
        }
        if(grid.checkSolution(puzzle::Story_Mode_Puzzle))
        {
            cursor_sprite->set_visible(false);
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
            {
                return GradeCalculator();
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
    if (++one_second_frames >= 60)
    {
        one_second_frames = 0;
        ++completion_time;
        BN_LOG("time ", completion_time);
        BN_LOG("limit ", time_limit);
        BN_LOG("mistakes ", mistake_counter);
    }
    cursor_sprite->set_position(tool::cellX2Screen(grid.getCursorX(), 8), tool::cellY2Screen(grid.getCursorY(),8));
    return -1;
}
