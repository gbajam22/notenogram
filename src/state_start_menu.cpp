#include "state_start_menu.h"

MainMenu::MainMenu(bn::sprite_text_generator* stg) : GameState(), bg_pattern(buildBG()), map(bg_pattern.map()),
    _text(stg), displaying_logo1(true), displaying_logo2(false),displaying_credits(false), returning_from_state(false),
    cursor_sprite(buildSprite(bn::sprite_items::cursor_pen,0,0)),
    logo(buildSprite(bn::sprite_items::logo,0,0)),
    bg_foreground(bn::regular_bg_items::title.create_bg(-20, 15)),
    script_ptr(0), line_ptr(0), symbol_ptr(0)
{
    bg_foreground.set_visible(false);
    cursor_sprite->set_horizontal_flip(true);
    cursor_sprite->set_vertical_flip(true);
    cursor_sprite->set_visible(false);
    initScrollingBG();
    bg_pattern.set_blending_enabled(false);
    bg_foreground.set_blending_enabled(false);
    cursor_sprite->set_blending_enabled(false);
    logo->set_blending_enabled(true);
    bn::blending::set_transparency_alpha(0);
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
    _text.output_Typewriter(credits[script_ptr], symbol_ptr, line_ptr, 0);
    if (bn::keypad::a_pressed())
    {
        if (++script_ptr >= 7)
        {
            script_ptr = 0;
        }
        line_ptr = 0;
        symbol_ptr = 0;
        _text.redraw(credits[script_ptr]);
    }
    if (bn::keypad::b_pressed())
    {
        displaying_credits = false;
        logo->set_visible(false);
        _text.clear();
        toggleStateVisibility(true);
        script_ptr = 0;
        line_ptr = 0;
        symbol_ptr = 0;
    }
}

int MainMenu::updateState()
{
    if (!displaying_credits)
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
                case 52:
                displaying_credits = true;
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
        if (bn::keypad::any_pressed())
        {
            displaying_logo1 = false;
            displaying_logo2 = true;
            refresh_counter = 200;
        }
        if (++refresh_counter >= 200)
        {
            refresh_counter = 0;
            if (!displaying_logo1 && displaying_logo2)
            {
                displaying_logo2 = false;
                bn::blending::set_transparency_alpha(1);
                logo->set_visible(false);
                logo->set_blending_enabled(false);
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
    }}
    else
    {
        logo = buildSprite(bn::sprite_items::scribble_star, 80, 10);
        //logo->set_visible(true);
        displayCredits();
    }
    bg_pattern.set_x(bg_pattern.x()+0.25);
    bg_pattern.set_y(bg_pattern.y()+0.25);
    return -1;
}

void MainMenu::toggleStateVisibility(bool show)
{
    if (!displaying_credits) bg_pattern.set_visible(show);
    else _text.redraw(credits[0]);
    bg_foreground.set_visible(show);
    cursor_sprite->set_visible(show);
    if (!show) _text.clear();
    else displayMainMenu();
}

void MainMenu::toggleFadeEffect()
{
    logo = buildSprite(bn::sprite_items::logo_butano,0,0);
    displaying_logo1 = false;
    displaying_logo2 = true;
}
