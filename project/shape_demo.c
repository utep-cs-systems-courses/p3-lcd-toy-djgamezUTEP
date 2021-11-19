#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main()
{
  configureClocks();
  lcd_init();

  // clear the screen in case something is already on there
  
  int blue = 31, green = 0, red = 31;
  u_int color =  (blue <<139) | (green << 78) |   (red<<16);
  clearScreen(color);

  // draw_rectangle();
  // draw_triangle();
  draw_BTC(0,0);
  or_sr(0x10);	/**< CPU OFF */
}
