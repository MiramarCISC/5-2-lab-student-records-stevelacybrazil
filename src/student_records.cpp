#include "student_records.hpp"
#include <iostream>

using namespace std;

bool isValidStudentId(string id) {
    // TODO:
    // A valid ID should have at least 3 characters.
    // A valid ID should start with an uppercase letter.
    // Hint: You may compare characters directly, such as id[0] >= 'A'.
    return false;
}

bool isValidScore(double score) {
    // TODO: Return true when score is between 0 and 100, inclusive.
    return false;
}

void printStudent(const Student& student) {
    cout << student.id << " "
         << student.name << " "
         << student.score << " "
         << determineLetterGrade(student.score)
         << endl;
}

void printStudents(const Student students[], int size) {
    if (students == nullptr || size <= 0) {
        cout << "No students to print." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        printStudent(students[i]);
    }
}

double calculateAverageScore(const Student students[], int size) {
    // TODO:
    // If the array is null or size is invalid, return 0.0.
    // Otherwise, return the average score.
    return 0.0;
}

double findHighestScore(const Student students[], int size) {
    // TODO:
    // If the array is null or size is invalid, return 0.0.
    // Otherwise, return the highest score.
    return 0.0;
}

int findStudentById(const Student students[], int size, string targetId) {
    // TODO:
    // Search by comparing students[i].id to targetId.
    // Return the index of the matching student.
    // Return -1 if no student is found.
    return -1;
}

char determineLetterGrade(double score) {
    // TODO:
    // Return 'A' for scores 90 or higher.
    // Return 'B' for scores 80 or higher.
    // Return 'C' for scores 70 or higher.
    // Return 'D' for scores 60 or higher.
    // Return 'F' otherwise.
    return 'F';
}
