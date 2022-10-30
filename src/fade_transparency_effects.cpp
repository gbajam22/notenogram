#include "fade_transparency_effects.h"

namespace fx
{
    bn::blending_transparency_alpha_loop_action logo_action(30, 1);

    void introLogoFade(int & frames)
    {
        if (frames < 30 || (frames >= 170 && frames < 200))
        {
            fx::logo_action.update();
        }
    }
    void simpleFade(int& frames, bool fading_out)
    {
        bn::blending_fade_alpha_loop_action fade_action(30, fading_out ? 0 : 1);
        while (++frames <= 30)
        {
            fade_action.update();
            bn::core::update();
        }
        frames = 0;
    }
    void hBlankFade(int& frames, bool fading_out)
    {
        /*int stripe_counter = 0;
        bn::array<bn::blending_fade_alpha, 160> fade_alphas;

        for (int i = 0; i < 160; ++i)
        {
            fade_alphas[i].set_value(fading_out ? 0 : 1);
        }

        bn::blending_fade_alpha_hbe_ptr fade_alphas_hbe =
                bn::blending_fade_alpha_hbe_ptr::create(fade_alphas);

        //bn::blending_fade_alpha_loop_action fade_action(60, !fading_out);
        while (frames <= 60)
        {
            for(int index = 0, amplitude = 160 / 2; index < amplitude; ++index)
            {
                bn::fixed fade_alpha = bn::fixed(index) / amplitude;
                fade_alphas[(160 / 2) + index].set_value(fade_alpha);
                fade_alphas[(160 / 2) - index - 1].set_value(fade_alpha);
            }

            bn::core::update();
        }*/
    }
}
