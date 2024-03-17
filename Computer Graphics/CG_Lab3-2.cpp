#include <graphics.h>
#include <iostream>

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

    int x, y, radius = 100;

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

        x = screenWidth / 2;
        y = screenHeight / 2;

        cleardevice(); 

        circle(x, y, radius);

        if (choice == 1)
        {
            boundaryFill4(x, y, fillColor, 15);
            delay(1000);
        }
        else if (choice == 2)
        {
            int oldColor = getpixel(x, y);
            floodFill(x, y, fillColor, oldColor);
            delay(1000);
        }

        cleardevice(); 
    }

    closegraph();
    return 0;
}
