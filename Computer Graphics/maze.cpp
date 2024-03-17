#include <iostream>
#include <graphics.h>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);


    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int cursorRow = 0;
    int cursorCol = 0;
    int score = 0;
    int squareSize = min(getmaxx(), getmaxy()) / 10;


vector<string> dictionary = {"apple", "orange", "banana", "grape", "pear", "cherry", "melon", "mango"};
string selectedWord = dictionary[rand() % dictionary.size()];


// Randomly choose a direction: 0 for diagonal, 1 for vertical, 2 for horizontal
int direction = rand() % 3;


// Calculate starting position based on the selected direction
int startRow, startCol;
if (direction == 0) {
    startRow = rand() % (9 - selectedWord.length());
    startCol = rand() % (9 - selectedWord.length());
} else if (direction == 1) {
    startRow = rand() % (9 - selectedWord.length());
    startCol = rand() % 8;
} else {
    startRow = rand() % 8;
    startCol = rand() % (9 - selectedWord.length());
}


    while (1) {
        // Draw grid
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                int x1 = centerX - 4 * squareSize + j * squareSize + squareSize / 4;
                int y1 = centerY - 4 * squareSize + i * squareSize + squareSize / 4;
                int x2 = x1 + squareSize / 2;
                int y2 = y1 + squareSize / 2;


                if (i == cursorRow && j == cursorCol) {
                    setfillstyle(INTERLEAVE_FILL, YELLOW);
                    bar(x1, y1, x2, y2);
                } else {
                    setfillstyle(EMPTY_FILL, WHITE);
                    bar(x1, y1, x2, y2);
                }


                rectangle(x1, y1, x2, y2);
            }
        }
srand(time(0));




// Draw the selected word in the grid, missing one character
char wordArray[selectedWord.length() + 1]; // +1 for null terminator
strcpy(wordArray, selectedWord.c_str());


for (int i = 0; i < selectedWord.length(); ++i) {
    int row = startRow;
    int col = startCol;
    if (direction == 0) {
        row += i;
        col += i;
    } else if (direction == 1) {
        row += i;
    } else {
        col += i;
    }


    // Skip one character in the word
    if (i != selectedWord.length() - 1) {
        int x1 = centerX - 4 * squareSize + col * squareSize;
        int y1 = centerY - 4 * squareSize + row * squareSize;
        int x2 = x1 + squareSize;
        int y2 = y1 + squareSize;
        rectangle(x1, y1, x2, y2);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(centerX - 4 * squareSize, centerY - 4 * squareSize, wordArray);
    }
}
        if (kbhit()) {
            char key = getch();


            if (key == 72 && cursorRow > 0) { // Up arrow
                cursorRow--;
            } else if (key == 80 && cursorRow < 7) { // Down arrow
                cursorRow++;
            } else if (key == 75 && cursorCol > 0) { // Left arrow
                cursorCol--;
            } else if (key == 77 && cursorCol < 7) { // Right arrow
                cursorCol++;
            } else if (key == 13) {
                string word;
                cout << "Enter a character for that position: ";
                cin >> word;


                auto it = find(dictionary.begin(), dictionary.end(), word);
                if (it != dictionary.end()) {
                    // Word is valid, fill it in the grid
                    // Implement logic to fill word in the grid at cursor position


                    // Calculate and update score
                    score += word.length();


                    // Clear the word after filling it in the grid
                    word.clear();
                } else {
                    cout << "Invalid word! Try again." << endl;
                }
            }
        }


        // Display score
        string scoreText = "Score: " + to_string(score);
        char scoreStr[100];
        strcpy(scoreStr, scoreText.c_str());
        outtextxy(getmaxx() - 70, 50, scoreStr);


        delay(100);
        cleardevice();
    }


    getch();
    closegraph();
    return 0;
}