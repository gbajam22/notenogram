#ifndef STATE_MAIN_TIMED_H
#define STATE_MAIN_TIMED_H

#include "state_main.h"
#include "bn_log.h"

class ArcadeGame : public MainGame
{
    int completion_time, time_limit, completion_time_delta,
        mistake_counter, crossed_square_counter, longest_coloring_time_delta;
    int one_second_frames;
public:
    ArcadeGame();
    ArcadeGame(int);
    int GradeCalculator();
    int updateState();
};

#endif // STATE_MAIN_TIMED_H
