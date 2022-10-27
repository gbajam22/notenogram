#include "state_start_menu.h"

MainMenu::MainMenu(bn::sprite_text_generator* stg) : GameState(), bg_pattern(buildBG()), map(bg_pattern.map()),
    _text(stg), displaying_logo1(true), displaying_logo2(false), displaying_credits(false), returning_from_state(false),
    bg_foreground(bn::regular_bg_items::title.create_bg(-22, 15)),
    cursor_sprite(buildSprite(bn::sprite_items::cursor_pen,0,0)),
    logo(buildSprite(bn::sprite_items::logo_butano,0,0))
{
    //bg_foreground.set_visible(false);
    //cursor_sprite->set_visible(false);
    initScrollingBG();
    //bg_pattern.set_blending_enabled(false);
    //bg_foreground.set_blending_enabled(false);
    //logo->set_blending_enabled(true);
    //bn::blending::set_transparency_alpha(logo_visibility);
    //menu();
    cursor_sprite->set_horizontal_flip(true);
    logo->set_visible(true);
    displayMainMenu();
}

void MainMenu::displaySplashLogos()
{
    if (displaying_logo1 || displaying_logo2)
    {
        bn::blending::set_transparency_alpha(logo_visibility);
        ++refresh_counter;
        if (logo_visibility == 1 && refresh_counter == 100)
        {
            logo_visibility = logo_visibility > 1 ? 1 : logo_visibility + 0.05;
        }
        if (logo_visibility < 1)
        {
            if (logo_visibility == 0 && refresh_counter > 100)
            {
                displaying_logo2 = displaying_logo1;
                displaying_logo1 = false;
                refresh_counter = 0;
            }
            logo_visibility = logo_visibility < 0 ? 0 : logo_visibility - 0.05;
        }
    }
    if (!displaying_logo1 && displaying_logo2)
    {
        logo = buildSprite(bn::sprite_items::logo_butano,0,0);
    }
    if (!displaying_logo1 && !displaying_logo2)
    {
        displayMainMenu();
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
    logo->set_visible(false);

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
    //if (!displaying_logo1 && !displaying_logo2)
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
                    return 1;
                    break;
                case 36:
                    return 2;
                    break;
                case 42:
                    return 3;
                    break;
                default: break;
            }
        }
        cursor_sprite->set_position(cursor_position[0], cursor_position[1]);
    }
    bg_pattern.set_x(bg_pattern.x()+0.25);
    bg_pattern.set_y(bg_pattern.y()+0.25);
    //bg_pattern.set_position()
    //scrollScreen(0.25, 0.25, bg_pattern);
    return -1;
}

int MainMenu::menu()
{
    if (!returning_from_state)
    {
        displaySplashLogos();
    }
    else
    {
        displayMainMenu();
    };
}
