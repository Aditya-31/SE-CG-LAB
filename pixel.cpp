#include <graphics.h> 
#include <stdio.h> 
  
// driver code 
int main() 
{ 
    // gm is Graphics mode which is 
    // a computer display mode that 
    // generates image using pixels. 
    // DETECT is a macro defined in 
    // "graphics.h" header file 
    int gd = DETECT, gm; 
  
    // initgraph initializes the 
    // graphics system by loading a 
    // graphics driver from disk 
    initgraph(&gd, &gm, NULL); 
  
    // putpixel function 
    //putpixel(int x, int y, int color);
    putpixel(85, 35, GREEN); 
    putpixel(30, 40, RED); 
    putpixel(115, 50, YELLOW); 
    putpixel(135, 50, CYAN); 
    putpixel(45, 60, BLUE); 
    putpixel(20, 100, WHITE); 
    putpixel(200, 100, LIGHTBLUE); 
    putpixel(150, 100, LIGHTGREEN); 
    putpixel(200, 50, YELLOW); 
    putpixel(120, 70, RED); 
  	delay(10000);
    // closegraph function closes the 
    // graphics mode and deallocates 
    // all memory allocated by 
    // graphics system . 
    closegraph(); 
  
    return 0; 
} 
/*EXECUTION:
pliii@pliii-HP-280-G2-MT-Legacy:~$ cd SEA18
pliii@pliii-HP-280-G2-MT-Legacy:~/SEA18$ g++ assign1.cpp -lgraph
pliii@pliii-HP-280-G2-MT-Legacy:~/SEA18$ ./a.out



OUTPUT is Obtained in a separate window*/
