#include <graphics.h> 
#include <stdio.h> 
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
	public:
		Pixel()
		{
		}
		void drawPixel(int X,int Y)
		{
			x=X;
			y=Y;
			putpixel(x,y,WHITE);
		}
};
class Line : public Pixel 
{
		Pixel p;
	public:
		Line()
		{
		}
		void Bresenham(int x1, int y1, int x2, int y2) 
		{ 
		   line(getmaxx()/2,0,getmaxx()/2,getmaxy());
		   line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
		   int m_new = 2 * (y2 - y1); 
		   int slope_error_new = m_new - (x2 - x1); 
		   for (int x = x1, y = y1; x <= x2; x++) 
		   { 
			  p.drawPixel (x,y);
		  
			  // Add slope to increment angle formed 
			  slope_error_new += m_new; 
		  
			  // Slope error reached limit, time to 
			  // increment y and update slope error. 
			  if (slope_error_new >= 0) 
			  { 
				 y++; 
				 slope_error_new  -= 2 * (x2 - x1); 
			  } 
		   } 
		} 
		void DDA(int x1,int y1,int x2,int y2)
		{
			//To Divide The Screen
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
				  p.drawPixel (X,Y);  // put pixel at (X,Y) 
				  X += incX;           // increment in x at each step 
				  Y += incY;           // increment in y at each step 
				  delay(10);          // for visualization of line- 
						             // generation step by step 
		    	} 
		}
};
int main()
{
	Line B;
	int x=100,y=100,l=140,b=90;
	int X=200,Y=400,a=50;
    int h=a*(int)1.73/2;
    printf("%d",h);
	//x1,y1,x2,y2
	int gd = DETECT, gm; 
    initgraph(&gd, &gm, "");  // initialize graph 
    /*A.DDA(x,y+b,x,y);
    A.DDA(x,y,x+l,y);
    A.DDA(x+l,y,x+l,y+b);
    A.DDA(x+l,y+b,x,y+b);
    
    A.DDA(x,y+(b/2),x+(l/2),y);
    A.DDA(x+(l/2),y,x+l,y+(b/2));
    A.DDA(x+l,y+(b/2),x+(l/2),y+b);
    A.DDA(x+(l/2),y+b,x,y+(b/2));
    
    A.DDA(x+(l/4),y+(3*b/4),x+(l/4),y+(b/4));
    A.DDA(x+(l/4),y+(b/4),x+(3*l/4),y+(b/4));
    A.DDA(x+(3*l/4),y+(b/4),x+(3*l/4),y+(3*b/4));
    A.DDA(x+(3*l/4),y+(3*b/4),x+(l/4),y+(3*b/4));
    */
    B.DDA(X,Y,X+a,Y);
    B.DDA(X+a,Y,X+a/2,Y-h);
    B.DDA(X+a/2,Y-h,X,Y);
    wait_for_char();
    closegraph();
	return 0;
}
