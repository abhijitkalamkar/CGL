#include<iostream>
#include<graphics.h>
using namespace std;

class Algo{
public:
/*void swap(int *x1, int *y1, int *x2,int *y2)
{
	int *temp;
	*temp = *x1;
	*x2 = *x1;
	*x1 = *temp;
	int *temp2;
	*temp2 = *y1;
	*y2 = *y1;
	*y1 = *temp2;
}*/
void drawline(float x1,float y1,float x2,float y2)
{  
   int gd = DETECT,gm;
   initgraph(&gd,&gm,NULL);
   float dx,dy;
   dx = x2-x1;
   dy = y2-y1;
   int step;
   float xin,yin;
   if(abs(dx) > abs(dy))
		step = abs(dx);
   else
		step = abs(dy);
   xin = dx/step;
   yin = dy/step;
   float x = x1;
   float y = y1;
   for(int i = 0;i<step;i++)
	{
		x = x + xin;
		y = y + yin;
		putpixel(round(x),round(y),GREEN);
		delay(20);
	}
	closegraph();
}

void drawline(int x1,int y1,int x2,int y2)
{
	int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int dx,dy;
    dx = x2-x1;
    dy = y2-y1;
	int x,y;
	x = x1;
	y = y1;
	int p; 
	if(x1>x2 && y1>y2)
	{
		for(int i=0;i<abs(dy);i++)
		{
			x = x-1;
			y = y-1;
			putpixel(x,y,GREEN);
			delay(20);
		}
		delay(1000);
	}
    else if(abs(dx) > abs(dy))
	{
		p = 2*abs(dy) - abs(dx);
		putpixel(x,y,GREEN);
		for(int i=0;i<abs(dx);i++)
		{
			x =x+1;
			if(p<0)
				p = p+2*abs(dy);
			else
			{
				y = y+1;
				p = p+2*abs(dy)-2*abs(dx);
			}
			putpixel(x,y,GREEN);
			delay(20);
		}	
		delay(1000);
	}
	else if(abs(dx) < abs(dy))
	{
		p = 2*abs(dx) - abs(dy);
		putpixel(x,y,GREEN);
		for(int i=0;i<abs(dy);i++)
		{
			y =y+1;
			if(p<0)
				p = p+2*abs(dx);
			else
			{
				x = x+1;
				p = p+2*abs(dx)-2*abs(dy);
			}
			putpixel(x,y,GREEN);
			delay(20);
		}	
		delay(1000);
	}
	else
	{
		for(int i=0;i<abs(dy);i++)
		{
			x = x+1;
			y = y+1;
			putpixel(x,y,GREEN);
			delay(20);
		}
		delay(1000);
	}
	closegraph();
}
};
int main()
{
	int i;
	Algo a;
	cout<<"\nChoose any one operation:-> 1.DDA Algorithm\n 2.BRESENHAMS Algorithm\n";
	cin>>i;
	if(i==1)
	{
		float x1,y1,x2,y2;
		cout<<"Enter start and endpoints(x1,y1) (x2,y2) resp.: ";
		cin>>x1>>y1>>x2>>y2;
		
		a.drawline(x1,y1,x2,y2);
	}
	else if(i==2)
	{
		int x1,y1,x2,y2;
		cout<<"Enter start and endpoints(x1,y1) (x2,y2) resp.: ";
		cin>>x1>>y1>>x2>>y2;
		//if(x1>x2 || y1>y2)
			//a.swap(&x1,&y1,&x2,&y2);
		a.drawline(x1,y1,x2,y2);
	}
	
    return 0;
}
