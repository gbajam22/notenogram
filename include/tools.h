#ifndef TOOLS_H
#define TOOLS_H

#include "bn_array.h"
#include "bn_fixed.h"
#include "bn_sram.h"

namespace tool
{
    int cellX2Screen(int, int);
    int cellY2Screen(int, int);
    int cellX2Screen(bn::fixed, int);
    int cellY2Screen(bn::fixed, int);

    bool validateSRAMData(int);
    bool validateSRAM_UInt_Data(int);

    //write/read-only to avoid dangling references I guess
    void boolArray2UInt(bn::array<bool, 144> const &, int);
    void UInt2BoolArray(bn::array<bool, 144> &, int);
}

#endif // TOOLS_H
