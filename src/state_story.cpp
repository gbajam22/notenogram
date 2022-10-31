#include "state_story.h"

namespace story
{
    bn::string_view intro[] =
    {
        "Hello! My name's Omi and I'm a regular junior high student. I love playing video games and visiting local arcades.",
        "I've been to this particular arcade so many times I managed to beat almost every game it has.",
        "But today I'm visiting it for a slightly different reason.",
        "See, there's this one arcade machine that I've never paid any attention to until recently.",
        "Notenogram, a puzzle game about solving picture crosswords that mimicked the look of a piece of a notebook paper.",
        "And apparently, I wasn't the only one avoiding this game for so long.",
        "Last time I visited the arcade I heard its owner telling someone they will remove this machine soon due to high maintenance costs.",
        "Plus every time I passed the Notenogram machine, I never saw anyone playing it or simply being near it.",
        "And so I've decided to dedicate today's afterschool hour to playing this game for myself before it goes away.",
        "After all, despite me hearing about picross before, I've never really given it a proper shot, and this looked liked the perfect opportunity to get into it.",
        "Maybe this could be my new arcade favorite, an arcade puzzle classic, a hidden gem?..",
        "And here I am in front of the machine, staring at its dusty screen, not knowing why do I even have to do this.",
        "After a brief tutorial, I selected one of the simpler puzzles Notenogram had to offer to see if I could solve it."
    };

    bn::string_view end_nobisu[] =
    {
        "\"You've obtained rank D!\"",
        "Well, so much for my first attempt. Maybe if I keep playing I could try getting a higher rank...",
        "-\"You're also not good at this, huh...\"",
        "I turned around to find the source of the voice and met face-to-face with a boy in a school uniform of about the same age as me.",
        "Despite being somewhat startled, I instinctively replied with what first came to mind.",
        "\"Yeah, I'm kind of new to this picross solving business. And you..?\"",
        "-\"Same for me! I've been trying to solve picross puzzles from this magazine my grandma has recently subscribed to, but they're just so tough!",
        "-\"They're really big and don't have any fully colored rows and I cannot believe there are people who can solve this kind of stuff.",
        "-\"I'm glad I found this arcade machine, though, I've heard it's really good for those starting out. Plus it has a good extended tutorial mode!",
        "-\"I've been keeping a notebook where I note all the strategy tips the game gives during it, and it helped me a lot!",
        "-\"Not so much with the magazine puzzles, but I'll keep trying and gaining experience and someday I may just be able to solve them in a flash!",
        "..Well, not really in a flash, since I have kind of poor reflexes...\"",
        "The boy was obviously starting to trail off a bit, and I let out a fake suppressed cough to clue him in on this.",
        "-\"Ah, please excuse me for that, I have a really bad habit of rambling in the middle of an unrelated conversation.",
        "-\"If you don't mind me asking, what's your story with Notenogram?\"",
        "\"Oh, I just wanted to experience it for myself before the arcade owners get rid of it.\"",
        "-\"Get rid of it? That's sad to hear. I hope they'll at least replace it with a newer one.\"",
        "\"That would be nice, even though this is my first time playing picross and failing miserably, I think I'm already a big fan.\"",
        "-\"I guess we can only hope for the best now, don't we?\"",
        "\"Well, on the other hand, we could talk to the owner and ask if there is a possibility the game could end up not leaving the arcade.",
        "\"Or we can always look up free-to-play online picross games and cheap puzzle magazines, haha.\"",
        "-\"Yeah! By the way, would you be interested in checking out that magazine I mentioned earlier and maybe even solving some puzzles together?",
        "-\"Like they say, two minds are better than one... or something. My name's Nobisu, by the way.\"",
        "\"Nice to meet you, I'm Omi. And yeah, solving complex puzzles together sounds like a good idea. We could even start our own afterschool picross club.",
        "\"Though I'm not sure if students of different schools can do so...\"",
        "-\"Nah, I think a club would be much better without any ties to school. Plus this could greatly expand our community beyond just junior high students!..",
        "-\"Oh, there's me starting to ramble again.\"",
        "-\"Anyways, would you like to meet up here at the same time tomorrow to play more Notenogram before it disappears?\"",
        "\"You bet! Let's exchange phone numbers so we can contact each other just in case.\"",
        "-\"Sure! Looking forward to our meeting!\"",
        "...I may've not done well at that simple puzzle game, but I managed to gain interest in picross overall, and also befriend a like-minded person.",
        "And to me, that's definitely much better than getting a good rank at any game."
    };

