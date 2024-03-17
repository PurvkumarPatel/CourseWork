#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Calculate ticket price based on the movie and number of tickets
int TicketPrice(int a, int b) {
    int r;
    if (a == 1) {
        r = 100;
    } else if (a == 2) {
        r = 150;
    } else {
        r = 120;
    }
    return r * b;
}

// Display the seat map
void displaySeatMap(int ar[][COLS]) {
    cout << "  1 2 3 4 5" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < COLS; j++) {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}

// Make a booking for a ticket
bool makeBooking(int ar[][COLS], int &seats) {
    int row, col;
    cout << "Enter Row number for the ticket: ";
    cin >> row;
    cout << "Enter Column number for the ticket: ";
    cin >> col;

    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        cout << "Invalid Row or Column number. Please try again." << endl;
        return false;
    }

    if (ar[row - 1][col - 1] == 1) {
        cout << "This seat is already booked. Please select another seat." << endl;
        return false;
    }

    ar[row - 1][col - 1] = 1;
    seats--;
    return true;
}

int main() {
    cout << "\n|| TASK 5 - MOVIE TICKET BOOKING SYSTEM ||" << endl << endl;

    int movies[3][ROWS][COLS] = {0};
    int seats[3] = {25, 25, 25};
    int movieChoice, numTickets;

    cout << "------ Movie Listings ------" << endl;
    cout << "  Movie    Time       Cost" << endl;
    cout << "1 Action - 120 mins - Rs 100" << endl;
    cout << "2 Comedy - 110 mins - Rs 150" << endl;
    cout << "3 Drama  - 100 mins - Rs 120" << endl;
    cout << "0 For Exit" << endl;

    while (true) {
        cout << "Select Movie (1, 2, 3) or 0 (Exit): ";
        cin >> movieChoice;

        if (movieChoice == 0) {
            cout << "EXIT Successfully" << endl;
            break;
        }

        if (movieChoice < 1 || movieChoice > 3) {
            cout << "Invalid INPUT!!" << endl;
            continue;
        }

        int currentMovie = movieChoice - 1;
        cout << "How many tickets would you like to purchase? : ";
        cin >> numTickets;

        if (numTickets > seats[currentMovie]) {
            cout << "Enter fewer than " << seats[currentMovie] << " tickets." << endl;
            continue;
        }

        cout << "Seat Map for Movie " << movieChoice << ":" << endl;
        displaySeatMap(movies[currentMovie]);

        for (int i = 1; i <= numTickets; i++) {
            cout << "Ticket " << i << ": " << endl;
            while (!makeBooking(movies[currentMovie], seats[currentMovie])) {}
        }

        cout << "Your total cost for " << numTickets << " movie tickets is " << TicketPrice(movieChoice, numTickets) << endl;
        cout << "You Booked Tickets successfully!" << endl;
        cout << "-----------------------------------------------------------" << endl;
    }

    return 0;
}
