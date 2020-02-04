/*References: https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/*/
#include<graphics.h>
#include<stdio.h>
class Pixel
{
	int x;
	int y;
	public:
		Pixel()
		{
			/*printf("\nPlease Enter X Co-ordinate of the centre of circle:");
    		scanf("%d",&x);
  			printf("\nPlease Enter Y Co-ordinate of the centre of circle:");
  			scanf("%d",&y);*/
		}
		Pixel(int X,int Y)
		{
			x=X;
			y=Y;
		}
		void operator =(Pixel& p)
		{
			x=p.x;
			y=p.y;
		}
		void drawPixel(int X,int Y)
		{
			x=X;
			y=Y;
			putpixel(x,y,WHITE);
		}
		int getX(){ return x;}
		int getY(){ return y;}
};
class Circle : public Pixel
{
	Pixel centre;
	int radius;
	public:
		Circle()
		{
			//printf("\nPlease Enter Radius:");
			//scanf("%d",&radius);
		}
		Circle(int x, int y,int r)
		{
			radius=r;
		}
		void drawCircle()
		{
			int x=0,y=centre.getY();
			int d = 3-(2*radius);
			drawPoints(x,y);
			while(!x>y)
			{
				x++;
				if(d<0)
					d+=(4*x)+6;
				else
				{
					d+=4*(x-y)+10;
					y--;
				}
				drawPoints(x,y);
			}
		}
		void drawPoints(int x,int y)
		{	
			centre.drawPixel(centre.getX()+x, centre.getY()+y);
			centre.drawPixel(centre.getX()-x, centre.getY()+y);
			centre.drawPixel(centre.getX()+x, centre.getY()-y);
			centre.drawPixel(centre.getX()-x, centre.getY()-y);
			
			centre.drawPixel(centre.getX()+y, centre.getY()+x);
			centre.drawPixel(centre.getX()-y, centre.getY()+x);
			centre.drawPixel(centre.getX()+y, centre.getY()-x);
			centre.drawPixel(centre.getX()-y, centre.getY()-x);
		}
};
int main()
{
	Circle c(50,50,50);
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, "");  // initialize graph 
	c.drawCircle();
	closegraph();
	return 0;
}
