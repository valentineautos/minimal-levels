/*******************************************************************************
 * Size: 24 px
 * Bpp: 1
 * Opts: --bpp 1 --size 24 --no-compress --font UbuntuCondensed-Regular.ttf --symbols  %,.-_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ° --format lvgl -o ubuntu_24.c
 ******************************************************************************/

#ifndef UBUNTU_24
#define UBUNTU_24 1
#endif

#if UBUNTU_24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap_u24[] = {
    /* U+0020 " " */
    0x0,

    /* U+0025 "%" */
    0x78, 0xc3, 0xc6, 0x33, 0x31, 0x9b, 0xc, 0xd8,
    0x66, 0x83, 0x3c, 0xf, 0x60, 0x7a, 0xf0, 0x37,
    0x81, 0xe6, 0x1b, 0x30, 0xd9, 0x86, 0xcc, 0x66,
    0x63, 0x1e, 0x10, 0xf0,

    /* U+002C "," */
    0x6d, 0xb5, 0x80,

    /* U+002D "-" */
    0xff,

    /* U+002E "." */
    0xff, 0x80,

    /* U+0030 "0" */
    0x3c, 0x7e, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x7e,
    0x3c,

    /* U+0031 "1" */
    0x19, 0xdf, 0xf5, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x63, 0x18,

    /* U+0032 "2" */
    0x79, 0xfa, 0x38, 0x30, 0x60, 0xc3, 0x6, 0x18,
    0x30, 0xc3, 0x6, 0x1c, 0x30, 0x7f, 0xfe,

    /* U+0033 "3" */
    0x79, 0xf8, 0x38, 0x30, 0x60, 0xc3, 0x3e, 0x7c,
    0x1c, 0x18, 0x30, 0x60, 0xe3, 0xfe, 0x78,

    /* U+0034 "4" */
    0x6, 0x7, 0x7, 0x83, 0xc1, 0x61, 0xb0, 0x98,
    0xcc, 0x66, 0x23, 0x31, 0x9f, 0xff, 0xf8, 0x30,
    0x18, 0xc, 0x6, 0x0,

    /* U+0035 "5" */
    0x7e, 0xfd, 0x83, 0x6, 0xc, 0x18, 0x3c, 0x1c,
    0x1c, 0x18, 0x30, 0x60, 0xc3, 0x7e, 0xf8,

    /* U+0036 "6" */
    0xe, 0x1e, 0x30, 0x60, 0x60, 0xc0, 0xfc, 0xfe,
    0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x67, 0x7e,
    0x3c,

    /* U+0037 "7" */
    0xff, 0xff, 0x7, 0x6, 0x6, 0xc, 0xc, 0xc,
    0x18, 0x18, 0x18, 0x18, 0x10, 0x30, 0x30, 0x30,
    0x30,

    /* U+0038 "8" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0x66, 0x7e,
    0x3c, 0x6e, 0xc7, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e,
    0x3c,

    /* U+0039 "9" */
    0x3c, 0x7e, 0xe6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xe3, 0x7f, 0x3f, 0x3, 0x6, 0x6, 0xc, 0x78,
    0x70,

    /* U+0041 "A" */
    0x6, 0x0, 0xf0, 0xf, 0x0, 0xf0, 0xf, 0x81,
    0x98, 0x19, 0x81, 0x98, 0x30, 0xc3, 0xc, 0x30,
    0xc3, 0xfc, 0x7f, 0xe6, 0x6, 0x60, 0x66, 0x6,
    0x60, 0x60,

    /* U+0042 "B" */
    0xfe, 0x7f, 0xb0, 0xf8, 0x3c, 0x1e, 0xf, 0xd,
    0xfe, 0xff, 0x61, 0xb0, 0x78, 0x3c, 0x1e, 0xf,
    0xf, 0xfe, 0xfc, 0x0,

    /* U+0043 "C" */
    0x1f, 0x1f, 0xdc, 0x2c, 0xc, 0x6, 0x3, 0x1,
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xe, 0x3, 0x1,
    0xc2, 0x7f, 0x1f, 0x0,

    /* U+0044 "D" */
    0xfc, 0x3f, 0xcc, 0x3b, 0x6, 0xc1, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc1,
    0xf0, 0x6c, 0x3b, 0xfc, 0xfc, 0x0,

    /* U+0045 "E" */
    0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe,
    0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff,
    0xff,

    /* U+0046 "F" */
    0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe,
    0xfe, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0,

    /* U+0047 "G" */
    0xf, 0x8f, 0xf7, 0x1, 0x80, 0xe0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0x3c, 0xf, 0x3, 0x60,
    0xd8, 0x37, 0xc, 0xff, 0xf, 0x80,

    /* U+0048 "H" */
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0xff, 0xff, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xc0,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+004A "J" */
    0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6,
    0xc, 0x18, 0x30, 0x60, 0xe3, 0xfe, 0x78,

    /* U+004B "K" */
    0xc1, 0xb0, 0xcc, 0x73, 0x18, 0xcc, 0x37, 0xd,
    0x83, 0xc0, 0xf8, 0x36, 0xc, 0xc3, 0x38, 0xc6,
    0x30, 0xcc, 0x3b, 0x6, 0xc1, 0xc0,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff,
    0xff,

    /* U+004D "M" */
    0xe0, 0x3f, 0x1, 0xfc, 0x1f, 0xe0, 0xff, 0x7,
    0xec, 0x6f, 0x63, 0x7b, 0x1b, 0xcd, 0x9e, 0x6c,
    0xf3, 0x67, 0x8e, 0x3c, 0x71, 0xe3, 0x8f, 0x8,
    0x78, 0x3, 0xc0, 0x18,

    /* U+004E "N" */
    0xc0, 0xf8, 0x3e, 0xf, 0xc3, 0xf0, 0xf6, 0x3d,
    0x8f, 0x33, 0xcc, 0xf1, 0xbc, 0x6f, 0xf, 0xc3,
    0xf0, 0x7c, 0x1f, 0x3, 0xc0, 0xc0,

    /* U+004F "O" */
    0xf, 0x3, 0xfc, 0x70, 0xe6, 0x6, 0xe0, 0x6c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0,
    0x3c, 0x3, 0xe0, 0x76, 0x6, 0x70, 0xe3, 0xfc,
    0xf, 0x0,

    /* U+0050 "P" */
    0xfc, 0x7f, 0xb0, 0xd8, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc7, 0x7f, 0xbf, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xc0, 0x0,

    /* U+0051 "Q" */
    0xf, 0x3, 0xfc, 0x70, 0xe6, 0x6, 0x60, 0x6c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0,
    0x3c, 0x3, 0xc0, 0x36, 0x6, 0x70, 0xe3, 0xfc,
    0x1f, 0x80, 0x70, 0x3, 0x0, 0x3c, 0x0, 0xe0,

    /* U+0052 "R" */
    0xfc, 0x3f, 0xcc, 0x33, 0x6, 0xc1, 0xb0, 0x6c,
    0x1b, 0x6, 0xc7, 0x3f, 0xcf, 0xe3, 0x1c, 0xc7,
    0x30, 0xcc, 0x1b, 0x6, 0xc0, 0xc0,

    /* U+0053 "S" */
    0x3e, 0x7e, 0xe0, 0xc0, 0xc0, 0xc0, 0x60, 0x70,
    0x1c, 0xe, 0x7, 0x3, 0x3, 0x3, 0x87, 0xfe,
    0x7c,

    /* U+0054 "T" */
    0xff, 0xff, 0xf0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0xc, 0x0,

    /* U+0055 "U" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf,
    0x8e, 0xfe, 0x3e, 0x0,

    /* U+0056 "V" */
    0x60, 0x6c, 0xd, 0x81, 0xb0, 0x37, 0xe, 0x61,
    0x8c, 0x31, 0x86, 0x30, 0xc3, 0x30, 0x66, 0xc,
    0xc1, 0x90, 0x1e, 0x3, 0xc0, 0x78, 0x6, 0x0,

    /* U+0057 "W" */
    0xc0, 0x3, 0xc0, 0x3, 0xc1, 0x83, 0xc1, 0x83,
    0xe3, 0xc3, 0x63, 0xc2, 0x63, 0xc6, 0x63, 0x46,
    0x62, 0x66, 0x66, 0x66, 0x66, 0x66, 0x36, 0x26,
    0x34, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x38, 0x1c,
    0x18, 0x18,

    /* U+0058 "X" */
    0x60, 0xcc, 0x18, 0xc6, 0x18, 0xc1, 0xb0, 0x36,
    0x3, 0xc0, 0x70, 0xe, 0x1, 0xe0, 0x6c, 0xd,
    0x83, 0x18, 0x63, 0x18, 0x33, 0x6, 0x60, 0x60,

    /* U+0059 "Y" */
    0xc0, 0xf8, 0x76, 0x19, 0x86, 0x73, 0x8c, 0xc3,
    0x30, 0x78, 0x1e, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0xc, 0x0,

    /* U+005A "Z" */
    0x7f, 0xbf, 0xc0, 0xe0, 0x60, 0x70, 0x30, 0x38,
    0x18, 0x1c, 0xc, 0xe, 0x6, 0x7, 0x3, 0x3,
    0x81, 0xff, 0xff, 0x80,

    /* U+005F "_" */
    0xff, 0xff, 0xc0,

    /* U+0061 "a" */
    0x7c, 0x7e, 0x7, 0x3, 0x3, 0x3f, 0x7f, 0xe3,
    0xc3, 0xc3, 0xe3, 0x7f, 0x3f,

    /* U+0062 "b" */
    0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xfe,
    0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc6, 0xfe, 0x7c,

    /* U+0063 "c" */
    0x3c, 0xf9, 0x86, 0xc, 0x18, 0x30, 0x60, 0xc1,
    0x81, 0x83, 0xf3, 0xc0,

    /* U+0064 "d" */
    0x1, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3f, 0x7f,
    0x63, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0x63, 0x7f, 0x3f,

    /* U+0065 "e" */
    0x3c, 0x7e, 0x67, 0xc3, 0xc3, 0xff, 0xff, 0xc0,
    0xc0, 0xc0, 0x60, 0x7e, 0x3e,

    /* U+0066 "f" */
    0x3d, 0xfe, 0x30, 0xc3, 0xf, 0xff, 0xc3, 0xc,
    0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x0,

    /* U+0067 "g" */
    0x1f, 0x7f, 0x63, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x63, 0x7f, 0x3f, 0x3, 0x7, 0x7e,
    0x7c,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xfe,
    0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3,

    /* U+0069 "i" */
    0xfc, 0x3f, 0xff, 0xff, 0xf0,

    /* U+006A "j" */
    0x33, 0x30, 0x3, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0xfe,

    /* U+006B "k" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc6, 0xc6,
    0xcc, 0xdc, 0xd8, 0xf0, 0xf0, 0xd8, 0xdc, 0xcc,
    0xc6, 0xc6, 0xc3,

    /* U+006C "l" */
    0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
    0xce, 0x60,

    /* U+006D "m" */
    0x7c, 0xf3, 0xff, 0xec, 0x71, 0xf0, 0xc3, 0xc3,
    0xf, 0xc, 0x3c, 0x30, 0xf0, 0xc3, 0xc3, 0xf,
    0xc, 0x3c, 0x30, 0xf0, 0xc3, 0xc3, 0xc,

    /* U+006E "n" */
    0x7c, 0xfe, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+006F "o" */
    0x3e, 0x3f, 0x98, 0xdc, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xd8, 0xcf, 0xe3, 0xe0,

    /* U+0070 "p" */
    0xf8, 0xfe, 0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc6, 0xfe, 0xfc, 0xc0, 0xc0, 0xc0,
    0xc0,

    /* U+0071 "q" */
    0x3f, 0x7f, 0x63, 0xe3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0x63, 0x7f, 0x3f, 0x3, 0x3, 0x3,
    0x3,

    /* U+0072 "r" */
    0x7f, 0xfc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,
    0x30, 0xc0,

    /* U+0073 "s" */
    0x7b, 0xec, 0x30, 0xc1, 0x83, 0x86, 0xc, 0x30,
    0xfe, 0xf0,

    /* U+0074 "t" */
    0xc6, 0x31, 0x8f, 0xff, 0x18, 0xc6, 0x31, 0x8c,
    0x63, 0xf, 0x78,

    /* U+0075 "u" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xe3, 0x7f, 0x3e,

    /* U+0076 "v" */
    0xe1, 0xb0, 0xd8, 0x6c, 0x66, 0x31, 0x98, 0xcc,
    0x64, 0x36, 0xf, 0x7, 0x83, 0x80, 0xc0,

    /* U+0077 "w" */
    0x63, 0x1b, 0x18, 0xd8, 0xc6, 0xce, 0x36, 0x79,
    0xb3, 0xc8, 0x96, 0xc6, 0x96, 0x34, 0xb1, 0xe5,
    0x8f, 0x38, 0x39, 0xc1, 0x86, 0x0,

    /* U+0078 "x" */
    0x61, 0xb1, 0x8c, 0xc6, 0xc1, 0xe0, 0xe0, 0x70,
    0x3c, 0x36, 0x1b, 0x98, 0xcc, 0x66, 0x18,

    /* U+0079 "y" */
    0xe1, 0xb0, 0xd8, 0x6c, 0x66, 0x31, 0x98, 0xcc,
    0x6c, 0x36, 0xf, 0x7, 0x3, 0x80, 0xc0, 0xc0,
    0x61, 0xe0, 0xe0, 0x0,

    /* U+007A "z" */
    0xff, 0xfc, 0x38, 0x61, 0x83, 0xc, 0x18, 0x60,
    0xc3, 0x7, 0xff, 0xe0,

    /* U+00B0 "°" */
    0x7b, 0xfc, 0xf3, 0xfd, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_u24[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 75, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 248, .box_w = 13, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 29, .adv_w = 89, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 32, .adv_w = 89, .box_w = 4, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 33, .adv_w = 89, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 35, .adv_w = 165, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 52, .adv_w = 165, .box_w = 5, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 63, .adv_w = 165, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 165, .box_w = 7, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 165, .box_w = 9, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 165, .box_w = 7, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 165, .box_w = 8, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 165, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 165, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 165, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 193, .box_w = 12, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 200, .box_w = 9, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 242, .adv_w = 180, .box_w = 9, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 221, .box_w = 10, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 175, .box_w = 8, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 164, .box_w = 8, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 202, .box_w = 10, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 221, .box_w = 10, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 99, .box_w = 2, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 367, .adv_w = 152, .box_w = 7, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 198, .box_w = 10, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 160, .box_w = 8, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 279, .box_w = 13, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 449, .adv_w = 223, .box_w = 10, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 232, .box_w = 12, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 186, .box_w = 9, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 232, .box_w = 12, .box_h = 21, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 549, .adv_w = 197, .box_w = 10, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 154, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 588, .adv_w = 164, .box_w = 10, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 211, .box_w = 9, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 630, .adv_w = 191, .box_w = 11, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 290, .box_w = 16, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 688, .adv_w = 181, .box_w = 11, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 712, .adv_w = 173, .box_w = 10, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 734, .adv_w = 166, .box_w = 9, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 754, .adv_w = 141, .box_w = 9, .box_h = 2, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 757, .adv_w = 167, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 770, .adv_w = 179, .box_w = 8, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 789, .adv_w = 136, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 801, .adv_w = 179, .box_w = 8, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 820, .adv_w = 167, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 833, .adv_w = 118, .box_w = 6, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 848, .adv_w = 179, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 865, .adv_w = 185, .box_w = 8, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 884, .adv_w = 93, .box_w = 2, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 889, .adv_w = 93, .box_w = 4, .box_h = 22, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 900, .adv_w = 164, .box_w = 8, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 919, .adv_w = 93, .box_w = 4, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 929, .adv_w = 268, .box_w = 14, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 952, .adv_w = 185, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 965, .adv_w = 178, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 980, .adv_w = 179, .box_w = 8, .box_h = 17, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 997, .adv_w = 179, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1014, .adv_w = 126, .box_w = 6, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1024, .adv_w = 131, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1034, .adv_w = 123, .box_w = 5, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1045, .adv_w = 184, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1058, .adv_w = 152, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1073, .adv_w = 220, .box_w = 13, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1095, .adv_w = 151, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1110, .adv_w = 152, .box_w = 9, .box_h = 17, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1130, .adv_w = 137, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1142, .adv_w = 111, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 13}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 2, 3, 4, 0,
    5, 6, 7, 8, 9, 10, 11, 12,
    13, 14
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps_u24[] =
{
    {
        .range_start = 32, .range_length = 26, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 26, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 16,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 95, .range_length = 1, .glyph_id_start = 42,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 43,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 176, .range_length = 1, .glyph_id_start = 69,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, 4, 5, 6, 7, 8, 9, 0,
    0, 10, 11, 12, 13, 0, 6, 14,
    6, 15, 16, 17, 18, 19, 20, 21,
    22, 23, 0, 24, 25, 26, 0, 27,
    28, 0, 29, 0, 30, 31, 0, 29,
    29, 25, 25, 32, 33, 0, 34, 0,
    35, 36, 37, 38, 39, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 1, 2, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, 0, 4, 0, 0, 0, 4, 0,
    0, 5, 0, 0, 6, 0, 4, 0,
    4, 0, 7, 8, 9, 10, 11, 12,
    13, 14, 0, 15, 0, 16, 16, 16,
    0, 16, 0, 0, 17, 0, 18, 19,
    19, 16, 19, 16, 19, 20, 21, 22,
    23, 24, 25, 23, 26, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 10, -13, 11, 0, 5, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 8, -18, 0,
    -8, -17, 0, -4, -4, -11, -17, -3,
    0, 6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 10, 0, 12, -10,
    12, 0, 4, -13, -6, -12, -8, 10,
    -15, 10, 8, 0, 0, 0, 0, 4,
    0, -2, 0, 4, 10, 8, -2, 0,
    0, 0, 0, 0, 0, -6, 0, -2,
    -2, -2, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    12, -11, 12, -4, 13, 0, 8, 12,
    0, 12, 0, 9, 7, 8, 0, -3,
    0, 0, 0, 0, 0, -6, 0, 0,
    6, 6, -13, 8, -10, 0, -15, 0,
    0, -12, 0, -4, 0, -6, -10, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, 0, 4, 0, 4, -6,
    6, 0, 0, 0, 0, 0, 0, 0,
    6, 4, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 4, 0, -35, 8,
    -12, -4, -29, 0, 0, 8, 0, 6,
    6, 4, 8, 0, -10, -8, 0, 0,
    -8, -6, -2, -8, 0, 0, -10, -8,
    0, 8, 0, 0, 0, 0, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -10, -6,
    0, 0, 0, 0, -8, 0, -12, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 6, -21, 8, -15,
    10, 0, 0, 3, 0, 4, -2, 10,
    6, 8, -4, -10, 0, 0, 0, 4,
    0, -13, -12, -8, 6, 4, 9, -19,
    12, -13, 11, 0, 5, -23, -6, -19,
    -13, 8, -19, 6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -8, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -4, -4,
    0, 0, -36, 0, -13, 0, -35, 0,
    4, 0, 0, 6, 4, -2, 4, 0,
    -8, -2, 0, 0, 0, 0, 0, 0,
    8, 8, 6, 0, 5, -8, 4, -4,
    8, 0, 0, -6, 0, -4, 0, 4,
    -4, 6, -4, -8, 0, -4, 0, 0,
    -2, -4, -4, -4, 0, 2, 0, 8,
    2, 4, 4, 0, 0, 0, 0, 4,
    0, 4, 0, 0, 8, 8, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -17, -17, -13, -12, -19, 0, 0, 10,
    0, 12, 6, 8, 13, 0, -17, -21,
    0, 0, -17, -17, 0, -17, -10, -10,
    -12, -15, -10, 0, -5, 0, -8, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -19, -4, -12, -4,
    -21, 0, 0, 12, 0, 12, 6, 8,
    13, 0, -10, -8, 0, 0, -6, -8,
    0, -8, 0, 0, 0, -6, -15, -4,
    -8, 0, -19, 0, 0, 6, 0, 8,
    4, 2, 10, 0, -6, -6, 0, 0,
    -6, -4, 0, -4, 0, 0, 0, 0,
    8, -11, 8, -6, 8, 0, 0, 5,
    0, 7, 0, 8, 7, 5, 0, -10,
    0, 0, 0, 0, -4, -6, -6, -6,
    7, 0, -15, -17, -15, -10, -25, -8,
    0, 13, 0, 13, 9, 8, 13, 2,
    -13, -17, 0, 0, -17, -13, 0, -15,
    -4, -4, -6, -8, 4, -13, 4, -4,
    6, 0, 0, 0, 0, 4, 0, 0,
    4, 0, 0, -8, 0, 0, 0, 0,
    0, -2, -4, -2, 8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, -2, 0, 0,
    0, 6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    -4, -4, 6, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    8, 8, 4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, -2, 0, -23, -13,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 8, 10, 6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -5, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -8, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, 0,
    0, 0, 4, 0, 8, 4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -27, -10, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -6, -4,
    0, 0, 0, 0, 0, 0, 13, 13,
    8, 0, 4, -8, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 6, 0, -15, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, -4, 0, 0, 0, 0,
    0, 0, 10, 10, 6, 0, -10, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 10, 10, 6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    7, 0, -15, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -5, -4, 0, 0, 0, 0, 0, 0,
    10, 10, 6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 39,
    .right_class_cnt     = 26,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache_u24;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc_u24 = {
#else
static lv_font_fmt_txt_dsc_t font_dsc_u24 = {
#endif
    .glyph_bitmap = glyph_bitmap_u24,
    .glyph_dsc = glyph_dsc_u24,
    .cmaps = cmaps_u24,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 5,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache_u24
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ubuntu_24 = {
#else
lv_font_t ubuntu_24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 23,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc_u24,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UBUNTU_24*/

