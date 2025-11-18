#include<stdio.h>
#include<math.h>
#include "draw.h"

void side_flocon(double x1, double y1, double x2, double y2, int m)
{
	if (m==0) // Straight line
	{
		draw_line(x1, y1, x2, y2, 1, 0, 0, 0);
	}

	else // Or continue
	{
		double X = x2-x1;
		double Y = y2-y1;
		double x1t = x1+X/3, y1t = y1+Y/3;
		double x2t = x1+2*(X)/3, y2t = y1+2*(Y)/3;
		double ymid = -(sqrt(3)/2)*(X/3);
		double xmid =  (sqrt(3)/2)*(Y/3);

		side_flocon(x1, y1, x1t, y1t, m-1);
		side_flocon(x1t, y1t, x1+(X/2)+xmid,y1+(Y/2)+ymid, m-1);
		side_flocon(x1+(X/2)+xmid, y1+(Y/2)+ymid, x2t, y2t, m-1);
		side_flocon(x2t, y2t, x2, y2, m-1);
	}
}

int flocon(int cx, int cy, int r, int m)
{
	for(int i=0; i < 3; i++)
	{
		double x1 = cx+r*cos(i*2*M_PI/3 + M_PI/6), y1 = cy+r*sin(i*2*M_PI/3 + M_PI/6);
		double x2 = cx+r*cos((i+1)*2*M_PI/3 + M_PI/6), y2 = cy+r*sin((i+1)*2*M_PI/3 + M_PI/6);
		side_flocon(x1, y1, x2, y2, m);
	}
	return 0;
}


int main()
{
	int m = 0;

	printf("inserez le nb d'ittération a  effectuer: ");
	scanf("%d", &m);

	draw_init("ex_4.svg", 400, 400);

	draw_line(0, 0, 0, 400, 5, 0, 0, 0);
	draw_line(0, 0, 400, 0, 5, 0, 0, 0);
	draw_line(400, 400, 400, 0, 5, 0, 0, 0);
	draw_line(400, 400, 0, 400, 5, 0, 0, 0);

	flocon(200, 200, 150, m);

	draw_close();
}