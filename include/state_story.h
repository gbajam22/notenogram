#ifndef STATE_STORY_H
#define STATE_STORY_H

#include "bn_keypad.h"
#include "state_base.h"
#include "vn_text_output.h"

#include "bn_regular_bg_items_end_nobisu.h"
#include "bn_regular_bg_items_end_notono.h"
#include "bn_regular_bg_items_end_nonogami.h"

class StoryMode : public GameState
{
    bn::regular_bg_ptr bg_pattern;
    bn::optional<bn::regular_bg_ptr> bg_foreground;
    bn::regular_bg_map_ptr map;

    int ending,script_ptr,symbol_ptr,line_ptr;
    bool showing_rank = false;

    text _text;
public:
    StoryMode(bn::sprite_text_generator *stg);
    StoryMode(bn::sprite_text_generator *stg, bool);

    int drawIntroText();
    int drawEnd1Text();
    int drawEnd2Text();
    int drawEnd3Text();
    int drawRankText();

    void setTextOutputOptions(int);
    void setOptionalBG();
    void eraseOptionalBG();

    int updateState();

    void toggleStateVisibility(bool) override;
    void toggleFadeEffect() override;
};

#endif // STATE_STORY_H
