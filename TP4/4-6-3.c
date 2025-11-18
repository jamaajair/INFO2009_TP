#include<stdio.h>
#include "draw.h"
#include <math.h>

void triangle(double x, double y, double R, double angle)
{
    for(double a=angle; a < 2*M_PI; a += 2*M_PI/3)
    {
        draw_line(x+cos(a)*R, y+sin(a)*R, x+cos(a+(2*M_PI/3))*R, y+sin(a+(2*M_PI/3))*R, 1, 0, 0, 0);
    }
}

void sierpinski(double x, double y, double r, int n)
{
    if(n > 0)
    {
        triangle(x, y, r, -M_PI/6);

        for(int i=0; i<3; i++)
        {
            double xs = x + r*cos(M_PI/6 + i*2*(M_PI/3));
            double ys = y + r*sin(M_PI/6 + i*2*(M_PI/3));
            sierpinski(xs, ys, r/2, n-1);
        }
    }

    else
        return;
}

int main()
{
    draw_init("ex_3.svg", 400, 400);

    draw_line(0, 0, 0, 400, 5, 0, 0, 0);
	draw_line(0, 0, 400, 0, 5, 0, 0, 0);
	draw_line(400, 400, 400, 0, 5, 0, 0, 0);
	draw_line(400, 400, 0, 400, 5, 0, 0, 0);

    int n;
    printf("inserez la profondeur: ");
	scanf("%d",&n);

    triangle(200, 200, 100, M_PI/6);
    sierpinski(200, 200, 50, n);
    

    draw_close();
}