#ifndef FADE_TRANSPARENCY_EFFECTS_H
#define FADE_TRANSPARENCY_EFFECTS_H

#include "bn_array.h"
#include "bn_blending_actions.h"
#include "bn_blending_fade_alpha.h"
#include "bn_blending_fade_alpha_hbe_ptr.h"
#include "bn_blending_transparency_attributes.h"
#include "bn_blending_transparency_attributes_hbe_ptr.h"
#include "bn_core.h"

namespace fx
{
    void introLogoFade(int&);
    void simpleFade(int&, bool);
    void hBlankFade(int&, bool);
}

#endif // FADE_TRANSPARENCY_EFFECTS_H
