#include<iostream>
#include<graphics.h>
using namespace std;

void circle(int xc,int yc,int r)
{
	int x,y,d;
	x=0;
	y=r;
	d = 3-2*r;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
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
		delay(90);
	}while(x<=y);
	delay(3000);
	closegraph();
}

int main()
{
	int xc,yc,r;
	cout<<"\nEnter center of circle(x,y) : ";
	cin>>xc>>yc;
	cout<<"\nEnter radius of circle : ";
	cin>>r; 
	circle(xc,yc,r);
	return 0;
}
