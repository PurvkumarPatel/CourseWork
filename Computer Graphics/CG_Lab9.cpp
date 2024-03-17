#include <iostream>
#include <graphics.h>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

bool areSame(string A[][8], string B[][8])
{
  int i, j;
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      if (A[i][j] != B[i][j])
        return 0;
  return 1;
}

int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);

  int centerX = getmaxx() / 2;
  int centerY = getmaxy() / 2;
  int cursorRow = 0;
  int cursorCol = 0;
  int score = 0;
  int squareSize = min(getmaxx(), getmaxy()) / 10;

  string check[8][8] = {
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""}};
  string dictionary[8][8] = {
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", ""}};

  vector<string> words = {"apple", "orange", "banana", "grape", "pear", "cherry", "melon", "mango"};
  srand(static_cast<unsigned int>(time(NULL)));

  for (const string &word : words)
  {
    int direction = rand() % 2;
    int startRow = rand() % 8;
    int startCol = rand() % 8;

    if (direction == 0)
    { // Horiz
      if (startCol + word.length() <= 8)
      {
        for (int i = 0; i < word.length(); ++i)
        {
          if (i == 2)
          {
            check[startRow][startCol + i] = word[i];
          }
          else
          {
            dictionary[startRow][startCol + i] = word[i];
            check[startRow][startCol + i] = word[i];
          }
        }
      }
    }
    else
    { // Vertical
      if (startRow + word.length() <= 8)
      {
        for (int i = 0; i < word.length(); ++i)
        {
          if (i == 2)
          {
            check[startRow + i][startCol] = word[i];
          }
          else
          {
            dictionary[startRow + i][startCol] = word[i];
            check[startRow][startCol + i] = word[i];
          }
        }
      }
    }
  }

  while (1)
  {
    for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
      {
        int x1 = centerX - 4 * squareSize + j * squareSize + squareSize / 4;
        int y1 = centerY - 4 * squareSize + i * squareSize + squareSize / 4;
        int x2 = x1 + squareSize / 2;
        int y2 = y1 + squareSize / 2;

        string word = dictionary[i][j];

        if (i == cursorRow && j == cursorCol)
        {
          setfillstyle(INTERLEAVE_FILL, YELLOW);
          bar(x1, y1, x2, y2);
        }
        else
        {
          setfillstyle(EMPTY_FILL, WHITE);
          bar(x1, y1, x2, y2);
        }

        if (!word.empty())
        {
          char *charArray = &word[0];
          outtextxy(x1 + 10, y1 + 10, charArray);
        }
        rectangle(x1, y1, x2, y2);
      }
    }

    if (kbhit())
    {
      char key = getch();

      if (key == 72 && cursorRow > 0)
      {
        cursorRow--;
      }
      else if (key == 80 && cursorRow < 7)
      {
        cursorRow++;
      }
      else if (key == 75 && cursorCol > 0)
      {
        cursorCol--;
      }
      else if (key == 77 && cursorCol < 7)
      {
        cursorCol++;
      }
      else if (key == 13)
      {
        string word;
        cout << "Enter a word: ";
        cin >> word;

        if (word == check[cursorRow][cursorCol])
        {

          string &foundWord = check[cursorRow][cursorCol];
          transform(foundWord.begin(), foundWord.end(), foundWord.begin(), ::tolower); // lowercase
          score += 5;
          int wordLength = word.length();
          for (int i = 0; i < wordLength; ++i)
          {
            if (cursorRow + i < 8 && cursorCol + i < 8)
            {
              dictionary[cursorRow + i][cursorCol + i] = word[i];
            }
          }
          cout << "Found the word '" << word << "'!" << endl;
        }
        else
        {
          score += -2;
          cout << "Incorrect word!" << endl;
        }

        if (areSame(check, dictionary))
        {
          cout << "You Win the game!" << endl;
        }
      }
    }

    string scoreText = "Score: " + to_string(score);
    char scoreStr[100];
    strcpy(scoreStr, scoreText.c_str());
    outtextxy(getmaxx() - 100, 50, scoreStr);

    delay(100);
    cleardevice();
  }

  getch();
  closegraph();
  return 0;
}
