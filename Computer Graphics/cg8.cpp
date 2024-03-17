#include <iostream>
#include <graphics.h>
using namespace std;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

int Code(int x, int y, int xmin, int ymin, int xmax, int ymax)
{
    int code = INSIDE;
    if (x < xmin)
    {
        code |= LEFT;
    }
    else if (x > xmax)
    {
        code |= RIGHT;
    }
    if (y < ymin)
    {
        code |= BOTTOM;
    }
    else if (y > ymax)
    {
        code |= TOP;
    }
    return code;
}

void clipPolygon(int x[], int y[], int n, int xmin, int ymin, int xmax, int ymax)
{
    for (int i = 0; i < n; i++)
    {
        int x1 = x[i];
        int y1 = y[i];
        int x2 = x[(i + 1) % n];
        int y2 = y[(i + 1) % n];

        int outcode1 = Code(x1, y1, xmin, ymin, xmax, ymax);
        int outcode2 = Code(x2, y2, xmin, ymin, xmax, ymax);

        if (outcode1 == INSIDE && outcode2 == INSIDE)
        {
            // Both points inside, keep the line
            setcolor(LIGHTCYAN);
            line(x1, y1, x2, y2);
        }
        else if (outcode1 & outcode2)
        {
            // Both points are outside in the same region, discard the line
        }
        else
        {
            // Partially inside
            int x, y;
            int outcodeOut = outcode1 ? outcode1 : outcode2;

            if (outcodeOut & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (outcodeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (outcodeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (outcodeOut & LEFT)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (outcodeOut == outcode1)
            {
                x1 = x;
                y1 = y;
            }
            else
            {
                x2 = x;
                y2 = y;
            }

            setcolor(LIGHTCYAN);
            line(x1, y1, x2, y2);
        }
    }
}

int main()
{
    int screenWidth = 800;
    int screenHeight = 800;
    initwindow(screenWidth, screenHeight, "Polygon Clipping");

    // Calculate the center of the screen
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    int xmin, ymin, xmax, ymax;
    cout << "Enter coordinates of the clipping window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    // Calculate the center of the clipping window
    int centerXWindow = (xmin + xmax) / 2;
    int centerYWindow = (ymin + ymax) / 2;

    // Calculate the adjusted coordinates for the clipping window
    int xminAdjusted = xmin - centerXWindow + centerX;
    int yminAdjusted = ymin - centerYWindow + centerY;
    int xmaxAdjusted = xmax - centerXWindow + centerX;
    int ymaxAdjusted = ymax - centerYWindow + centerY;

    rectangle(xminAdjusted, yminAdjusted, xmaxAdjusted, ymaxAdjusted); // Draw the clipping window

    int numVertices;
    cout << "Enter the number of polygon vertices: ";
    cin >> numVertices;

    int x[100], y[100]; // Maximum of 100 vertices
    cout << "Enter the coordinates of the polygon vertices (x, y):" << endl;
    for (int i = 0; i < numVertices; ++i)
    {
        cout << "Vertex " << (i + 1) << ": ";
        cin >> x[i] >> y[i];

        // Adjust the coordinates to place the center at the middle of the screen
        x[i] = x[i] - centerXWindow + centerX;
        y[i] = y[i] - centerYWindow + centerY;
    }

    x[numVertices] = x[0]; // Closing the polygon
    y[numVertices] = y[0];

    setcolor(WHITE);
    for (int i = 0; i < numVertices; ++i)
    {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }

    delay(2000); // Delay to display the original polygon

    setcolor(BLACK);
    clipPolygon(x, y, numVertices, xminAdjusted, yminAdjusted, xmaxAdjusted, ymaxAdjusted);

    delay(5000); // Delay to display the clipped polygon

    closegraph();
    return 0;
}
