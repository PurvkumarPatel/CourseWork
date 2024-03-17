#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <math.h>

using namespace std;

void drawAxes() {
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2); 
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy()); 
}

void drawObject(int x1, int y1, int x2, int y2, int x3, int y3) {

    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    int adjustedX1 = x1 + centerX;
    int adjustedY1 = centerY - y1;
    int adjustedX2 = x2 + centerX;
    int adjustedY2 = centerY - y2;
    int adjustedX3 = x3 + centerX ;
    int adjustedY3 = centerY - y3;

    line(adjustedX1, adjustedY1, adjustedX2, adjustedY2);
    line(adjustedX2, adjustedY2, adjustedX3, adjustedY3);
    line(adjustedX3, adjustedY3, adjustedX1, adjustedY1);
}

void translateObject(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int tx, int ty) {
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;
    x3 += tx;
    y3 += ty;
    drawObject(x1, y1, x2, y2, x3, y3);
}

void scaleObject(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float sx, float sy) {
    x1 *= sx;
    y1 *= sy;
    x2 *= sx;
    y2 *= sy;
    x3 *= sx;
    y3 *= sy;
    drawObject(x1, y1, x2, y2, x3, y3);
}

void rotateObject(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float angle) {
    float rad = angle * 3.14159265 / 180;

    int x1_new =  (x1) * cos(rad) - (y1) * sin(rad);
    int y1_new =  (x1) * sin(rad) + (y1) * cos(rad);

    int x2_new =  (x2) * cos(rad) - (y2) * sin(rad);
    int y2_new =  (x2) * sin(rad) + (y2) * cos(rad);

    int x3_new =  (x3) * cos(rad) - (y3) * sin(rad);
    int y3_new =  (x3) * sin(rad) + (y3) * cos(rad);

    x1 = x1_new;
    y1 = y1_new;
    x2 = x2_new;
    y2 = y2_new;
    x3 = x3_new;
    y3 = y3_new;
    drawObject(x1, y1, x2, y2, x3, y3);
}

void reflectObjectX(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) {
    y1 = -y1;
    y2 = -y2;
    y3 = -y3;
    drawObject(x1, y1, x2, y2, x3, y3);
}

void reflectObjectY(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) {
    x1 = -x1;
    x2 = -x2;
    x3 = -x3;
    drawObject(x1, y1, x2, y2, x3, y3);
}

void reflectObjectOrigin(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) {
    x1 = -x1;
    y1 = -y1;
    x2 = -x2;
    y2 = -y2;
    x3 = -x3;
    y3 = -y3;
    drawObject(x1, y1, x2, y2, x3, y3);
}

void reflectObjectLine(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float a, float c) {
    int temp1 = x1, temp2 = x2, temp3 = x3;
    x1 = (temp1 * (1 - a * a) + 2 * a * c * y1) / (a * a + 1);
    y1 = (temp1 * 2 * a * c + y1 * (a * a - 1)) / (a * a + 1);

    x2 = (temp2 * (1 - a * a) + 2 * a * c * y2) / (a * a + 1);
    y2 = (temp2 * 2 * a * c + y2 * (a * a - 1)) / (a * a + 1);

    x3 = (temp3 * (1 - a * a) + 2 * a * c * y3) / (a * a + 1);
    y3 = (temp3 * 2 * a * c + y3 * (a * a - 1)) / (a * a + 1);
    drawObject(x1, y1, x2, y2, x3, y3);
}

void shearObjectX(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float shx) {
    x1 += shx * y1;
    x2 += shx * y2;
    x3 += shx * y3;
    drawObject(x1, y1, x2, y2, x3, y3);
}

void shearObjectY(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, float shy) {
    y1 += shy * x1;
    y2 += shy * x2;
    y3 += shy * x3;
    drawObject(x1, y1, x2, y2, x3, y3);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2, x3, y3;
    int choice;


    cout << "Enter the coordinates of the object (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    drawAxes();
    drawObject(x1, y1, x2, y2, x3, y3);

    while (true) {
        cout << "Choose an operation:" << endl;
        cout << "1. Translation" << endl;
        cout << "2. Scaling" << endl;
        cout << "3. Rotation" << endl;
        cout << "4. Reflection" << endl;
        cout << "5. Shearing" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) {
            return -1;
        }

        switch (choice) {
            case 1: 
                int tx, ty;
                cout << "Enter translation values (tx ty): ";
                cin >> tx >> ty;
                translateObject(x1, y1, x2, y2, x3, y3, tx, ty);
                break;
            case 2: 
                float sx, sy;
                cout << "Enter scaling factors (sx sy): ";
                cin >> sx >> sy;
                scaleObject(x1, y1, x2, y2, x3, y3, sx, sy);
                break;
            case 3: 
                float angle;
                cout << "Enter rotation angle (degrees): ";
                cin >> angle;

                int rotationChoice;
                cout << "Choose rotation direction:" << endl;
                cout << "1. Clockwise" << endl;
                cout << "2. Anticlockwise" << endl;
                cin >> rotationChoice;
                if (rotationChoice == 2) {
                    angle = -angle; // Negative angle for clockwise rotation
                }

                rotateObject(x1, y1, x2, y2, x3, y3, angle);
                break;


            case 4: 
                int reflChoice;
                cout << "Choose a reflection option:" << endl;
                cout << "1. X-axis" << endl;
                cout << "2. Y-axis" << endl;
                cout << "3. Origin" << endl;
                cout << "4. Custom Line" << endl;
                cin >> reflChoice;

                switch (reflChoice) {
                    case 1:
                        reflectObjectX(x1, y1, x2, y2, x3, y3);
                        break;
                    case 2:
                        reflectObjectY(x1, y1, x2, y2, x3, y3);
                        break;
                    case 3:
                        reflectObjectOrigin(x1, y1, x2, y2, x3, y3);
                        break;
                    case 4:
                        float a, c;
                        cout << "Enter the equation of the line (ax + b = ): ";
                        cin >> a >> c;
                        reflectObjectLine(x1, y1, x2, y2, x3, y3, a, c);
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                break;
            case 5: 
                int shearChoice;
                cout << "Choose a shearing option:" << endl;
                cout << "1. Shear w.r.t. X-axis" << endl;
                cout << "2. Shear w.r.t. Y-axis" << endl;
                cin >> shearChoice;

                switch (shearChoice) {
                    case 1:
                        float shx;
                        cout << "Enter the shearing factor (shx): ";
                        cin >> shx;
                        shearObjectX(x1, y1, x2, y2, x3, y3, shx);
                        break;
                    case 2:
                        float shy;
                        cout << "Enter the shearing factor (shy): ";
                        cin >> shy;
                        shearObjectY(x1, y1, x2, y2, x3, y3, shy);
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        cleardevice();
        drawAxes();
        drawObject(x1, y1, x2, y2, x3, y3);
    }

    getch();
    closegraph();
    return 0;
}
