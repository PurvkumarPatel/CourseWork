#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <ctime> 

using namespace std;

int main()
{
	// gm is Graphics mode which is a computer display
	// mode that generates image using pixels.
	// DETECT is a macro defined in "graphics.h" header file
	int gd = DETECT, gm;

	// location of left, top, right, bottom
	int left = 10, top = 10;
	int right = 630, bottom = 470;
    int rc1,rc2,rc3;
    srand(time(0));

    // Generate a random number between 1 and 3
    int rC = rand() % 3 + 1;
    if(rC == 1){
        rc1 == 1;
        rc2 == 2;
        rc3 == 4; 
    } else if (rC == 2){
        rc1 == 2;
        rc2 == 4;
        rc3 == 1;
    } else{
        rc1 == 4;
        rc2 == 1;
        rc3 == 2;
    }

    initgraph(&gd, &gm, NULL);
	rectangle(left, top, right, bottom);
    
    rectangle(600,20,620,140);
    setfillstyle(SOLID_FILL,rc1);
    floodfill(610,30,15);

    rectangle(600,160,620,300);
    setfillstyle(SOLID_FILL,rc2);
    floodfill(610,180,15);

    rectangle(600,320,620,460);
    setfillstyle(SOLID_FILL,rc3);
    floodfill(610,340,15);

    // char ch;
    // cout<<"Enter key ESC to exit "<<endl;
    // // define infinite loop for taking keys
    // while (1) {
    //     if (!kbhit()) {
    //         // fetch typed character into ch
    //         cin>>ch;
    //         if ((int)ch == 27)
    //             // when esc button is pressed, then it will exit from loop
    //             break;
    //         cout<<"You have entered : "<< ch<< endl;
    //     }
    // }

	getch();
	closegraph();

	return 0;
}