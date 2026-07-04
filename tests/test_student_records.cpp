#include "student_records.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

bool nearlyEqual(double actual, double expected, double tolerance = 0.0001) {
    return fabs(actual - expected) <= tolerance;
}

void testIsValidStudentId() {
    assert(isValidStudentId("A123"));
    assert(isValidStudentId("B99"));
    assert(!isValidStudentId(""));
    assert(!isValidStudentId("A"));
    assert(!isValidStudentId("AB"));
    assert(!isValidStudentId("a123"));
    assert(!isValidStudentId("1123"));
}

void testIsValidScore() {
    assert(isValidScore(0.0));
    assert(isValidScore(75.5));
    assert(isValidScore(100.0));
    assert(!isValidScore(-0.1));
    assert(!isValidScore(100.1));
}

void testDetermineLetterGrade() {
    assert(determineLetterGrade(100.0) == 'A');
    assert(determineLetterGrade(90.0) == 'A');
    assert(determineLetterGrade(89.9) == 'B');
    assert(determineLetterGrade(80.0) == 'B');
    assert(determineLetterGrade(79.9) == 'C');
    assert(determineLetterGrade(70.0) == 'C');
    assert(determineLetterGrade(69.9) == 'D');
    assert(determineLetterGrade(60.0) == 'D');
    assert(determineLetterGrade(59.9) == 'F');
}

void testCalculateAverageScore() {
    Student students[] = {
        {"A123", "Alex", 90.0},
        {"B456", "Maya", 80.0},
        {"C789", "Jordan", 70.0}
    };

    assert(nearlyEqual(calculateAverageScore(students, 3), 80.0));
    assert(nearlyEqual(calculateAverageScore(nullptr, 3), 0.0));
    assert(nearlyEqual(calculateAverageScore(students, 0), 0.0));
}

void testFindHighestScore() {
    Student students[] = {
        {"A123", "Alex", 90.0},
        {"B456", "Maya", 84.0},
        {"C789", "Jordan", 96.5}
    };

    assert(nearlyEqual(findHighestScore(students, 3), 96.5));
    assert(nearlyEqual(findHighestScore(nullptr, 3), 0.0));
    assert(nearlyEqual(findHighestScore(students, 0), 0.0));
}

void testFindStudentById() {
    Student students[] = {
        {"A123", "Alex", 91.5},
        {"B456", "Maya", 84.0},
        {"C789", "Jordan", 76.5}
    };

    assert(findStudentById(students, 3, "A123") == 0);
    assert(findStudentById(students, 3, "B456") == 1);
    assert(findStudentById(students, 3, "C789") == 2);
    assert(findStudentById(students, 3, "Z999") == -1);
    assert(findStudentById(nullptr, 3, "A123") == -1);
    assert(findStudentById(students, 0, "A123") == -1);
}

void testStructureMemberAccess() {
    Student student = {"A123", "Alex", 91.5};

    assert(student.id == "A123");
    assert(student.name == "Alex");
    assert(nearlyEqual(student.score, 91.5));
}

int main() {
    testIsValidStudentId();
    testIsValidScore();
    testDetermineLetterGrade();
    testCalculateAverageScore();
    testFindHighestScore();
    testFindStudentById();
    testStructureMemberAccess();

    cout << "All Lab 5.2 student records tests passed!" << endl;
    return 0;
}
