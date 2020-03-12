#include <graphics.h>
#include <iostream>
#include<math.h>
using namespace std;

class draw
{
public:
	void drawlineDOT(float x1,float y1,float x2,float y2)
	{
		int gd = DETECT, gm;
		initgraph(&gd, &gm, NULL);
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
			if(i%2 == 0)
				putpixel(round(x1), round(y1), GREEN);
			delay(10);
		}

		delay(5000);
		closegraph();
	}
	void drawlineDASH(float x1,float y1,float x2,float y2)
	{
		int gd = DETECT, gm;
		initgraph(&gd, &gm, NULL);
		int step;
		float dx = x2 - x1;
		float dy = y2 - y1;

		if (abs(dx) > abs(dy))
			step = abs(dx);
		else
			step = abs(dy);

		float xin = dx / step;
		float yin = dy / step;
		
		int count = 5;
		for (int i = 0; i < step; i++)
		{

			x1 = x1 + xin;
			y1 = y1 + yin;
			if(count > 0)
				putpixel(round(x1), round(y1), GREEN);
			count--;
			if(count == -5)
				count = 5;
			delay(10);
		}

		delay(5000);
		closegraph();
	}
	void drawlineDOTDASH(float x1,float y1,float x2,float y2)
	{
		int gd = DETECT, gm;
		initgraph(&gd, &gm, NULL);
		int step;
		float dx = x2 - x1;
		float dy = y2 - y1;

		if (abs(dx) > abs(dy))
			step = abs(dx);
		else
			step = abs(dy);

		float xin = dx / step;
		float yin = dy / step;
		
		int count = 5;
		for (int i = 0; i < step; i++)
		{

			x1 = x1 + xin;
			y1 = y1 + yin;
			if(count > 0)
				putpixel(round(x1), round(y1), GREEN);
			count--;
			if(count == -3)
				putpixel(round(x1), round(y1), GREEN);
			if(count == -5)
				count = 5;
			delay(10);
		}

		delay(5000);
		closegraph();
	}
	void drawlineTHICK(float x1,float y1,float x2,float y2,int w)
	{
		int gd = DETECT, gm;
		initgraph(&gd, &gm, NULL);
		float dx = x2 - x1;
		float dy = y2 - y1;
		float xin,yin;
		int step;
		if (abs(dx) > abs(dy))
		{
			w = (((w -1)/2) * (sqrt((dx * dx) + (dy * dy)))/abs(dx));
			cout<<"Wy"<<w;
			step = abs(dx);
			xin = dx / step;
			yin = dy / step;
			for(int i=0;i<step;i++)
			{
				for(int j=0;j<abs(w);j++)
				{
					putpixel(round(x1), round(y1 + j), GREEN);
					putpixel(round(x1), round(y1 - j), GREEN);
				}
				x1 = x1 + xin;
				y1 = y1 + yin;
				delay(10);
			}
		}
		else
		{
			w = (((w -1)/2) * (sqrt((dx * dx) + (dy * dy)))/abs(dy));
			cout<<"Wx"<<w;
			step = abs(dx);
			xin = dx / step;
			yin = dy / step;
			for(int i=0;i<step;i++)
			{
				for(int j=0;j<abs(w);j++)
				{
					putpixel(round(x1 - j), round(y1), GREEN);
					putpixel(round(x1 + j), round(y1), GREEN);
				}
				x1 = x1 + xin;
				y1 = y1 + yin;
				delay(10);
			}
		}
		delay(5000);
		closegraph();
	}
};
int main()
{
    draw obj;
    float a, b, c, d;
    int width,choice;
 do
    {

        cout << "\n Enter the line drawing algorithm to use";
        cout << "\n 1) Dotted Line ";
        cout << "\n 2) Dashed Line ";
        cout << "\n 3) Dotted-Dashed Line ";
        cout << "\n 4) Thick Line ";
        cin >> choice;

        switch (choice)
        {

        case 1:

            cout << "\n Enter First co-ordinantes x1,y1 ";
            cin >> a >> b;
            cout << "\n Enter Second co-ordinantes x2,y2 ";
            cin >> c >> d;
            obj.drawlineDOT(a, b, c, d);
            break;

        case 2:

            cout << "\n Enter First co-ordinantes x1,y1 ";
            cin >> a >> b;
            cout << "\n Enter Second co-ordinantes x2,y2 ";
            cin >> c >> d;
            obj.drawlineDASH(a, b, c, d);
            break;

        case 3:

            cout << "\n Enter First co-ordinantes x1,y1 ";
            cin >> a >> b;
            cout << "\n Enter Second co-ordinantes x2,y2 ";
            cin >> c >> d;
            obj.drawlineDOTDASH(a, b, c, d);
            break;

        case 4:
            cout << "\n Enter First co-ordinantes x1,y1 ";
            cin >> a >> b;
            cout << "\n Enter Second co-ordinantes x2,y2 ";
            cin >> c >> d;
            cout << "\n Enter the width ";
            cin >> width;

            obj.drawlineTHICK(a, b, c, d, width);
            break;

        case 5:
            break;

        default:
            cout << "\n You Entered wrong choice";
        }

    } while (choice > 5);
return 0;
}

