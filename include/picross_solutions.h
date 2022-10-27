#ifndef PICROSS_SOLUTIONS_H
#define PICROSS_SOLUTIONS_H
#include "bn_array.h"

namespace puzzle
{
constexpr bn::array<bool, 144> Kanji_Cat =
    {
        0,1,1,1,1,1,0,1,1,1,0,1,
        1,0,1,0,1,0,0,0,0,0,0,0,
        1,1,0,1,1,1,0,1,1,1,0,1,
        1,1,0,0,1,1,1,1,1,1,1,1,
        1,0,1,0,1,0,0,0,0,0,0,0,
        1,1,1,0,1,0,1,1,0,1,1,0,
        1,1,0,0,1,0,1,1,0,1,1,0,
        1,1,0,0,1,0,0,0,0,0,0,0,
        1,0,1,0,1,0,1,1,0,1,1,0,
        1,1,1,0,1,0,1,1,0,1,1,0,
        1,1,1,0,1,0,0,0,0,0,0,0,
        1,0,0,1,1,0,1,1,1,1,1,0
    };
constexpr bn::array<bool, 144> Kanji_Congrats =
    {
        1,1,1,0,1,1,1,0,0,0,0,0,
        1,0,0,0,0,0,1,0,1,1,1,0,
        1,1,1,1,1,0,1,0,1,1,1,0,
        1,1,1,1,0,1,1,0,1,1,1,0,
        1,1,1,0,0,1,1,0,0,0,0,0,
        1,1,0,0,1,0,1,1,1,1,1,1,
        1,0,1,0,1,0,1,1,0,1,0,1,
        1,1,1,0,1,1,1,1,0,1,0,1,
        1,1,1,0,1,1,1,1,0,1,0,1,
        1,1,1,0,1,1,1,0,1,1,0,1,
        1,1,1,0,1,1,1,0,1,1,0,1,
        1,1,1,0,1,1,0,1,1,1,0,0
    };
constexpr bn::array<bool, 144> Kanji_Flower =
    {
        0,0,0,1,0,0,0,0,1,0,0,0,
        0,0,0,1,0,0,0,0,1,0,0,0,
        0,1,1,1,1,1,1,1,1,1,1,0,
        0,0,0,1,0,0,0,0,1,0,0,0,
        0,0,0,0,1,0,1,0,0,0,0,0,
        0,0,0,1,0,0,1,0,0,1,0,0,
        0,0,0,1,0,0,1,0,0,1,0,0,
        0,0,1,1,0,0,1,0,1,0,0,0,
        0,1,0,1,0,0,1,1,0,0,0,0,
        0,0,0,1,0,1,1,0,0,0,0,0,
        0,0,0,1,0,0,1,0,0,0,1,0,
        0,0,0,1,0,0,1,1,1,1,0,0

    };

constexpr bn::array<bool, 144> Nature_4LClover =
    {
        0,0,0,0,0,1,1,1,0,0,0,0,
        0,0,0,0,1,1,1,1,1,0,0,0,
        0,0,0,0,1,1,1,1,1,0,0,0,
        0,0,0,0,1,1,1,0,0,1,1,0,
        0,1,1,1,0,1,0,1,1,1,1,1,
        1,1,1,1,1,0,1,1,1,1,1,1,
        1,1,1,1,0,1,0,1,1,1,1,0,
        1,1,1,0,1,1,1,0,0,0,1,0,
        0,1,1,0,1,1,1,0,1,1,0,0,
        0,0,0,1,1,1,1,1,0,1,0,0,
        0,0,0,1,1,1,1,1,0,0,1,0,
        0,0,0,0,1,1,0,0,0,0,1,0
    };
constexpr bn::array<bool, 144> Nature_Flower =
    {
        0,0,0,0,0,1,1,0,0,0,0,0,
        0,0,0,0,1,0,0,1,0,0,0,0,
        0,1,1,1,1,1,1,1,1,1,1,0,
        1,0,0,0,1,1,1,1,0,0,0,1,
        1,0,0,0,1,1,1,1,0,0,0,1,
        0,1,1,1,0,0,0,0,1,1,1,0,
        0,0,0,1,0,0,0,0,1,0,0,0,
        0,0,0,0,1,1,1,1,0,0,0,0,
        0,1,1,1,0,1,1,0,1,1,1,0,
        1,0,0,0,0,1,1,0,0,0,0,1,
        1,0,0,0,1,1,1,1,0,0,0,1,
        1,1,1,1,0,1,1,0,1,1,1,1
    };
constexpr bn::array<bool, 144> Nature_Lagomorph =
    {
        1,1,1,0,0,0,0,0,0,1,1,1,
        1,0,0,1,0,0,0,0,1,0,0,1,
        1,0,0,0,1,0,0,1,0,0,0,1,
        0,1,0,0,1,0,0,1,0,0,1,0,
        0,0,1,0,1,0,0,1,0,1,0,0,
        0,0,0,1,0,1,1,0,1,0,0,0,
        0,0,1,0,0,0,0,0,0,1,0,0,
        0,1,0,1,0,0,0,0,1,0,1,0,
        1,0,0,1,0,0,0,0,1,0,0,1,
        1,0,0,1,0,1,1,0,1,0,0,1,
        0,1,0,0,0,0,0,0,0,0,1,0,
        0,0,1,1,1,1,1,1,1,1,0,0
    };

constexpr bn::array<bool, 144> Portrait_Nyra =
    {
        1,1,1,1,1,1,1,1,1,1,1,0,
        1,1,1,0,0,0,1,1,0,1,1,0,
        1,1,1,0,0,0,0,0,0,0,1,1,
        1,1,0,1,1,0,0,1,1,0,1,1,
        1,0,1,0,1,0,0,0,1,0,1,1,
        1,0,0,0,1,0,0,0,1,0,1,1,
        0,1,0,0,0,0,0,0,0,1,1,1,
        1,0,0,0,0,1,1,0,0,0,1,0,
        1,1,0,0,0,1,0,0,0,1,0,0,
        1,1,1,1,0,0,0,1,1,0,0,0,
        1,1,1,1,1,1,1,1,0,0,0,0,
        1,1,1,1,0,0,0,1,1,1,1,0
    };
constexpr bn::array<bool, 144> Portrait_Tooru =
    {
        1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,0,0,1,1,0,0,0,1,1,1,
        1,0,0,0,0,0,0,0,0,0,1,1,
        1,1,1,0,0,0,1,1,1,0,1,1,
        1,0,0,1,0,1,0,0,0,1,1,0,
        1,0,1,1,1,1,0,1,0,1,0,0,
        1,0,1,1,0,1,0,1,0,1,0,1,
        1,1,1,0,0,0,1,1,1,0,1,0,
        1,0,0,1,1,0,0,0,0,1,1,0,
        0,1,0,0,0,0,0,0,1,1,0,1,
        0,0,1,1,1,1,1,1,1,0,1,1,
        0,0,0,0,0,1,1,1,1,0,0,0
    };
constexpr bn::array<bool, 144> Portrait_Yuuji =
    {
        0,0,0,0,0,0,0,0,0,0,0,1,
        0,1,0,1,0,1,0,1,0,1,0,1,
        1,0,1,0,1,0,1,0,1,1,0,1,
        0,1,1,1,0,0,1,1,0,1,1,1,
        0,1,0,1,0,0,0,1,0,1,0,1,
        0,1,0,1,0,0,0,1,0,0,0,1,
        0,1,0,0,0,0,0,0,0,0,0,1,
        0,1,0,1,1,1,0,0,0,1,1,0,
        0,0,1,0,0,0,0,0,1,1,0,0,
        0,0,0,1,1,1,1,1,1,0,0,0,
        0,0,0,0,1,1,0,0,1,1,0,0,
        1,1,1,1,0,1,1,1,1,0,1,1
    };

constexpr bn::array<bool, 144> Things_Gameboy =
    {
        0,0,1,1,1,1,1,1,1,1,0,0,
        0,0,1,0,0,0,0,0,0,1,0,0,
        0,0,1,0,1,1,1,1,0,1,0,0,
        0,0,1,0,1,1,1,1,0,1,0,0,
        0,0,1,0,1,1,1,1,0,1,0,0,
        0,0,1,0,0,0,0,0,0,1,0,0,
        0,0,1,0,1,0,0,0,0,1,0,0,
        0,0,1,1,1,1,0,0,1,1,0,0,
        0,0,1,0,1,0,0,1,0,1,0,0,
        0,0,1,0,0,0,0,0,0,1,0,0,
        0,0,1,0,1,1,1,1,0,1,0,0,
        0,0,1,1,1,1,1,1,1,0,0,0
    };
constexpr bn::array<bool, 144> Things_Giftbox =
    {
        0,0,1,0,1,0,0,1,0,1,0,0,
        0,1,1,1,0,1,1,0,1,1,1,0,
        1,0,0,1,1,0,0,1,1,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,1,0,0,1,0,0,0,1,
        1,0,0,0,1,0,0,1,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,
        0,1,0,0,1,0,0,1,0,0,1,0,
        0,1,0,0,1,0,0,1,0,0,1,0,
        0,1,0,0,1,0,0,1,0,0,1,0,
        0,1,0,0,1,0,0,1,0,0,1,0,
        0,1,1,1,1,1,1,1,1,1,1,0
    };
constexpr bn::array<bool, 144> Things_Notepad =
    {
        0,0,1,1,1,1,1,1,1,1,1,1,
        0,1,1,1,1,1,1,1,1,1,1,1,
        0,1,0,0,0,0,0,0,0,0,1,1,
        1,1,1,0,1,1,1,1,1,0,1,1,
        0,1,0,0,1,1,1,1,1,0,1,1,
        1,1,1,0,1,1,1,1,1,0,1,1,
        0,1,0,0,0,0,0,0,0,0,1,1,
        1,1,1,0,0,0,0,0,0,0,1,1,
        0,1,0,0,1,1,1,1,1,0,1,1,
        0,1,0,0,0,0,0,0,0,0,1,1,
        0,1,1,1,1,1,1,1,1,1,1,0
    };

inline bn::array<bool, 144> Custom = {0};
}

#endif // PICROSS_SOLUTIONS_H
