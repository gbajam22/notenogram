#include "state_start_menu.h"

MainMenu::MainMenu(bn::sprite_text_generator* stg) : GameState(), bg_pattern(buildBG()), map(bg_pattern.map()),
    _text(stg), displaying_logo1(true), displaying_logo2(false),displaying_credits(false), returning_from_state(false),
    bg_foreground(bn::regular_bg_items::title.create_bg(-22, 15)),
    cursor_sprite(buildSprite(bn::sprite_items::cursor_pen,0,0)),
    logo(buildSprite(bn::sprite_items::logo,0,0)), logo_appear_action(60, 1), logo_disappear_action(60, 0)
{
    bg_foreground.set_visible(false);
    cursor_sprite->set_horizontal_flip(true);
    cursor_sprite->set_vertical_flip(true);
    cursor_sprite->set_visible(false);
    initScrollingBG();
    bg_pattern.set_blending_enabled(false);
    bg_foreground.set_blending_enabled(false);
    logo->set_blending_enabled(true);
    bn::blending::set_transparency_alpha(0);
}

void MainMenu::displayIntro()
{
    if (refresh_counter < 60)
    {
        logo_appear_action.update();
    }
    else if (refresh_counter > 160 && refresh_counter < 220)
    {
        logo_disappear_action.update();
    }
    else
    {
        bn::blending::set_transparency_alpha(1);
    }
}

void MainMenu::initScrollingBG()
{
    resetMap();
    PaperSheetPattern_Scrollable();
    refreshScreen(map);
}

void MainMenu::displayMainMenu()
{
    bg_foreground.set_visible(true);
    cursor_sprite->set_visible(true);

    _text.outputSingleLine(42, -60, "notenogram");
    _text.outputSingleLine(57, 20, "play");
    _text.outputSingleLine(57, 36, "create");
    _text.outputSingleLine(57, 52, "credits");
}

void MainMenu::displayCredits()
{
    if (displaying_credits)
        _text.output_Typewriter(credits[script_ptr], symbol_ptr, line_ptr, 0);
    if (bn::keypad::a_pressed())
        {
            if (++script_ptr == credits->length())
            {
                displaying_credits = false;
            }
        }
        if (bn::keypad::start_pressed())
        {
            displaying_credits = false;
        }
}

int MainMenu::updateState()
{
    if (!displaying_logo1 && !displaying_logo2)
    {
        if (bn::keypad::down_pressed())
        {
            cursor_position[1] = cursor_position[1] >= upper_bound ? lower_bound : cursor_position[1] + 16;
        }
        else if (bn::keypad::up_pressed())
        {
            cursor_position[1] = cursor_position[1] <= lower_bound ? upper_bound : cursor_position[1] - 16;
        }
        if (bn::keypad::a_pressed())
        {
            switch(cursor_position[1])
            {
                case 20:
                toggleStateVisibility(false);
                    return 1;
                    break;
                case 36:
                toggleStateVisibility(false);
                    return 2;
                    break;
                case 42:
                toggleStateVisibility(false);
                    return 3;
                    break;
                default: break;
            }
        }
        cursor_sprite->set_position(cursor_position[0], cursor_position[1]);
    }
    else
    {
        if (refresh_counter < 220)
        displayIntro();
        if (++refresh_counter > 220)
        {
            refresh_counter = 0;
            if (!displaying_logo1 && displaying_logo2)
            {
                logo->set_visible(false);
                displaying_logo2 = false;
                bn::sound_items::nootonoguramu.play();
                displayMainMenu();
            }
            else
            {
                logo = buildSprite(bn::sprite_items::logo_butano,0,0);
                logo->set_blending_enabled(true);
                bn::blending::set_transparency_alpha(0);
                displaying_logo1 = false;
                displaying_logo2 = true;
            }
        }
    }
    bg_pattern.set_x(bg_pattern.x()+0.25);
    bg_pattern.set_y(bg_pattern.y()+0.25);
    //bg_pattern.set_position()
    //scrollScreen(0.25, 0.25, bg_pattern);
    return -1;
}

void MainMenu::toggleStateVisibility(bool show)
{
    bg_pattern.set_visible(show);
    bg_foreground.set_visible(show);
    cursor_sprite->set_visible(show);
    if (!show) _text.clear();
    else displayMainMenu();
}
