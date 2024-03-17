#include <iostream>
#include <cstdlib> // For rand() and srand() function
#include <ctime> // For time() function
using namespace std;

int main() {
    int a;

    // Getting the current time (optional)
    time_t current_time = time(NULL);

    // Setting the random seed based on the current time
    srand((unsigned)current_time);

    int offset = 1; // Minimum number in the range
    int range = 10; // Range of numbers (1 to 10)
    int r = offset + (rand() % range); // Generating a random number between 1 and 10
    cout<<"|| TASK 1 - NUMBER GUESSING GAME ||"<<endl;
    do {
        cout << "Guess the number from 1 to 10 : " ;
        cin >> a;
        // asks the user to guess it and provide feedback
        if (a == r) {
            cout << "You guessed the correct number." << endl;
        } else if ( a > 10 || a < 1){
            cout<<"Invalid Input !!" <<endl;
        } else if (a == (r - 1) || a == (r + 1)) {
            cout << "Too close try again." << endl;
        } else if (a > (r + 1)) {
            cout << "Try a smaller number." << endl;
        } else {
            cout << "Try a greater number." << endl;
        }
    } while (a != r); //loop run untill the user guesses the correct number

    return 0;
}
