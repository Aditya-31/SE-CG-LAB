/*
	Aditya Gade SEA18
	Write C++Java program to fill polygon using scan line algorithm.
*/
#includegraphics.h
#includeiostream
#includestdlib.h
#includemath.h
using namespace std;

class polygon
{
	public
		int x[10],y[10];
		int min_y,max_y,y_val;
		int n,i;
		int cnt;
		float m[20],xint[200];
		void draw_poly();
		void scanline();
		void sort(float[],int);
		void floodfill(int,int,int,int);
		void boundaryFill(int,int,int,int);
		
};

void polygondraw_poly()
{
	coutnEnter no of vertices;
	cinn;
	if(n3)
	{
		coutnError;
		exit(0);
	}
	else
	{
		for(i=0;in;i++)
		{
			cinx[i];
			ciny[i];
		}
		x[n]=x[0];
		y[n]=y[0];
		for(i=0;in;i++)
		{
			line(x[i],y[i],x[i+1],y[i+1]);
		}
	}
}
void polygonscanline()
{
	draw_poly();
	setcolor(BLUE);
	min_y=480;
	max_y=0;
	for(i=0;in;i++)
	{
		if(min_y = y[i])
			min_y=y[i];
		
		if(y[i]= max_y)
			max_y=y[i];
		
		int dx=x[i+1]-x[i];
		int dy=y[i+1]-y[i];
		if(dx==0)
		{
			m[i]=0;
		}
		else if(dy==0)
		{
			m[i]=1;
		}
		else
		{
			m[i]=(dydx);
		}
		coutm[i];
	}
	
	for(y_val=max_y;y_val=min_y;y_val--)
	{
		cnt=0;
		for(i=0;in;i++)
		{
			if((y[i]y_val && y[i+1]=y_val)  (y[i]=y_val && y[i+1]y_val))
			{
				if (m[i]!=0)
					xint[cnt]=x[i]+((y_val-y[i])m[i]);
				else
					xint[cnt]=x[i];
				cnt++;
			}
		}
		sort(xint,cnt);

		for(int k=0;kcnt-1;k=k+2)
		{
			line(xint[k],y_val,xint[k+1],y_val);
			delay(50);
		}
	}

}

void polygonsort(float xint[],int cnt)
{
	float temp;
	for(int i=0;icnt;i++)
	{
		for(int j=0;jcnt-1;j++)
		{
			if(xint[i]  xint[j])
			{
				temp=xint[j];
				xint[j]=xint[j+1];
				xint[j+1]=temp;
			}
		}
	}
}

void polygonfloodfill(int x,int y,int new_color,int old_color)		 also called as SeedFill
{ 
    if (getpixel(x,y) == old_color) 						OR (getpixel(x,y) != new_color) 
    { 	
        putpixel(x,y,new_color);  put new pixel with new color 
  
        floodfill(x+1,y,new_color,old_color); 
  	  floodfill(x-1,y,new_color,old_color); 
  	  floodfill(x,y+1,new_color,old_color); 
  	  floodfill(x,y-1,new_color,old_color); 
    }

}

void polygonboundaryFill(int x, int y, int new_color,int old_color)
{
    if(getpixel(x,y) != old_color && getpixel(x,y) != new_color)
    {
        putpixel(x,y,new_color);
        boundaryFill(x+1,y,new_color,old_color);
        boundaryFill(x,y+1,new_color,old_color);
        boundaryFill(x-1,y,new_color,old_color);
        boundaryFill(x,y-1,new_color,old_color);
    }
}

int main()
{
	int gd,gm;
	int new_color,x,y,ch;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	
	polygon p;
	do
	{
		coutn1.Scanline algorithmn2.Floodfill algorithmn3.Boundaryfill algorithm;
		coutnEnter choice;
		cinch;
		switch(ch)
		{
			case 1
				p.scanline();
				break;
			case 2
				p.draw_poly();
				coutnEnter x and y ;
				cinxy;
				p.floodfill(x,y,BLUE,BLACK);			SeedFill
				break;
			case 3
				p.draw_poly();
				coutnEnter x and y ;
				cinxy;
				p.boundaryFill(x,y,YELLOW,15);
				break;
			default
				coutnEnter valid choice;
		}
	}while(ch4);
	
	getch();
	closegraph();
	return 0;
}