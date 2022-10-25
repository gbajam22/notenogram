#include "tools.h"

namespace tool
{
    int cellX2Screen(int &x)
    {
        return (x * 8) - (32 * 4) + 8;
    }

    int cellY2Screen(int &y)
    {
        return (y * 8) - (32 * 4) + 8;
    }

    int cellX2Screen(bn::fixed &x)
    {
        return (x.integer() * 8) - (32 * 4) + 8;
    }

    int cellY2Screen(bn::fixed &y)
    {
        return (y.integer() * 8) - (32 * 4) + 8;
    }

    bool validateSRAMData(int offset)
    {
        bn::array<int8_t, 144> puzzle_slot;
        bn::sram::read_offset(puzzle_slot, offset);
        if (puzzle_slot[0] == 1 || puzzle_slot[0] == 0)
        {
            for (int i = 1; i < 144; ++i)
            {
                if (puzzle_slot[i] != 1 && puzzle_slot[i] != 0)
                    return false;
            }
        }
        return true;
    }
}
