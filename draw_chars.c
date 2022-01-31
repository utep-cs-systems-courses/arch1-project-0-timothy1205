#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void get_font_dimensions(char font, int *width, int *height)
{
  if (width == NULL || height == NULL) {
    return;
  }

  switch (font) {
    case FONT_11x16:
      *width = 11;
      *height = 16;
      break;
    case FONT_8x12:
      *width = 8;
      *height = 12;
      break;
    case FONT_5x7:
      *width = 5;
      *height = 7;
      break;
  }
}

void print_char(char font, char c)
{
  int width = 0;
  int height = 0;

  get_font_dimensions(font, &width, &height);

  c -= 0x20; // make character uppercase
  if (font == FONT_8x12) {
    for (char col = 0; col < height; col++) {
      unsigned short colBits = font_8x12[c][col];

      for (char row = 0; row < width; row++) {
        unsigned short rowMask = 1 << (width-1-row);
        putchar( (colBits & rowMask) ? '*' : ' ');
      }
      putchar('\n');
    }
  } else {
    for (char row = 0; row < width; row++) {
      unsigned short rowBits;
     
      switch (font) {
        case FONT_11x16:
          rowBits = font_11x16[c][row];
          break;
        case FONT_5x7:
          rowBits = font_5x7[c][row];
          break;
        default:
          printf("Unexpected value (%c), skipping...", font);
      }

      for (char col = 0; col < height; col++) {
        unsigned short colMask = 1 << (height-1-col); /* mask to select bit associated with bit */
        putchar( (rowBits & colMask) ? '*' : ' ');
      }
      putchar('\n');
    }
  
  }
}

void print_char_11x16(char c)
{
  c -= 0x20; // make character uppercase
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : '_');
    }
    putchar('\n');
  }
}
