#include<graphics.h>
#include <iostream>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    //get maximum X
    cout<<endl<<"MAX X:"<<getmaxx();
    //get maximum Y
    cout<<endl<<"MAX Y:"<<getmaxy();
    putpixel(getmaxx(),getmaxy(),RED);
    delay(5000);
    closegraph();
    return 0;
}
