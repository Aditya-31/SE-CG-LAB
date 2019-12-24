#include<graphics.h>
#include <iostream>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    
    /*circle(x, y, radius);
	where,
	(x, y) is center of the circle.
	'radius' is the Radius of the circle.*/
	
	circle(200,200,200);
	delay(5000);
	closegraph();
    return 0;
}
