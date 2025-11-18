#include<stdio.h>
#include "draw.h"

int main()
{
    draw_init("ex_1b.svg", 400, 400);

    draw_line(0, 0, 0, 400, 5, 0, 0, 0);
	draw_line(0, 0, 400, 0, 5, 0, 0, 0);
	draw_line(400, 400, 400, 0, 5, 0, 0, 0);
	draw_line(400, 400, 0, 400, 5, 0, 0, 0);

    for(int i=0; i<=200; i += 10)
    {
        draw_line(200, 400-i, 200+i, 200, 2, 255, 0, 0); // bottom right
        draw_line(200, 400-i, 200-i, 200, 2, 255, 0, 0); // bottom left
        draw_line(200, i, 200+i, 200, 2, 255, 0, 0); // upper right
        draw_line(200, i, 200-i, 200, 2, 255, 0, 0); // upper left
    }

    draw_close();
}