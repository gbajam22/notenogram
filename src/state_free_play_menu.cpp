#include "state_free_play_menu.h"

PuzzleSelect::PuzzleSelect(bn::sprite_text_generator* stg) :
    GameState(), bg(buildBG()), map(bg.map()), _text(stg),
    menu_hrz_lower_limit(15), menu_hrz_upper_limit(19), menu_vrt_lower_limit(13), menu_vrt_upper_limit(19),
    cursor_sprite(buildSprite(bn::sprite_items::cursor_circle, 0,0)),
    scribble_left(buildSprite(bn::sprite_items::scribble_star, -96, -64))
{
    slots_occupied[0] = tool::validateSRAMData(0x00);
    slots_occupied[1] = tool::validateSRAMData(0x90);
    slots_occupied[2] = tool::validateSRAMData(0x120);
    showMenu();
}

/*PuzzleSelect::PuzzleSelect(int x, int y, bn::sprite_text_generator* stg) :
    GameState(x,y) , bg(buildBG()), map(bg.map()), _text(stg),
    menu_hrz_lower_limit(15), menu_hrz_upper_limit(19), menu_vrt_lower_limit(13), menu_vrt_upper_limit(19),
    cursor_sprite(bn::sprite_items::cursor_circle.create_sprite_optional(0,0)),
    scribble_left(bn::sprite_items::scribble_heart.create_sprite_optional(0,0))
{
    slots_occupied[0] = tool::validateSRAMData(0x00);
    slots_occupied[1] = tool::validateSRAMData(0x90);
    slots_occupied[2] = tool::validateSRAMData(0x120);
}

PuzzleSelect::PuzzleSelect(int x, int y, bn::bg_palette_item const& palette, bn::sprite_text_generator* stg) :
    GameState(x,y,palette) , bg(buildBG()), map(bg.map()), _text(stg),
    menu_hrz_lower_limit(15), menu_hrz_upper_limit(19), menu_vrt_lower_limit(13), menu_vrt_upper_limit(19),
    cursor_sprite(bn::sprite_items::cursor_circle.create_sprite_optional(0,0)),
    scribble_left(bn::sprite_items::scribble_heart.create_sprite_optional(0,0))
{
    slots_occupied[0] = tool::validateSRAMData(0x00);
    slots_occupied[1] = tool::validateSRAMData(0x90);
    slots_occupied[2] = tool::validateSRAMData(0x120);
}*/

void PuzzleSelect::showMenu()
{
    resetMap();
    PaperSheetPattern_PuzzleSelection(menu_vrt_lower_limit, menu_vrt_upper_limit);
    refreshScreen(map);

    _text.outputSingleLine(tool::cellX2Screen(9, 4), tool::cellY2Screen(10, 4), "Choose a puzzle");

    _text.outputSingleLine(tool::cellX2Screen(6, 4), tool::cellY2Screen(13, 4), "things");
    _text.outputSingleLine(tool::cellX2Screen(6, 4), tool::cellY2Screen(15, 4), "nature");
    _text.outputSingleLine(tool::cellX2Screen(6, 4), tool::cellY2Screen(17, 4), "kanji");
    _text.outputSingleLine(tool::cellX2Screen(6, 4), tool::cellY2Screen(19, 4), "portraits");

    if (slots_occupied[0] || slots_occupied[1] || slots_occupied[2])
    {
        menu_vrt_upper_limit += 2;
        _text.outputSingleLine(tool::cellX2Screen(6, 4), tool::cellY2Screen(21, 4), "custom");
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
        switch(cursor_position[1])
        {
            case 13:
                switch(cursor_position[0])
                {
                    case 15:
                        current_puzzle = puzzle::Things_Gameboy;
                        return 4;
                    case 17:
                        current_puzzle = puzzle::Things_Giftbox;
                        return 4;
                    case 19:
                        current_puzzle = puzzle::Things_Notepad;
                        return 4;
                    default:
                        break;
                }
                break;
            case 15:
                switch(cursor_position[0])
                {
                    case 15:
                        current_puzzle = puzzle::Nature_4LClover;
                        return 4;
                    case 17:
                        current_puzzle = puzzle::Nature_Flower;
                        return 4;
                    case 19:
                        current_puzzle = puzzle::Nature_Lagomorph;
                        return 4;
                    default:
                        break;
                }
                break;
            case 17:
                switch(cursor_position[0])
                {
                    case 15:
                        current_puzzle = puzzle::Kanji_Cat;
                        return 4;
                    case 17:
                        current_puzzle = puzzle::Kanji_Congrats;
                        return 4;
                    case 19:
                        current_puzzle = puzzle::Kanji_Flower;
                        return 4;
                    default:
                        break;
                }
                break;
            case 19:
                switch(cursor_position[0])
                {
                    case 15:
                        current_puzzle = puzzle::Portrait_Nyra;
                        return 4;
                    case 17:
                        current_puzzle = puzzle::Portrait_Tooru;
                        return 4;
                    case 19:
                        current_puzzle = puzzle::Portrait_Yuuji;
                        return 4;
                    default:
                        break;
                }
                break;
            case 21:
                switch(cursor_position[0])
                {
                    case 15:
                        if (slots_occupied[0])
                        {
                            bn::sram::read_offset(puzzle::Custom, 0);
                            current_puzzle = puzzle::Custom;
                            return 4;
                        }
                    case 17:
                        if (slots_occupied[1])
                        {
                            bn::sram::read_offset(puzzle::Custom, 0x90);
                            current_puzzle = puzzle::Custom;
                            return 4;
                        }
                    case 19:
                        if (slots_occupied[2])
                        {
                            bn::sram::read_offset(puzzle::Custom, 0x120);
                            current_puzzle = puzzle::Custom;
                            return 4;
                        }
                    default:
                        break;
                }
                break;
            default:
                break;
            }
    }
    else if (bn::keypad::b_pressed())
    {
        return 0;
    }
    return -1;
}
