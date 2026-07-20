#include "student_records.hpp"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool isValidStudentId(string id) {
    if (id.length() < 2) {
        return false;
    }

    if (!isupper(id[0])) {
        return false;
    }

    for (size_t i= 1; i < id.length(); i++) {
        if (!isdigit(id[i])) {
            return false;
        }
    }

    return true;
}

bool isValidScore(double score) {
    return score >= 0.0 && score <= 100.0;;
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
    if (students == nullptr || size <= 0) {
        return 0.0;
    }
    
    double total = 0.0;

    for (int i=0; i < size; i++) {
        total += students[i].score;
    }

    return total / size;
}

double findHighestScore(const Student students[], int size) {
  if (students == nullptr || size <= 0) {
        return 0.0;
    }

    double highest = students[0].score;

    for (int i = 1; i < size; i++) {

        if (students[i].score > highest) {
            highest = students[i].score;
        }
    }

    return highest;
}

int findStudentById(const Student students[], int size, string targetId) {
    if (students == nullptr || size <= 0) {
        return -1;

    }

    for (int i = 0; i < size; i++) {
        if (students[i].id == targetId) {
            return i;
        }
    }

    return -1;
}

char determineLetterGrade(double score) {
    if (score >= 90.0) {
        return 'A';
    } else if (score >= 80.0) {
        return 'B';
    } else if (score >= 70.0) {
        return 'C';
    } else if (score >= 60.0) {
        return 'D';
    } else {
        return 'F';
    }
}
