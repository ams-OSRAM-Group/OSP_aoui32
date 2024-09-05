// toled.h - Tiny OLED driver (only 128x32, only I2C, only for ESP32)
#ifndef _TOLED_H_
#define _TOLED_H_


#include <stdint.h>


#define TOLED_VERSION  "0.6.3"
// 20240611  0.6.3  bugfix: undid more strict wrapping
// 20240607  0.6.2  bugfix: out of bounds write (added range check on loc in toled_framebuf_mask)
// 20240417  0.6.1  


#define TOLED_WIDTH    128
#define TOLED_HEIGHT    32


#define TOLED_COL_BLACK 0   // Draw black pixels (off)
#define TOLED_COL_WHITE 1   // Draw white pixels (on)
#define TOLED_COL_FLIP  2   // Draw pixels by inverting


// toled management
void toled_init(void);
void toled_clear(void);
void toled_commit(void);

// toled pixels, lines, rectangles
void toled_pixel(int x, int y, int col=TOLED_COL_WHITE );
void toled_verline(int x, int y0, int y1, int col=TOLED_COL_WHITE );
void toled_horline(int x0, int x1, int y, int col=TOLED_COL_WHITE );
void toled_fillrect(int x0, int y0, int x1, int y1, int col=TOLED_COL_WHITE );
void toled_openrect(int x0, int y0, int x1, int y1, int col=TOLED_COL_WHITE );

// toled text
typedef enum toled_font_e {
  toled_font_sans5, 
  toled_font_sans8, 
  toled_font_sans10, 
  toled_font_sans12, 
  toled_font_sans14, 
} toled_font_t;

void toled_font(toled_font_t font, int col=TOLED_COL_WHITE, int kern=1, int margin=0 );
void toled_cursor(int x, int y);

void toled_char(char ch);
void toled_str(const char *s);

int toled_charwidth(char ch);
int toled_strwidth(const char *s);

void toled_str(const char *s, int width, int align=0);

#endif
