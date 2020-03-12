#include<iostream>
#include<graphics.h>
using namespace std;
void boundary_fill(int x,int y,int f_color,int b_color)
{
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
	{
		putpixel(x,y,f_color);
		delay(1);
		boundary_fill(x+1,y,f_color,b_color);
		boundary_fill(x,y+1,f_color,b_color);
		boundary_fill(x-1,y,f_color,b_color);
		boundary_fill(x,y-1,f_color,b_color);
	}
}
void flood_fill(int x,int y,int old_color,int new_color)
{
	if(getpixel(x,y)==old_color)
	{
		putpixel(x,y,new_color);
		delay(1);
		flood_fill(x+1,y,old_color,new_color);
		flood_fill(x,y+1,old_color,new_color);
		flood_fill(x-1,y,old_color,new_color);
		flood_fill(x,y-1,old_color,new_color);
		flood_fill(x+1,y+1,old_color,new_color);
		flood_fill(x-1,y-1,old_color,new_color);
		flood_fill(x+1,y-1,old_color,new_color);
		flood_fill(x-1,y+1,old_color,new_color);
	}
}
int main()
{
	int x1,y1,x2,y2,ch,f_color=BLUE,b_color=WHITE;
	int old_color=BLACK,new_color=BLUE;
	
	do
	{
		cout<<"\n1: Boundary Fill";
		cout<<"\n2: Flood Fill";
		cout<<"\n3: Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		if(ch==1)
		{
			cout<<"\nEnter coordinates of rectangle(x1,y1),(x2,y2) : ";
			cin>>x1>>y1>>x2>>y2;
			int gd = DETECT, gm;
			initgraph(&gd, &gm, NULL);
			rectangle(x1,y1,x2,y2);
			//arc(x1+(x2-x1)/2,y1+(y2-y1)/2,0,180,(y2-y1)/4);
			boundary_fill(x1+1,y1+1,f_color,b_color);
			delay(400);
			closegraph();
		}
		else if(ch==2)
		{
			cout<<"\nEnter coordinates of rectangle(x1,y1),(x2,y2) : ";
			cin>>x1>>y1>>x2>>y2;
			int gd = DETECT, gm;
			initgraph(&gd, &gm, NULL);
			rectangle(x1,y1,x2,y2);
			//circle(x1+(x2-x1)/2,y1+(y2-y1)/2,(y2-y1)/4);
			flood_fill(x1+1,y1+1,old_color,new_color);
			delay(400);
			closegraph();
		}
		else if(ch==3)
		{
			break;
		}
	}while(ch!=3);
	
	return 0;
}
