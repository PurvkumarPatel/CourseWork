#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>

using namespace std;

void drawQuadraticBezier(int x0, int y0, int x1, int y1, int x2, int y2) {
    float t;
    cout<<'x'<<"   "<<'y'<<endl;
    int c = 0;
    for (t = 0.0; t <= 1.0; t += 0.001) {
        float x = (1 - t) * (1 - t) * x0 + 2 * (1 - t) * t * x1 + t * t * x2;
        float y = (1 - t) * (1 - t) * y0 + 2 * (1 - t) * t * y1 + t * t * y2;
        c++;
        if(c % 30 == 0){
        cout<<x<<" "<<y<<endl;
        }
        putpixel(x, y, WHITE);
    }
}

void drawCubicBezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    float t;
    cout<<'x'<<"   "<<'y'<<endl;
    int c = 0;
    for (t = 0.0; t <= 1.0; t += 0.001) {
        float x = pow(1 - t, 3) * x0 + 3 * t * pow(1 - t, 2) * x1 + 3 * pow(t, 2) * (1 - t) * x2 + pow(t, 3) * x3;
        float y = pow(1 - t, 3) * y0 + 3 * t * pow(1 - t, 2) * y1 + 3 * pow(t, 2) * (1 - t) * y2 + pow(t, 3) * y3;
        putpixel(x, y, WHITE);
        c++;
        if(c % 30 == 0){
        cout<<x<<" "<<y<<endl;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int choice;
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    line(centerX, 0, centerX, getmaxy()); 
    line(0, centerY, getmaxx(), centerY); 

    while (true) {
        cout << "Choose Bezier Curve:\n";
        cout << "1. Quadratic Bezier Curve\n";
        cout << "2. Cubic Bezier Curve\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cleardevice();

        // Redraw the x-y plane
        line(centerX, 0, centerX, getmaxy()); // Vertical line
        line(0, centerY, getmaxx(), centerY); // Horizontal line

        if (choice == 1) {
            int x0, y0, x1, y1, x2, y2;
            cout << "Enter the coordinates of the control points (x0 y0 x1 y1 x2 y2): ";
            cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

            // Adjust control points to the correct quadrant
            x0 += centerX;
            y0 = centerY - y0; // Invert y-axis
            x1 += centerX;
            y1 = centerY - y1; // Invert y-axis
            x2 += centerX;
            y2 = centerY - y2; // Invert y-axis

            // Draw control points
            putpixel(x0, y0, RED);
            putpixel(x1, y1, RED);
            putpixel(x2, y2, RED);

            // Draw lines between control points
            line(x0, y0, x1, y1);
            line(x1, y1, x2, y2);

            drawQuadraticBezier(x0, y0, x1, y1, x2, y2);
        } else if (choice == 2) {
            int x0, y0, x1, y1, x2, y2, x3, y3;
            cout << "Enter the coordinates of the control points (x0 y0 x1 y1 x2 y2 x3 y3): ";
            cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

            // Adjust control points to the correct quadrant
            x0 += centerX;
            y0 = centerY - y0; // Invert y-axis
            x1 += centerX;
            y1 = centerY - y1; // Invert y-axis
            x2 += centerX;
            y2 = centerY - y2; // Invert y-axis
            x3 += centerX;
            y3 = centerY - y3; // Invert y-axis

            // Draw control points
            putpixel(x0, y0, RED);
            putpixel(x1, y1, RED);
            putpixel(x2, y2, RED);
            putpixel(x3, y3, RED);

            // Draw lines between control points
            line(x0, y0, x1, y1);
            line(x1, y1, x2, y2);
            line(x2, y2, x3, y3);

            drawCubicBezier(x0, y0, x1, y1, x2, y2, x3, y3);
        } else if (choice == 3) {
            return -1;
        } else {
            cout << "Invalid choice\n";
        }
    }

    getch();
    closegraph();
    return 0;
}
