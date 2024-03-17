#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <cmath>
#include <math.h>


void plotEllipsePoints(int xc, int yc, int x, int y) {
    delay(50);
    putpixel(xc + x, yc - y, GREEN); 
    putpixel(xc - x, yc - y, RED); 
    putpixel(xc + x, yc + y, YELLOW);
    putpixel(xc - x, yc + y, BLUE);
}

void midpointEllipse(int xc, int yc, int rx, int ry) {
    int x = 0;
    int y = ry;
    int rxSq = rx * rx;
    int rySq = ry * ry;
    int twoRxSq = 2 * rxSq;
    int twoRySq = 2 * rySq;
    int p;

    // Region 1
    int p1 = rySq - rxSq * ry + 0.25 * rxSq;
    while (twoRySq * x < twoRxSq * y) {
        plotEllipsePoints(xc, yc, x, y);
        x++;
        if (p1 < 0) {
            p1 += rySq + twoRySq * x;
        }
        else {
            y--;
            p1 += rySq + twoRySq * x - twoRxSq * y;
        }
    }

    // Region 2
    int p2 = rySq * (x + 0.5) * (x + 0.5) + rxSq * (y - 1) * (y - 1) - rxSq * rySq;
    while (y >= 0) {
        plotEllipsePoints(xc, yc, x, y);
        y--;
        if (p2 > 0) {
            p2 += rxSq - twoRxSq * y;
        }
        else {
            x++;
            p2 += rxSq - twoRxSq * y + twoRySq * x;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    int screenWidth = getmaxx();
    int screenHeight = getmaxy();

    int xc, yc, rx, ry;
    std::cout << "Enter the center coordinates (xc yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter the major and minor axis lengths (rx ry): ";
    std::cin >> rx >> ry;
    rx = abs(rx);
    ry = abs(ry);

    xc = xc + screenWidth / 2;
    yc = screenHeight / 2 - yc; 

    line(screenWidth/2, 0, screenWidth/2, screenHeight); 
    line(0, screenHeight/2, screenWidth, screenHeight/2); 

    midpointEllipse(xc, yc, rx, ry);
    delay(500);

    closegraph();
    return 0;
}
