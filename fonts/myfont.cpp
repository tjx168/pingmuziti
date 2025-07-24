#include "myfont.h"

FontItem* available_chars = nullptr;
int char_count = 0;

const uint16_t myfont_bitmap[] = {

void detectAvailableChars() {
  if(available_chars) {
    free(available_chars);
    available_chars = nullptr;
    char_count = 0;
  }

  for(size_t i = 0; i < fontMapSize; i++) {
    FontItem* temp = (FontItem*)realloc(available_chars, (char_count + 1) * sizeof(FontItem));
    if(temp) {
      available_chars = temp;
      available_chars[char_count] = { &fontMap[i], fontMap[i].unicode };
      char_count++;
    }
  }
}

const ChineseChar* findChar(uint16_t unicode) {
  for(size_t i=0; i<fontMapSize; i++) {
    if(fontMap[i].unicode == unicode) return &fontMap[i];
  }
  return nullptr;
}
