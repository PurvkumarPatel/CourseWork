#include <graphics.h>
#include <iostream>
void plotEllipsePoints(int xc, int yc, int x, int y) {
    delay(80);
    putpixel(xc + x, yc - y, 15); 
    putpixel(xc - x, yc - y, 15); 
    putpixel(xc + x, yc + y, 15);
    putpixel(xc - x, yc + y, 15);
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

void boundaryFill4(int x, int y, int fill_color, int boundary_color)
{
    if ((getpixel(x, y) != boundary_color) && (getpixel(x, y) != fill_color))
    {
        putpixel(x, y, fill_color);
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
}

void floodFill(int x, int y, int &fill_color, int oldColor)
{
    if (getpixel(x, y) == oldColor)
    {
        putpixel(x, y, fill_color);
        floodFill(x + 1, y, fill_color, oldColor);
        floodFill(x - 1, y, fill_color, oldColor);
        floodFill(x, y + 1, fill_color, oldColor);
        floodFill(x, y - 1, fill_color, oldColor);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int screenWidth = getmaxx(); 
    int screenHeight = getmaxy(); 

    int x, y, x1, y1, r = 100;

    int choice;
    while (true)
    {
        std::cout << "Menu:\n";
        std::cout << "1. Boundary Fill\n";
        std::cout << "2. Flood Fill\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (choice == 3 )
            break;

        int fillColor;
        std::cout << "Enter the fill color in circle (integer code): ";
        std::cin >> fillColor;
        // std::cout << "Enter the corrdinate of circle (x,y): ";
        // std::cin >> x1>>y1;
    int xc, yc, rx, ry;
    std::cout << "Enter the center coordinates of Eclipes(xc yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter the major and minor axis lengths (rx ry): ";
    std::cin >> rx >> ry;
    rx = abs(rx);
    ry = abs(ry);

        // int centerX = getmaxx() / 2;
        // int centerY = getmaxy() / 2;

        // int x = x1 + centerX;
        // int y = centerY - y1;
    xc = xc + screenWidth / 2;
    yc = screenHeight / 2 - yc; 

    // line(screenWidth/2, 0, screenWidth/2, screenHeight); 
    // line(0, screenHeight/2, screenWidth, screenHeight/2); 

    midpointEllipse(xc, yc, rx, ry);
    // delay(750);
        //cleardevice();
        //line_styles(GREEN); 
        // line(screenWidth/2, 0, screenWidth/2, screenHeight); 
        // line(0, screenHeight/2, screenWidth, screenHeight/2); 
        //circle(x, y, r);

        if (choice == 1)
        {
            boundaryFill4(xc, yc, fillColor, 15);
            delay(1500);
        }
        else if (choice == 2)
        {
            int oldColor = getpixel(x, y);
            floodFill(xc, yc, fillColor, oldColor);
            delay(1500);
        }

        cleardevice(); 
    }

    closegraph();
    return 0;
}
