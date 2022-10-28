#include "tools.h"

namespace tool
{
    int cellX2Screen(int x, int delta_x)
    {
        return (x * 8) - (32 * 4) + delta_x;
    }

    int cellY2Screen(int y, int delta_y)
    {
        return (y * 8) - (32 * 4) + delta_y;
    }

    int cellX2Screen(bn::fixed x, int delta_x)
    {
        return (x.integer() * 8) - (32 * 4) + delta_x;
    }

    int cellY2Screen(bn::fixed y, int delta_y)
    {
        return (y.integer() * 8) - (32 * 4) + delta_y;
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
            return true;
        }
        return false;
    }

    bool validateSRAM_UInt_Data(int offset)
    {
        uint8_t sram_data = 0;
        int data_sum = 0;
        for (int i = offset; i < offset + 18; ++i)
        {
            bn::sram::read_offset(sram_data, i);
            data_sum += sram_data;
        }
        return (data_sum > 0 && data_sum < 255*18) ? true : false;
    }

    void boolArray2UInt(bn::array<bool, 144> const &array_of_bools, int offset)
    {
        for (int i = 0; i < 18; ++i)
        {
            uint8_t data = 0;
            for (int j = 0; j < 8; ++j)
            {
                data |= array_of_bools[8*i+j] << j;
            }
            bn::sram::write_offset(data, offset);
            ++offset;
        }
    }

    void UInt2BoolArray(bn::array<bool, 144> &array_of_bools, int offset)
    {
        for (int i = 0; i < 18; ++i)
        {
            uint8_t data = 0;
            bn::sram::read_offset(data, offset);
            for (int j = 0; j < 8; ++j)
            {
                uint8_t temp = data;
                array_of_bools[8*i+j] = (temp >> j)&1;
            }
            ++offset;
        }
    }
}
