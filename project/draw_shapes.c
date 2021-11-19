
#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"

void
draw_rectangle(int xshift, int yshift)
{
  int height = 68;
  int width  = 8;
  int row = 32, col = (screenWidth / 2)-17;
  row+=yshift;
  col+=xshift;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int blue = 0, green = 0, red = 31;
  u_int color = COLOR_SIENNA;

  fillRectangle(left_col, row, width, height, color);
}
draw_rectangle2(int xshift, int yshift)
{
  int height = 90;
  int width  = 5;
  int row = 22, col = (screenWidth / 2)-4;
  row+=yshift;
  col+=xshift;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int blue = 0, green = 0, red = 31;
  u_int color = COLOR_SIENNA;

  fillRectangle(left_col, row, width, height, color);
} 
draw_rectangle3(int xshift, int yshift)
{
  int height = 90;
  int width  = 5;
  int row = 22, col = (screenWidth / 2)+6;
  row+=yshift;
  col+=xshift;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int blue = 0, green = 0, red = 31;
  u_int color = COLOR_SIENNA;

  fillRectangle(left_col, row, width, height, color);
}


void
//B-top inner rectangle
draw_rectangle4(int xshift, int yshift)
{
  int height = 52;
  int width  = 12;
  int row = 38, col = (screenWidth / 2)-8;
  row+=yshift;
  col+=xshift;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int blue = 0, green = 0, red = 31;
  u_int color = COLOR_SIENNA;

  fillRectangle(left_col, row, width, height, color);
}


void
draw_rectangle5(int xshift, int yshift)
{
  int height = 8;
  int width  = 18;
  int row = 32, col = (screenWidth / 2)-15;
  row+=yshift;
  col+=xshift;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int blue = 0, green = 0, red = 31;
  u_int color = COLOR_SIENNA;

  fillRectangle(left_col, row, width, height, color);
}


void
draw_rectangle6(int xshift, int yshift)
{
  int height = 8;
  int width  = 18;
  int row = 96, col = (screenWidth / 2)-15;
  row+=yshift;
  col+=xshift;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int blue = 0, green = 0, red = 31;
  u_int color = COLOR_SIENNA;

  fillRectangle(left_col, row, width, height, color);
}


void
draw_rectangle7(int xshift, int yshift)
{
  int height = 56;
  int width  = 8;
  int row = 40, col = (screenWidth / 2)-17;
  row+=yshift;
  col+=xshift;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  int blue = 31, green = 0, red = 31;
  u_int color =  (blue <<0) | (green << 140) | (red<<255);

  fillRectangle(left_col, row, width, height, color);
}


void

drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR)
{
  u_int length = x_end - x_start;
  // set the draw area from the start of the line to the end
  // height is 1 since its a line
  lcd_setArea(x_start, y, x_end, y);
  for (u_int i = 0; i < length; i++) {
    lcd_writeColor(colorBGR);
  }
  
}

void
drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color)
{
  // bottom
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord + y_point, color);
  // top
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord - y_point, color);
  // and the middle two
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord + x_point, color);
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord - x_point, color);
					  
}

void
//B-top outer circle
draw_circle(int xshift, int yshift)
{
  int x_coord = screenWidth / 2;
  int y_coord =50;
  int r = 20;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);
  x_coord+=xshift;
  y_coord+=yshift;
  u_int color = COLOR_SIENNA;

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}
//B-bottom outter circle
draw_circle2(int xshift, int yshift)
{
  int x_coord = (screenWidth / 2)+3;
  int y_coord = 78;
  int r = 24;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);
  x_coord+=xshift;
  y_coord+=yshift;
  u_int color = COLOR_SIENNA;

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}
//B-top inner circle
draw_circle3(int xshift, int yshift)
{
  int blue = 31, green = 0, red = 31;
  int x_coord = screenWidth / 2;
  int y_coord =50;
  int r = 10;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);
  x_coord+=xshift;
  y_coord+=yshift;
  u_int color = (blue << 0) | (green << 140) | (red<<255);

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}
//B-bottom inner circle
draw_circle4(int xshift, int yshift)
{
  int blue = 31, green = 0, red = 31;
  int x_coord = (screenWidth / 2)+3;
  int y_coord = 78;
  int r = 12;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);
  x_coord+=xshift;
  y_coord+=yshift;
  u_int color = (blue << 0) | (green << 140) | (red<<255);

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    //background circle

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}
draw_circle5(int xshift, int yshift)
  {
    
  int blue = 31, green = 0, red = 31;
  int x_coord = screenWidth / 2;
  int y_coord =66;
  int r = 50;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);
  x_coord+=xshift;
  y_coord+=yshift;
  u_int color =  (blue << 0) | (green << 140) | (red<<255);

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}
draw_circle6(int xshift, int yshift)
  {
    
  int blue = 0, green = 0, red = 0;
  int x_coord = screenWidth / 2;
  int y_coord =66;
  int r = 53;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);
  x_coord+=xshift;
  y_coord+=yshift;
  u_int color =  (blue) | (green) | (red);

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}
draw_BTC(int xShift, int yShift){
  draw_circle6(xShift, yShift);
  draw_circle5(xShift, yShift);
  draw_circle(xShift, yShift);
  draw_circle2(xShift, yShift);
  draw_rectangle(xShift, yShift);
  draw_rectangle2(xShift, yShift);
  draw_rectangle3(xShift, yShift);
  draw_circle3(xShift, yShift);
  draw_circle4(xShift, yShift);
  draw_rectangle4(xShift, yShift);
  draw_rectangle5(xShift, yShift);
  draw_rectangle6(xShift, yShift);
  draw_rectangle7(xShift, yShift);

}
