#include<stdio.h>
#include "draw.h"
#include <math.h>

void polygon(double x, double y, double R, double sides, int w, int r, int g, int b)
{
    for(double angle=0; angle < 2*M_PI; angle += 2*M_PI/sides)
    {
        draw_line(x+cos(angle)*R, y+sin(angle)*R, x+cos(angle+(2*M_PI/sides))*R, y+sin(angle+(2*M_PI/sides))*R, w, r, g, b);
    }
}

int main()
{
    draw_init("ex_2.svg", 400, 400);

    draw_line(0, 0, 0, 400, 5, 0, 0, 0);
	draw_line(0, 0, 400, 0, 5, 0, 0, 0);
	draw_line(400, 400, 400, 0, 5, 0, 0, 0);
	draw_line(400, 400, 0, 400, 5, 0, 0, 0);

    int n, d;
    printf("inserez le nb de lignes/colonnes: ");
	scanf("%d",&n);

    d = (380 - (n-1)*5)/n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            double xc = 10 + (d/2) + j*(d) + j*5;
            double yc = 10 + (d/2) + i*(d) + i*5;
            polygon(xc, yc, d/2, 3+j, 1, 255 - (255/n)*i, (255/n)*i, 0);
        }
    }
    

    draw_close();
}