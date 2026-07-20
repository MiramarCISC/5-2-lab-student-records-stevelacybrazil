#include "student_records.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int SIZE = 3;
    
    Student students[SIZE] = {
        {"A123", "Alex", 91.5},
        {"B456", "Maya", 84.0},
        {"C789", "Jordan", 76.5}
    };
    
    cout << "Student Records" << endl;
    cout << endl;

    cout << "All students:" << endl;
        printStudents(students, SIZE);
    cout << endl;

    cout << "Class average: "
         << calculateAverageScore(students, SIZE)
         << endl;

    cout << "Highest score: "
         << findHighestScore(students, SIZE)
         << endl;

    cout << endl;

    string targetId;
    
    cout << "Enter student ID to search for: ";
    cin >> targetId;

    int index = findStudentById(students, SIZE, targetId);

    if (index == -1) {
        cout << "Student not found." << endl;
    } else {
        cout << "Found: ";
        printStudent(students[index]);
    }

    return 0;
}
