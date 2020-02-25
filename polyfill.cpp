#include<iostream>
#include<graphics.h>
using namespace std;
void wait_for_char()
{

    //Wait for a key press
    int in = 0;

    while (in == 0) {
        in = getchar();
    }
}
class Pixel
{
	int x;
	int y;
	friend class Polygon;	
};
class Polygon
{
	Pixel* p;
	int noOfVertices;
	int Xmax,Xmin,Ymax,Ymin;
	public:
		Polygon(int n)
		{
			noOfVertices=n;
			p=new Pixel[noOfVertices]; 
			Xmax=Ymax=0;
		}
		void read()
		{
			cout<<"\nPlease enter "<<noOfVertices<<" vertices :\n";
			for (int i=0;i<noOfVertices;i++)
			{
				cout<<i+1<<" :\tEnter X: ";
				cin>>p[i].x;
				cout<<"\tEnter Y: ";
				cin>>p[i].y;
			}
		}
		void drawPoly()
		{
			for(int i=0;i<noOfVertices;i++)
			{
				if(i+1==noOfVertices)
					line(p[i].x,p[i].y,p[0].x,p[0].y);
				else
					line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
			}
		}
		void getMaxAndMin()
		{
			Xmin=p[0].x;
			Ymin=p[0].y;
			for(int i=0;i<noOfVertices;i++)
			{
				if(p[i].x>Xmax)
					Xmax=p[i].x;
				if(p[i].x<Xmin)
					Xmin=p[i].x;
				if(p[i].y>Ymax)
					Ymax=p[i].y;
				if(p[i].y<Ymin)
					Ymin=p[i].y;
			}
			cout<<"\nXmax :"<<Xmax<<"\nXmin :"<<Xmin<<"\nYmax :"<<Ymax<<"\nYmin :"<<Ymin<<endl;
		}
};
int main()
{
	cout<<"\nEnter the no of Vertices of the Polygon : ";
	int n;
	cin>>n;
	Polygon user(n);
	user.read();
	user.getMaxAndMin();
	int gd = DETECT, gm; 
  
    // initgraph initializes the graphics system 
    // by loading a graphics driver from disk 
    initgraph(&gd, &gm, NULL); 
	user.drawPoly();
	wait_for_char();
	closegraph();
	return 0;
}

