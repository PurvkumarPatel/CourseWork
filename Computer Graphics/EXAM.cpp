#include <graphics.h>
#include <iostream>
#include <math.h>
#include <vector>
void adjust(int &x, int &y)
{
  int width = getmaxx() / 2;
  int height = getmaxy() / 2;
  x = x + width;
  y = height - y;
}
void adjust2(double &x, double &y)
{
  int width = getmaxx() / 2;
  int height = getmaxy() / 2;
  x = x + width;
  y = height - y;
}
void rotation(int &x, int &y, float &co, float &si)
{
  int a = x;
  int b = y;
  x = a * co + b * si;
  y = -a * si + b * co;
}

int main()
{
  int gd = DETECT, gm;
  initwindow(800, 600);

  int x = 0;
  int y = 20;
  adjust(x, y);
    const int numPoints = 60; 
    const double centerX = 0; 
    const double centerY = 20; 
    const double radius = 120; 

    std::vector<double> xVector; 
    std::vector<double> yVector;

    const double angleIncrement = 2 * M_PI / numPoints; 

    for (int i = 0; i < numPoints; ++i) {
        double angle = i * angleIncrement;
        double x = centerX + radius * cos(angle);
        double y = centerY + radius * sin(angle);

        xVector.push_back(x);
        yVector.push_back(y);
    }

  int numRotations = 60;
  int i = 0;
  int minuteX = 0, minuteY = 0;
  int r = 0, s= 0;
  while (1)
  {
    cleardevice();

    circle(x, y, 150);
    if (i % 60 == 0)
    {
      r++;s++;
      adjust2(xVector[r],yVector[s]);
    line(x, y, xVector[r], yVector[s]);
    } else {
      adjust2(xVector[r],yVector[s]);
    line(x, y, xVector[r], yVector[s]);
    }
    
      int m = 0;
      int n = -130;
      adjust(m,n);
    if (i % 2 == 0)
    {
      int newX = -200;
      int newY = -200;
      adjust(newX, newY);

      line(m, n, newX, newY);
      circle(newX, newY, 20);
    }
    else
    {
      int newx = 200;
      int newy = -200;
      adjust(newx, newy);
      line(m, n, newx, newy);
      circle(newx, newy, 20);
    }

    setcolor(WHITE);

    delay(100);


        i++;
  }

  delay(100);
  // closegraph();
  return 0;
}


