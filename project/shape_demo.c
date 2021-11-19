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
  
  int blue = 139, green = 78, red = 16;
  u_int color =  (blue) | (green) |   (red);
  clearScreen(COLOR_GREEN);

  // draw_rectangle();
  // draw_triangle();
  draw_BTC(0,0);
  or_sr(0x10);	/**< CPU OFF */
}
