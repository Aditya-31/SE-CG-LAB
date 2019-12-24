#include<graphics.h>
#include <iostream>
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    //rectangle(int left, int top, int right, int bottom);
    rectangle(100,100,400,400);
    rectangle(175,175,325,325);
    // line for x1, y1, x2, y2   
    line(250,100,100,250);
    line(250,100,400,250);
    line(100,250,250,400);
    line(400,250,250,400); 
    
    delay(5000);
    closegraph();
    return 0;
}
