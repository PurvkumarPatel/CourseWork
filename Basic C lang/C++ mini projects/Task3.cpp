#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip> // For setw and left manipulators
using namespace std;

struct Student {
    string firstName;
    string lastName;
    string grade;
};

int main() {
    cout << "\n|| TASK 3 - STUDENT GRADING SYSTEM ||" << endl << endl;

    // Initialize vector to store student information
    vector<Student> students;
    string firstName;
    string lastName;
    string grade;
    char continueInput;

    // Mapping letter grades to numeric values (GPA Grade system)
    map<string, double> gradeMap = {
        {"A+", 4.0},
        {"A", 4.0},
        {"A-", 3.7},
        {"B+", 3.3},
        {"B", 3.0},
        {"B-", 2.7},
        {"C+", 2.3},
        {"C", 2.0},
        {"C-", 1.7},
        {"D+", 1.3},
        {"D", 1.0},
        {"E", 0.0},
        {"F", 0.0}
    };

    do {
        cout << "Enter student's first name: ";
        cin >> firstName;

        cout << "Enter student's last name: ";
        cin >> lastName;

    Grade:
        cout << "Enter student's letter grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, E, F): ";
        cin >> grade;

        // Check if the entered grade is valid
        if (gradeMap.find(grade) == gradeMap.end()) {
            cout << "Invalid grade! Please enter a valid letter grade \n";
            goto Grade;
        }

        students.push_back({firstName, lastName, grade});

        cout << "Do you want to enter another student? (y/n): ";
        cin >> continueInput;
        cout << endl;
    } while (continueInput == 'y' || continueInput == 'Y');

    // Calculate average grade
    double totalGrade = 0;
    for (const auto& student : students) {
        totalGrade += gradeMap[student.grade];
    }
    double averageGrade = totalGrade / students.size();

    // Find highest and lowest grades
    string highestGrade = students[0].grade;
    string lowestGrade = students[0].grade;
    for (const auto& student : students) {
        if (gradeMap[student.grade] > gradeMap[highestGrade]) {
            highestGrade = student.grade;
        }
        if (gradeMap[student.grade] < gradeMap[lowestGrade]) {
            lowestGrade = student.grade;
        }
    }

    // Display results in table form
    cout << "\n------------ Student Details ------------" << endl;
    cout << setw(5) << left << "No." << setw(15) << left << "First Name" << setw(15) << left << "Last Name" << setw(8) << left << "Grade" << endl;
    cout << "-----------------------------------------" << endl;
    int i = 1;
    for (const auto& student : students) {
        cout << setw(5) << left << i << setw(15) << left << student.firstName << setw(15) << left << student.lastName << setw(8) << left << student.grade << endl;
        i++;
    }
    cout << "-----------------------------------------" << endl;

    cout << "\n-------- Student Grades Summary --------" << endl;
    cout << "Average Grade: " << averageGrade << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;
    cout << endl << "** GPA Grade System (0.0 to 4.0)" << endl;

    return 0;
}