    bn::string_view end_notono[] =
    {
        "\"You've obtained rank B!\"",
        "...Woah, not bad for my first try!",
        "-\"Woah, not bad for your first try!\"",
        "As I wondered how could my thoughts have echoed across the arcade hall, I turned around and noticed a girl standing near me, looking at the screen.",
        "Was she standing there the whole time or..?",
        "\"Thanks, but uh... how did you know it was my first time playing picross?\"",
        "-\"Ah, it's easy. You completely missed a row where you could color pixels by overlapping their supposed placements.",
        "-\"And it's also the first time I see you near this machine.\"",
        "\"Oh. You must have been playing the game for a long time to make such a claim.\"",
        "-\"Well, it's not like I'm playing Notenogram ALL the time, so I can't say for sure if you played this before, but I'm glad my guess was spot on!",
        "-\"How do you like it so far?\"",
        "\"Oh, uh, I've only played one level so far, so I myself can't say for sure if I have any opinion based on just one good rank for one puzzle.",
        "\"Picross as a concept seems pretty interesting, though.\"",
        "-\"Ooh, glad to hear that!\"",
        "\"Why do you ask?\"",
        "-\"You know this machine is about to be removed from this arcade, right?\"",
        "\"Yeah, I've heard of something of this sort recently.\"",
        "-\"I'm trying to persuade the owner of this store to donate it to a video game museum and archive I'm currently volunteering for...",
        "-\"or at least sell it to the nearset larger arcade place.",
        "-\"I really like this and other arcade machines by the same developer and it's sad to see them disappear just like that.",
        "-\"Especially considering those are quite rare to come across nowadays.\"",
        "\"So you help preserving video games? That's cool!\"",
        "-\"I know, right? I especially like hunting for unlabeled video game cartridges and disks, sometimes they can hold a treasure trove of unreleased content.",
        "-\"Oh, this reminds me - if you ever find something video game-related that you don't need, consider donating it to our museum!",
        "-\"We even offer monetary bounties for some of the more obscure findings. Here's my business card in case you'd like to contact me.\"",
        "\"Oh, thanks. I'll be sure to contact you whenever.\"",
        "I accepted the business card from her hands and studied it for a minute before carefully placing it between the copybooks in my bag.",
        "It said \"Notono Ramu, apprentice retro game archivist\".",
        "\"So... Notono-san, right?\"",
        "-\"That's my name! What's yours?\"",
        "\"I'm Omi. Pleasure to meet you.\"",
        "-\"Likewise!\"",
        "\"...I'm curious to know, what kind of games has this developer created?\"",
        "-\"Oh, mostly puzzle games with cute aesthetics, like tile stacking games with super-deformed anime characters...",
        "-\"competitive minesweeper with paper-cutout stop-motion-like 3D graphics... and such.",
        "-\"Though they've also made a fighting game about the characters from a dancing rhythm game that was quite popular.",
        "-\"And I think this arcade has it too, actually!\"",
        "\"You mean Seven's Battle Origins? I love that game! I've completed every fighting team's route there!\"",
        "-\"That's great! Care to play a round of versus mode against me? I'll pay for you as a treat.\"",
        "\"Sounds good, bring it on!\"",
        "...Not only did I gain huge interest in picross puzzles, I also made a new friend, whom I later joined as a video game museum volunteer.",
        "And thanks to a certain obscure picross video game I discovered a wonderful world of video game preservation."

    };

    bn::string_view end_nonogami[] =
    {
        "\"You've obtained rank S! New high score!\"",
        "...Wow. That wasn't what I expected at all.",
        "The brief starter tutorial on picross was enough for me to land on top of the game's leaderboard, just barely passing someone by the name of...",
        "-\"Unbelievable!!\"",
        "The sudden voice caught me off guard and I nearly jumped at the machine.",
        "I quickly turned around and saw a teenager in a varsity jacket standing behind my back and looking in my direction, clearly not liking whatever they saw.",
        "-\"To see someone passing me, THE Picross Master Nonogami, in what may be considered the hardest picross game to master!!..\"",
        "\"Um, it wasn't that hard actually... I mean, I picked one of the easiest levels...\"",
        "The Picross Master Nonogami casted a thorough glance at the screen, which continued showing my name right above theirs on the leaderboard.",
        "-\"...At least you were being honest. I was just checking to see if completing an incredibly easy 12-by-12 puzzle is enough for someone to boast about.",
        "-\"Still, it's a rare sight to see anyone other than me trying to go for a high score on any picross arcade.\"",
        "\"Probably because they're not that popular?..\"",
        "-\"That, too, can be considered a reason for this.\"",
        "\"Well, at the end of the day, I kinda had fun playing this and I want to check out more levels and see if I can beat the high scores for them, too.\"",
        "-\"I like your competitive spirit. Good luck with that.",
        "-\"Just know this - should you stumble across it, you'll never beat my high score for Picross Kingdom DX.",
        "-\"Lots of people tried, none of them succeded.\"",
        "\"Perhaps so, give me a couple of months and maybe I'll prove you wrong.\"",
        "-\"Hmph.\"",
        "\"...\"",
        "-\"Oh, one more thing.\"",
        "Master's voice startled me once more.",
        "-\"I made a mental promise to myself to treat someone who beats any of my picross high scores to a favorite latte of mine.",
        "-\"That doesn't mean that I'm willing to be friends with the person I treat, it's just my token of rivarly appreciation. What do you say?\"",
        "\"Wait, does that mean you've been observing every single person who played this machine... just to make them drink coffee with you?\"",
        "-\"Maybe I did, maybe I didn't. Is wanting to buy someone a freshly-brewn cup of latte a bad thing? Feel free to decline my offer if you wish.\"",
        "\"Ah, no-no-no, do count me in, I like free fancy coffee. Especially with cinnamon rolls.\"",
        "-\"Then I guess you can buy it yourself at the coffee shop, they have a good variety of tasty bakery as well.\"",
        "\"Right... oh, I almost forgot. My name is Omi. Pleased to meet your acquaintance, Master.\"",
        "-\"...Heh. Our future picross battles will sure be legendary, Omi-dono.\"",
        "...And that was how I had gotten myself into competitive picross.",
        "I did eventually beat Master's high score for Picross Kindom DX, but it took me a lot of trial and error.",
        "Still, I'm glad I am now a part of the passionate community around picross, all thanks to the Notenogram machine I happened to play on that faithful day."
    };
}

