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
    8,  // 48 0
    6,  // 49 1
    7,  // 50 2
    7,  // 51 3
    7,  // 52 4
    8,  // 53 5
    7,  // 54 6
    7,  // 55 7
    6,  // 56 8
    7,  // 57 9
    5,  // 58 :
    5,  // 59 ;
    7,  // 60 <
    7,  // 61 =
    7,  // 62 >
    8,  // 63 ?
    8,  // 64 @
    8,  // 65 A
    7,  // 66 B
    8,  // 67 C
    8,  // 68 D
    8,  // 69 E
    8,  // 70 F
    7,  // 71 G
    8,  // 72 H
    8,  // 73 I
    7,  // 74 J
    8,  // 75 K
    8,  // 76 L
    8,  // 77 M
    8,  // 78 N
    8,  // 79 O
    7,  // 80 P
    8,  // 81 Q
    8,  // 82 R
    7,  // 83 S
    7,  // 84 T
    8,  // 85 U
    8,  // 86 V
    8,  // 87 W
    8,  // 88 X
    8,  // 89 Y
    8,  // 90 Z
    6,  // 91 [
    7,  // 92 backslash
    6,  // 93 ]
    4,  // 94 ^
    8,  // 95 _
    4,  // 96 `
    8,  // 97 a
    6,  // 98 b
    7,  // 99 c
    7,  // 100 d
    7,  // 101 e
    7,  // 102 f
    7,  // 103 g
    8,  // 104 h
    6,  // 105 i
    6,  // 106 j
    7,  // 107 k
    7,  // 108 l
    8,  // 109 m
    8,  // 110 n
    6,  // 111 o
    7,  // 112 p
    8,  // 113 q
    6,  // 114 r
    7,  // 115 s
    6,  // 116 t
    7,  // 117 u
    7,  // 118 v
    8,  // 119 w
    8,  // 120 x
    8,  // 121 y
    7,  // 122 z
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
