#include <iostream>
#include <fstream> // Required to open a file
#include <string>
#include <sstream> // Required for working with string streams
using namespace std;

int main() {
    cout << "\n|| TASK 4 - WORD COUNT ||" << endl << endl;

    START:
    // Prompt the user to enter the name of the text file
    string filename;
    cout << "Enter the name of the text file: ";
    cin >> filename;

    // Open the file specified by the user
    ifstream inputFile(filename);
    if (!inputFile) { // Check if the file was opened successfully
        cerr << "Error opening the file. Please make sure the file exists and is accessible.\n";
        goto START; // Exit the program with an error code
    }

    // Read the entire content of the file into a string
    stringstream buffer;
    buffer << inputFile.rdbuf();
    string fileContent = buffer.str();

    // Close the file, as its content is already stored in the 'fileContent' string
    inputFile.close();

    // Split the content into words using a stringstream
    stringstream ss(fileContent);
    string word;
    int wordCount = 0 ;
    while (ss >> word) { // Extract words one by one from the stringstream
        wordCount++ ; // Increment the word count for each word encountered
    }

    // Display the total word count
    cout << "\nTotal number of words in the file: " << wordCount << endl;

    return 0; // Return 0 to indicate successful execution
}
