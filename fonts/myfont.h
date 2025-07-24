#pragma once
#include <cstddef>
#include <stdint.h>

#define FONT_BITMAP_WIDTH 1024
#define FONT_BITMAP_HEIGHT 48

typedef struct {
  uint16_t unicode;
  uint16_t x;
  uint16_t y;
  uint16_t w;
  uint16_t h;
} ChineseChar;

extern const uint16_t myfont_bitmap[];
extern const ChineseChar fontMap[];
extern const size_t fontMapSize;
extern const uint16_t supported_unicodes[];
extern const size_t supported_unicodes_size;

const ChineseChar* findChar(uint16_t unicode);
