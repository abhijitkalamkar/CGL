#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void drawline(float x1, float y1, float x2, float y2)
{
	int step;
	float dx = x2 - x1;
	float dy = y2 - y1;
	if (abs(dx) > abs(dy))
		step = abs(dx);
		
	else
		step = abs(dy);
		
	float xin = dx / step;
	float yin = dy / step;
	for (int i = 0; i < step; i++)
	{
		x1 = x1 + xin;
		y1 = y1 + yin;
		putpixel(round(x1), round(y1), GREEN);
		delay(10);
	}
	delay(100);
}

void circle(int xc,int yc,int r)
{
	int x,y,d;
	x=0;
	y=r;
	d = 3-2*r;
	do
	{
		putpixel(x+xc,y+yc,GREEN);
		putpixel(x+xc,-y+yc,GREEN);
		putpixel(-x+xc,-y+yc,GREEN);
		putpixel(-x+xc,y+yc,GREEN);
		putpixel(y+xc,x+yc,GREEN);
		putpixel(-y+xc,-x+yc,GREEN);
		putpixel(y+xc,-x+yc,GREEN);
		putpixel(-y+xc,x+yc,GREEN);
		
		x = x+1;
		if(d<0)
		{
			d = d+4*x+6;
		}
		else
		{
			y = y-1;
			d = d+4*(x-y)+10;
		}
		delay(10);
	}while(x<=y);
	delay(700);
}
int main()
{
	int xc,yc,r;
	cout<<"\nEnter Center of circle(xc,yc) : ";
	cin>>xc>>yc;
	cout<<"\nEnter Radius of outer circle : ";
	cin>>r;
	
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	// Outer circle
	circle(xc,yc,r);
	
	//Triangle
	drawline(xc,yc-r,xc-sqrt(3)*r/2,yc+r/2);
	drawline(xc-sqrt(3)*r/2,yc+r/2,xc+sqrt(3)*r/2,yc+r/2);
	drawline(xc+sqrt(3)*r/2,yc+r/2,xc,yc-r);
	
	// Inner circle
	circle(xc,yc,r/2);
	
	closegraph();
	
	return 0;
}
