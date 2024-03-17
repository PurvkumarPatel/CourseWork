#include <iostream> // For input/output operation
#include <string> // For handling strings
#include <sstream> // For string stream operations
#include <iomanip> // For std::fixed and std::setprecision
#include <bits/stdc++.h> // optional (includes most of the standard C++ headers)
using namespace std;

// Function to get a valid long double number from the user
long double getValidNumber() {
    string input;
    long double num;

    while (true) {
        // Read the entire line of input
        getline(cin, input);

        // Convert the input string to long double
        stringstream ss(input);
        if (ss >> num && ss.eof()) { // .eof means end of file and >> is extraction operation
            // Conversion to long double is successful and no extra characters are present
            break;
        }

        cout << "Invalid input!! Please enter a valid number: ";
        // Clear the input buffer in case of invalid input
        cin.clear();
    }

    return num;
}

int main() {
    long double num1, num2;
    char operation;

    cout << "|| TASK 2 - SIMPLE CALCULATOR ||" << endl << endl;

    while (true) { // loop keeps the calculator running until the user chooses to exit
        // Display the available operations
        cout << "For Addition choose (+)" << endl << "For Subtraction choose (-)" << endl << "For Multiplication choose (*)" << endl << "For Division choose (/)" << endl << "For EXIT Press Dot (.)" << endl;
        cout << "Choose an operation : ";
        cin >> operation;   

        if (operation == '.') {
            cout << "Exit" << endl;
            return 1;
        }

        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            // Invalid operation selected, ask for input again
            cout << "Invalid operation !!" << endl;
            cout << "-------------------------------------------------------" << endl << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining characters left in the input buffer

        cout << "Enter the first number: ";
        num1 = getValidNumber();

        cout << "Enter the second number: ";
        num2 = getValidNumber();

        long double result;

        switch (operation) {
            case '+':
                result = num1 + num2;
                cout << fixed << setprecision(3) << "Addition of " << num1 << " and " << num2 << " is equal to " << result << endl;
                cout << "-------------------------------------------------------" << endl << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << fixed << setprecision(3) << "Subtraction of " << num1 << " and " << num2 << " is equal to " << result << endl;
                cout << "-------------------------------------------------------" << endl << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "Multiplication of " << num1 << " and " << num2 << " is equal to " << result << endl;
                cout << "-------------------------------------------------------" << endl << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Division of " << num1 << " and " << num2 << " is equal to " << result << endl;
                    cout << "-------------------------------------------------------" << endl << endl;
                } else {
                    cout << "Division by zero is not allowed." << endl << endl;
                    cout << "-------------------------------------------------------" << endl << endl;
                }
                break;
        }
    }

    return 0;
}
