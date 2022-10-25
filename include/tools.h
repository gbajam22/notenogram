#ifndef TOOLS_H
#define TOOLS_H

#include "bn_array.h"
#include "bn_fixed.h"
#include "bn_sram.h"

namespace tool
{
    int cellX2Screen(int &);
    int cellY2Screen(int &);
    int cellX2Screen(bn::fixed &);
    int cellY2Screen(bn::fixed &);

    bool validateSRAMData(int);
}

#endif // TOOLS_H
