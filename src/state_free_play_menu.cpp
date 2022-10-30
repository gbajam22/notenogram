#include "state_free_play_menu.h"

PuzzleSelect::PuzzleSelect(bn::sprite_text_generator* stg) :
    GameState(), bg(buildBG()), map(bg.map()), _text(stg),
    menu_hrz_lower_limit(15), menu_hrz_upper_limit(19), menu_vrt_lower_limit(13), menu_vrt_upper_limit(19),
    cursor_sprite(buildSprite(bn::sprite_items::cursor_circle, 0,0)),
    scribble_left(buildSprite(bn::sprite_items::scribble_star, -68, -40))
{
    bg.set_blending_enabled(true);
    scribble_left->set_blending_enabled(true);
    cursor_sprite->set_blending_enabled(true);

    //bn::blending::set_fade_alpha(1);

    slots_occupied[0] = tool::validateSRAM_UInt_Data(0);
    BN_LOG("slot 0 data valid: ", slots_occupied[0]);

    slots_occupied[1] = tool::validateSRAM_UInt_Data(18);
    BN_LOG("slot 1 data valid: ", slots_occupied[1]);

    slots_occupied[2] = tool::validateSRAM_UInt_Data(36);
    BN_LOG("slot 2 data valid: ", slots_occupied[2]);
    showMenu();
}

void PuzzleSelect::showMenu()
{
    if (slots_occupied[0] || slots_occupied[1] || slots_occupied[2])
    {
        menu_vrt_upper_limit += 2;
    }

    resetMap();
    PaperSheetPattern_PuzzleSelection(menu_vrt_lower_limit, menu_vrt_upper_limit);
    refreshScreen(map);

    showMenuText();

}

void PuzzleSelect::showMenuText()
{
    _text.clear();

    _text.outputSingleLine(tool::cellX2Screen(9, 4), tool::cellY2Screen(10, 4), "Choose a puzzle");

    _text.outputSingleLine(tool::cellX2Screen(6, 4), tool::cellY2Screen(13, 4), "things");
    _text.outputSingleLine(tool::cellX2Screen(6, 4), tool::cellY2Screen(15, 4), "nature");
    _text.outputSingleLine(tool::cellX2Screen(6, 4), tool::cellY2Screen(17, 4), "kanji");
    _text.outputSingleLine(tool::cellX2Screen(6, 4), tool::cellY2Screen(19, 4), "portraits");

    if (slots_occupied[0] || slots_occupied[1] || slots_occupied[2])
    {
        _text.outputSingleLine(tool::cellX2Screen(6, 4), tool::cellY2Screen(21, 4), "custom");
    }
}


bn::array<bool, 144> const& PuzzleSelect::getSelectedPuzzle()
{
    bn::sound_items::ganbatte_ne.play(1);
    switch(cursor_position[1])
    {
        case 13:
            switch(cursor_position[0])
            {
                case 15:
                    return puzzle::Things_Gameboy;
                case 17:
                    return puzzle::Things_Giftbox;
                case 19:
                    return puzzle::Things_Notepad;
                default:
                    break;
            }
            break;
        case 15:
            switch(cursor_position[0])
            {
                case 15:
                    return puzzle::Nature_4LClover;
                case 17:
                    return puzzle::Nature_Flower;
                case 19:
                    return puzzle::Nature_Lagomorph;
                default:
                    break;
            }
            break;
        case 17:
            switch(cursor_position[0])
            {
                case 15:
                    return puzzle::Kanji_Cat;
                case 17:
                    return puzzle::Kanji_Congrats;
                case 19:
                    return puzzle::Kanji_Flower;
                default:
                    break;
            }
            break;
        case 19:
            switch(cursor_position[0])
            {
                case 15:
                    return puzzle::Portrait_Nyra;
                case 17:
                    return puzzle::Portrait_Tooru;
                case 19:
                    return puzzle::Portrait_Yuuji;
                default:
                    break;
            }
            break;
        case 21:
            switch(cursor_position[0])
            {
                case 15:
                    if (slots_occupied[0] == true)
                    {
                        tool::UInt2BoolArray(puzzle::Custom, 0);
                        //bn::sram::read_offset(puzzle::Custom, 0);
                        return puzzle::Custom;
                    }
                case 17:
                    if (slots_occupied[1] == true)
                    {
                        tool::UInt2BoolArray(puzzle::Custom, 18);
                        //bn::sram::read_offset(puzzle::Custom, 0x90);
                        return puzzle::Custom;
                    }
                case 19:
                    if (slots_occupied[2] == true)
                    {
                        tool::UInt2BoolArray(puzzle::Custom, 36);
                        //bn::sram::read_offset(puzzle::Custom, 0x120);
                        return puzzle::Custom;
                    }
                default:
                    break;
            }
            break;
        default:
            break;
        }
}

int PuzzleSelect::updateState()
{
    if (bn::keypad::down_pressed() && cursor_position[1] < menu_vrt_upper_limit)
    {
        cursor_position[1]+=2;
    }
    else if (bn::keypad::up_pressed() && cursor_position[1] > menu_vrt_lower_limit)
    {
        cursor_position[1]-=2;
    }
    if (bn::keypad::right_pressed() && cursor_position[0] < menu_hrz_upper_limit)
    {
        cursor_position[0]+=2;
    }
    else if (bn::keypad::left_pressed() && cursor_position[0] > menu_hrz_lower_limit)
    {
        cursor_position[0]-=2;
    }

    if (bn::keypad::a_pressed())
    {
        if (cursor_position[1] == 21 &&
                ((cursor_position[0] == 15 && !slots_occupied[0]) ||
                (cursor_position[0] == 17 && !slots_occupied[1]) ||
                (cursor_position[0] == 19 && !slots_occupied[2])))
        {
            _text.outputSingleLine(tool::cellX2Screen(11, 4), tool::cellY2Screen(23, 4), "no puzzle found!");
            empty_selection = true;
            return -1;
        }
        return 4;
    }
    else if (bn::keypad::b_pressed())
    {
        return 0;
    }
    two_frame_anim.update();
    cursor_sprite->set_position(tool::cellX2Screen(cursor_position[0], 8), tool::cellY2Screen(cursor_position[1],8));

    if (empty_selection && ++frame_counter >= 100)
    {
        empty_selection = false;
        frame_counter = 0;
        showMenuText();
    }

    return -1;
}

void PuzzleSelect::toggleStateVisibility(bool show)
{
    bg.set_visible(show);
    cursor_sprite->set_visible(show);
    scribble_left->set_visible(show);
    if (!show) _text.clear();
    else showMenuText();
}

void PuzzleSelect::toggleFadeEffect()
{

}
