#include <graphics.h> 
#include <stdio.h> 
class Pixel
{
	int x;
	int y;
	int color;
	friend class Line;
};
class Line
{
		Pixel p;
	public:
		Line()
		{
		}
		void DDA(int x1,int y1,int x2,int y2)
		{
			line(getmaxx()/2,0,getmaxx()/2,getmaxy());
			line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
			//find dx,dy
			int dx=x2-x1;
			int dy=y2-y1;
			//the greater one becomes no of steps
			int steps= abs(dx)>abs(dy)? abs(dx):abs(dy);
			float incX = dx / (float) steps; 
		   	float incY = dy / (float) steps; 
		  
		   	// Put pixel for each step 
		    	float X = x1; 
		    	float Y = y1; 
		    	for (int i = 0; i <= steps; i++) 
		    	{ 
			  putpixel (X,Y,WHITE);  // put pixel at (X,Y) 
			  X += incX;           // increment in x at each step 
			  Y += incY;           // increment in y at each step 
			  delay(100);          // for visualization of line- 
				                 // generation step by step 
		    	} 
		}
};
// driver code 
int main() 
{    
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, NULL); 
	Line l1;
	l1.DDA(100,200,300,400);
	delay(10000);
	return 0;
}
