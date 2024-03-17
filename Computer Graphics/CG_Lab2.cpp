#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>

void drawCircleBresenham(int centerX, int centerY, int radius) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (y >= x) {
        putpixel(centerX + x, centerY + y, GREEN);
        putpixel(centerX - x, centerY + y, GREEN);
        putpixel(centerX + x, centerY - y, GREEN);
        putpixel(centerX - x, centerY - y, GREEN);
        putpixel(centerX + y, centerY + x, GREEN);
        putpixel(centerX - y, centerY + x, GREEN);
        putpixel(centerX + y, centerY - x, GREEN);
        putpixel(centerX - y, centerY - x, GREEN);

        if (d <= 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
        delay(50);
    }
}

void drawCircleMidPoint(int centerX, int centerY, int radius) {
    int x = radius;
    int y = 0;
    int decisionOver2 = 1 - x;

    while (y <= x) {
        putpixel(centerX + x, centerY - y, MAGENTA);
        putpixel(centerX + y, centerY - x, MAGENTA);
        putpixel(centerX - y, centerY - x, MAGENTA);
        putpixel(centerX - x, centerY - y, MAGENTA);
        putpixel(centerX - x, centerY + y, MAGENTA);
        putpixel(centerX - y, centerY + x, MAGENTA);
        putpixel(centerX + y, centerY + x, MAGENTA);
        putpixel(centerX + x, centerY + y, MAGENTA);
        y++;

        if (decisionOver2 <= 0) {
            decisionOver2 += 2 * y + 1;
        } else {
            x--;
            decisionOver2 += 2 * (y - x) + 1;
        }
        delay(50);
    }
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int choice;
    int centerX, centerY, radius;
    int screenWidth = getmaxx();
    int screenHeight = getmaxy();

    while (true) {
        cleardevice();
        std::cout << "1. Bresenham Algorithm\n";
        std::cout << "2. Midpoint Algorithm\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 3) {
            break;
        }

        std::cout << "Enter center (x, y): ";
        std::cin >> centerX >> centerY;
        
        // Adjust center to be relative to the center of the screen
        centerX += screenWidth / 2;
        centerY = screenHeight / 2 - centerY; // Invert y-coordinate to match screen coordinates
        
        line(screenWidth/2, 0, screenWidth/2, screenHeight); // Vertical line
        line(0, screenHeight/2, screenWidth, screenHeight/2); // Quadrant partitions
        
        std::cout << "Enter radius: ";
        std::cin >> radius;
        radius = abs(radius);

        switch (choice) {
            case 1:
                drawCircleBresenham(centerX, centerY, radius);
                break;
            case 2:
                drawCircleMidPoint(centerX, centerY, radius);
                break;
            default:
                std::cout << "Invalid choice\n";
        }

        delay(500); // Delay to observe the drawn circle
    }

    closegraph();
    return 0;
}