StoryMode::StoryMode(bn::sprite_text_generator *stg) :
    GameState(),  bg_pattern(buildBG()), map(bg_pattern.map()),
    ending(0),script_ptr(0),symbol_ptr(0),line_ptr(0),
    _text(stg)
{
    resetMap();
    PaperSheetPattern_Scrollable();
    refreshScreen(map);
    _text.redraw(story::intro[0]);
}

int StoryMode::drawIntroText()
{
    _text.output_Typewriter(story::intro[script_ptr], symbol_ptr, line_ptr, 0);
    if (bn::keypad::a_pressed())
    {
        line_ptr = 0;
        symbol_ptr = 0;
        if (++script_ptr >= 13)
        {
            script_ptr = 0;
            return 4;
        }
        _text.redraw(story::intro[script_ptr]);
    }
    return -1;
}

int StoryMode::drawEnd1Text()
{
    _text.output_Typewriter(story::end_nobisu[script_ptr], symbol_ptr, line_ptr, 0);
    if (bn::keypad::a_pressed())
    {
        line_ptr = 0;
        symbol_ptr = 0;
        if (++script_ptr >= 32)
        {
            script_ptr = 0;
            return 0;
        }
        _text.redraw(story::end_nobisu[script_ptr]);
    }
    return -1;
}

int StoryMode::drawEnd2Text()
{
    _text.output_Typewriter(story::end_notono[script_ptr], symbol_ptr, line_ptr, 0);
    if (bn::keypad::a_pressed())
    {
        line_ptr = 0;
        symbol_ptr = 0;
        if (++script_ptr >= 42)
        {
            script_ptr = 0;
            return 0;
        }
        _text.redraw(story::end_notono[script_ptr]);
    }
    return -1;
}

int StoryMode::drawEnd3Text()
{
    _text.output_Typewriter(story::end_nonogami[script_ptr], symbol_ptr, line_ptr, 0);
    if (bn::keypad::a_pressed())
    {
        line_ptr = 0;
        symbol_ptr = 0;
        if (++script_ptr >= 33)
        {
            script_ptr = 0;
            return 0;
        }
        _text.redraw(story::end_nonogami[script_ptr]);
    }
    return -1;
}

void StoryMode::setTextOutputOptions(int rank)
{
    if (rank == 1) ending = 3;
    if (rank > 1 && rank < 5) ending = 2;
    if (rank >= 5) ending = 1;
}

void StoryMode::setOptionalBG()
{
    if (line_ptr == 0 && symbol_ptr == 0)
    {
        if (ending == 1 && script_ptr == 3)
        {
            bg_foreground = bn::regular_bg_items::end_nobisu.create_bg_optional(0,0);
        }
        if (ending == 2 && script_ptr == 2)
        {
            bg_foreground = bn::regular_bg_items::end_notono.create_bg_optional(0,0);
        }
        if (ending == 3 && script_ptr == 4)
        {
            bg_foreground = bn::regular_bg_items::end_nonogami.create_bg_optional(0,0);
        }
    }
}

void StoryMode::eraseOptionalBG()
{
    /*if (ending == 1)
    {
        bg_foreground = bn::regular_bg_items::square.create_bg_optional(0,0);
    }
    if (ending == 2)
    {
        bg_foreground = bn::regular_bg_items::square.create_bg_optional(0,0);
    }
    if (ending == 3)
    {
        bg_foreground = bn::regular_bg_items::square.create_bg_optional(0,0);
    }*/
}

int StoryMode::updateState()
{
    switch (ending)
    {
    case 0:
        return drawIntroText();
        break;
    case 1:
        return drawEnd1Text();
        break;
    case 2:
        return drawEnd2Text();
        break;
    case 3:
        return drawEnd3Text();
        break;
    default:
        return -1;
    }
}

void StoryMode::toggleStateVisibility(bool show)
{
    bg_pattern.set_visible(show);
    _text.clear();
}

void StoryMode::toggleFadeEffect()
{

}


