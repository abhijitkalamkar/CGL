#include<iostream>
#include<graphics.h>
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

void shape(float x,float y,float l,float b)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	//outer rectangle
	drawline(x,y,x+l,y);
	drawline(x,y,x,y+b);
	drawline(x,y+b,x+l,y+b);
	drawline(x+l,y,x+l,y+b);
	
	//Diamond
	drawline(x+l,y+b/2,x+l/2,y);
	drawline(x,y+b/2,x+l/2,y);
	drawline(x+l,y+b/2,x+l/2,y+b);
	drawline(x+l/2,y+b,x,y+b/2);
	
	//inner rectangle
	drawline(x+l/4,y+b/4,x+l/4,y+3*b/4);
	drawline(x+l/4,y+3*b/4,x+3*l/4,y+3*b/4);
	drawline(x+3*l/4,y+3*b/4,x+3*l/4,y+b/4);
	drawline(x+3*l/4,y+b/4,x+l/4,y+b/4);
	
	closegraph();
}

int main()
{
	float x,y,l,b;
	cout<<"\nEnter top left corner of rectangle(x,y) : ";
	cin>>x>>y;
	cout<<"\nEnter length and breadth of rectangle : ";
	cin>>l>>b;
	shape(x,y,l,b);
	return 0;
} 
