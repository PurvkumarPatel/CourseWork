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

void cohenSutherland(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax)
{
    int outcode1 = Code(x1, y1, xmin, ymin, xmax, ymax);
    int outcode2 = Code(x2, y2, xmin, ymin, xmax, ymax);
    bool accept = false;

    while (true)
    {
        if ((outcode1 == 0) && (outcode2 == 0))
        {
            accept = true;
            break;
        }
        else if (outcode1 & outcode2)
        {
            break;
        }
        else
        {
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
                outcode1 = Code(x1, y1, xmin, ymin, xmax, ymax);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = Code(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept)
    {
        setcolor(LIGHTCYAN);
        line(x1, y1, x2, y2);
    }
}

void adjust(int &x, int &y, int center_x, int center_y)
{
    x -= center_x;
    y = center_y - y;
}

int main()
{
    int screenWidth = 800;
    int screenHeight = 800;
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;

    initwindow(screenWidth, screenHeight, "Clipping");

    int xmin, ymin, xmax, ymax;
    cout << "Entre cordinates of the clipping window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    rectangle(xmin + centerX, centerY - ymax, xmax + centerX, centerY - ymin);

    int numLines;
    cout << "Enter the number of lines to be drawn: ";
    cin >> numLines;

    for (int i = 0; i < numLines; ++i)
    {
        int x1, y1, x2, y2;
        cout << "Entre cordinates of the line " << (i + 1) << " (x1 y1 x2 y2): ";
        cin >> x1 >> y1 >> x2 >> y2;
        setcolor(WHITE);
        line(x1 + centerX, centerY - y1, x2 + centerX, centerY - y2);
        delay(2000);
        setcolor(BLACK);
        line(x1 + centerX, centerY - y1, x2 + centerX, centerY - y2);
        int outcode1 = Code(x1 + centerX, centerY - y1, xmin + centerX, centerY - ymax, xmax + centerX, centerY - ymin);
        int outcode2 = Code(x2 + centerX, centerY - y2, xmin + centerX, centerY - ymax, xmax + centerX, centerY - ymin);

        if (outcode1 == INSIDE && outcode2 == INSIDE)
        {
            cout << "Line " << (i + 1) << ": Fully Inside" << endl;
            cohenSutherland(x1 + centerX, centerY - y1, x2 + centerX, centerY - y2, xmin + centerX, centerY - ymax, xmax + centerX, centerY - ymin);
        }
        else if (outcode1 & outcode2)
        {
            cout << "Line " << (i + 1) << ": Completely Outside" << endl;
            cohenSutherland(x1 + centerX, centerY - y1, x2 + centerX, centerY - y2, xmin + centerX, centerY - ymax, xmax + centerX, centerY - ymin);
        }
        else
        {
            cout << "Line " << (i + 1) << ": Partially Inside" << endl;
            cohenSutherland(x1 + centerX, centerY - y1, x2 + centerX, centerY - y2, xmin + centerX, centerY - ymax, xmax + centerX, centerY - ymin);
        }
    }

    delay(5000); 
    closegraph();
    return 0;
}

