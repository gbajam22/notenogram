/*
 * Copyright (c) 2020-2021 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */

#ifndef KVALLIGRAPHY_VARIABLE_8x8_SPRITE_FONT_H
#define KVALLIGRAPHY_VARIABLE_8x8_SPRITE_FONT_H

#include "bn_sprite_font.h"
#include "bn_sprite_items_kvalligraphy_8x8.h"

constexpr bn::string_view variable_8x8_sprite_font_utf8_characters[] = {
"д"
};

constexpr int8_t variable_8x8_sprite_font_character_widths[] = {
    6,  // 32
    7,  // 33 !
    6,  // 34 "
    8,  // 35 #
    7,  // 36 $
    7,  // 37 %
    8,  // 38 &
    6,  // 39 '
    6,  // 40 (
    6,  // 41 )
    8,  // 42 *
    8,  // 43 +
    5,  // 44 ,
    7,  // 45 -
    4,  // 46 .
    7,  // 47 /
    7,  // 48 0
    4,  // 49 1
    6,  // 50 2
    6,  // 51 3
    5,  // 52 4
    7,  // 53 5
    5,  // 54 6
    6,  // 55 7
    5,  // 56 8
    6,  // 57 9
    5,  // 58 :
    5,  // 59 ;
    7,  // 60 <
    7,  // 61 =
    7,  // 62 >
    8,  // 63 ?
    8,  // 64 @
    8,  // 65 A
    6,  // 66 B
    7,  // 67 C
    7,  // 68 D
    7,  // 69 E
    8,  // 70 F
    6,  // 71 G
    8,  // 72 H
    7,  // 73 I
    6,  // 74 J
    8,  // 75 K
    7,  // 76 L
    8,  // 77 M
    7,  // 78 N
    7,  // 79 O
    6,  // 80 P
    7,  // 81 Q
    7,  // 82 R
    6,  // 83 S
    7,  // 84 T
    8,  // 85 U
    7,  // 86 V
    8,  // 87 W
    8,  // 88 X
    7,  // 89 Y
    7,  // 90 Z
    6,  // 91 [
    7,  // 92 backslash
    6,  // 93 ]
    4,  // 94 ^
    8,  // 95 _
    4,  // 96 `
    7,  // 97 a
    5,  // 98 b
    5,  // 99 c
    6,  // 100 d
    6,  // 101 e
    5,  // 102 f
    6,  // 103 g
    7,  // 104 h
    5,  // 105 i
    5,  // 106 j
    6,  // 107 k
    5,  // 108 l
    8,  // 109 m
    7,  // 110 n
    5,  // 111 o
    5,  // 112 p
    6,  // 113 q
    6,  // 114 r
    6,  // 115 s
    5,  // 116 t
    7,  // 117 u
    6,  // 118 v
    8,  // 119 w
    7,  // 120 x
    6,  // 121 y
    6,  // 122 z
    6,  // 123 {
    5,  // 124 |
    6,  // 125 }
    8, // 126 ~
    8 //i'm guessing butano's sprite_font won't work without ANY utf8 chars
};

/*constexpr bn::span<const bn::utf8_character> variable_8x8_sprite_font_utf8_characters_span(
        variable_8x8_sprite_font_utf8_characters);

constexpr auto variable_8x8_sprite_font_utf8_characters_map =
        bn::utf8_characters_map<variable_8x8_sprite_font_utf8_characters_span>();

constexpr bn::sprite_font variable_8x8_sprite_font(
        bn::sprite_items::kvalligraphy_8x8, variable_8x8_sprite_font_utf8_characters,
        variable_8x8_sprite_font_character_widths);*/

#endif
