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
				  delay(100);          // for visualization of line- 
						             // generation step by step 
		    	} 
		}
};
// driver code 
int main() 
{    
	char choice;
	float x1,y1,x2,y2;
	printf("\nMENU:\n\t1.DDA\n\t2.Bresenham\nPlease Enter: ");
	scanf("%c",&choice);
	printf("Enter the Co-ordinates:\n\tx1: ");
	scanf("%f",&x1);
	printf("\tx2: ");
	scanf("%f",&x2);
	printf("\ty1: ");
	scanf("%f",&y1);
	printf("\ty2: ");
	scanf("%f",&y2);
	Line* l1= new Line;
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, NULL); 
	switch(choice)
	{
		case '1':
				l1->DDA(x1,y1,x2,y2);
				delay(10000);
				break;
		case '2':
				l1->Bresenham((int)x1,(int)y1,(int)x2,(int)y2);
				delay(10000);
				break;
		default:
				printf("\nWrong Choice entered try again next time ");
	}
	
	closegraph();
	return 0;
}
/*COMPILING:
g++ lineAlgo.cpp -lgraph
./a.outs*/
