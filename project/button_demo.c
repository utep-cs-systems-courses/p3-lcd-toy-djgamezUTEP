#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
#include "led.h"
#include "draw_shapes.h"
// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 


char redraw_screen = 1;
u_int backgroundColor = COLOR_BLUE; 
void main(void)
{
  
  configureClocks();
  led_init();
  switch_p2_init();
  lcd_init();
  
  //enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(backgroundColor);

  while (1) {			/* forever */
    if (redraw_screen) {
      redraw_screen = 0;
      draw_BTC(xShift,yShift);
    }
    green_on = 0;   	/* led off */
    led_changed = 1;
    led_update();
    or_sr(0x10);	/**< CPU OFF */
    
    green_on = 1;	/* led on */
    led_changed = 1;
    led_update();
  }
}

    
    
