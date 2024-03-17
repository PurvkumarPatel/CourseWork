#include <graphics.h>
#include<iostream>
#include<stdio.h>
using namespace std;
main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = getmaxx(); // to get the co-ordinates i.e. x & y
    int y = getmaxy();

    
    line(x/2, 0, x/2, y); //vertical line 
    line(0,y/2,x,y/2);//quadrant partitions
    
    int x1, y1 , x2 , y2;
    cout<<"Enter x1 : ";
    cin>>x1;
    cout<<"Enter y1 : ";
    cin>>y1;
    cout<<"Enter x2 : ";
    cin>>x2;
    cout<<"Enter y2 : ";
    cin>>y2;
    x1 = x1 + x/2;
    x2 = x2 + x/2;
    y1 = y/2 - y1;
    y2 = y/2 - y2;

    int dx = x2 - x1;
    int dy = y2 - y1;
    float m = dy / dx;
    int p = 0;
    int n;
    while(1){
    cout<<"Enter Choice: \n 1: DDA \n 2: Bresenham \n 3: Mid-Point \n 4: Exit \n";
    cin>>n;
    if(n == 4){
        return -1;
    }
    if(n == 1){
        //digital differntial alnalyzer
        while(x1 < x2 || y1 < y2){
                if(abs(dx) - abs(dy) >= 0){
                    dx = 1;
                    x1 = x1 + 1;
                    y1 = y1 + m;
                }
                else{
                    dy = 1;
                    x1 = x1 + 1/m;
                    y1 = y1 + 1;
                }
                putpixel(x1, y1, GREEN);
                delay(100);
            }
    }
    else if( n == 2){
        int p = 0;
        p = 2 * dy - dx;
            while(x1 < x2 || y1 < y2){
                if(p >= 0){
                    p = p + 2 * (dy - dx);
                    x1 = x1 + 1;
                    y1 = y1 + 1;
                }
                else{
                    p = p + 2 * dy;
                    x1 = x1 + 1;
                }
                putpixel(x1, y1, BLUE);
                delay(50);
            }
    }
    else if (n == 3){
        int p = 0;
        p = 2 * dy - dx;
        while(x1 < x2 || y1 < y2){
                    int dinitial = 2*dy - dx;
                    int deltad = 2 * (dy - dx);
                    if(dinitial >= 0){
                        x1 = x1 + 1;
                        y1 = y1 + 1;
                        dinitial  = dinitial + deltad;
                    }
                    else{
                        x1 = x1 + 1;
                        dinitial = dinitial + 2 * dy;
                    }
                    putpixel(x1, y1, YELLOW);
                    delay(50);
                }
    }
    delay(100);
    }
}