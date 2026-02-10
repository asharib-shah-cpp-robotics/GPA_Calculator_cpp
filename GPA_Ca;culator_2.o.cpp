#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to calculate GPA Points
float getPoints(int m) {
    if (m >= 85) return 4.0;
    if (m >= 80) return 3.7;
    if (m >= 75) return 3.3;
    if (m >= 71) return 3.0;
    if (m >= 68) return 2.7;
    if (m >= 64) return 2.3;
    if (m >= 60) return 2.0;
    if (m >= 57) return 1.7;
    if (m >= 53) return 1.3;
    if (m >= 50) return 1.0;
    return 0.0;
}

// Function to convert marks to Grade
string getGrade(int m) {
    if (m >= 85) return "A";
    if (m >= 80) return "A-";
    if (m >= 75) return "B+";
    if (m >= 71) return "B";
    if (m >= 68) return "B-";
    if (m >= 64) return "C+";
    if (m >= 60) return "C";
    if (m >= 57) return "C-";
    if (m >= 53) return "D+";
    if (m >= 50) return "D";
    return "F";
}

int main() {
    int passedSem, totalCourses;
    float lastCGPA = 0.0; // Initialized to avoid garbage values

    float* cgpaPtr = &lastCGPA; // Pointer stores the address of lastCGPA

    int c1, c2, c3;

    cout << "____GPA Calculator 2.O____" << endl;
    cout << "How many semesters have you passed : ";
    cin >> passedSem;

    if (passedSem >= 1) { // Changed to >=1 so students after 1st sem can input
        cout << "Enter your last CGPA : ";
        cin >> *cgpaPtr; // Taking input directly using the pointer
    }

    cout << "Enter total number of courses in current semester: ";
    cin >> totalCourses;

    cout << "Enter number of courses having 1 credit hour: "; cin >> c1;
    cout << "Enter number of courses having 2 credit hour: "; cin >> c2;
    cout << "Enter number of courses having 3 credit hour: "; cin >> c3;

    int marks[10];
    int credits[10];
    int count = 0;

    for (int i = 0; i < c1; i++) credits[count++] = 1;
    for (int i = 0; i < c2; i++) credits[count++] = 2;
    for (int i = 0; i < c3; i++) credits[count++] = 3;

    float currentQualityPoints = 0;
    int currentTotalCredits = 0;
    int lowestMark = 101;
    int lowestCourseIdx = -1;

    for (int i = 0; i < totalCourses; i++) {
        cout << "Enter marks for course " << i + 1 << " (" << credits[i] << " Cr. Hr): ";
        cin >> marks[i];

        float points = getPoints(marks[i]);
        currentQualityPoints += (points * credits[i]);
        currentTotalCredits += credits[i];

        if (marks[i] < lowestMark) {
            lowestMark = marks[i];
            lowestCourseIdx = i + 1;
        }
    }

    float currentGPA = (currentTotalCredits > 0) ? currentQualityPoints / currentTotalCredits : 0;

    // We dereference the pointer using *cgpaPtr to get the stored value
    float newCGPA = ((*cgpaPtr * passedSem) + currentGPA) / (passedSem + 1);

    cout << "\n--- Results ---" << endl;
    for (int i = 0; i < totalCourses; i++) {
        cout << "Your grade for course " << i + 1 << " is : " << getGrade(marks[i]) << endl;
    }

    cout << "\nYour Current Semester GPA: " << currentGPA << endl;
    cout << "Your Total CGPA is : " << newCGPA << endl;

    if (newCGPA < 2.0) {
        cout << "\nSTATUS: PROBATION ALERT!" << endl;
        cout << "You should retake at least " << (totalCourses / 2) + 1 << " courses." << endl;
    }
    else {
        cout << "\nSTATUS: Good Standing." << endl;
    }

    if (lowestCourseIdx != -1 && lowestMark < 85) {
        cout << "You can improve your CGPA if you improve Course " << lowestCourseIdx << endl;
    }

    return 0;
}