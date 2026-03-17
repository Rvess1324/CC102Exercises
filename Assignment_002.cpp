#include <iostream>
using namespace std;

void processScores(int *scoreMatrix, int numPupils, int numCourses) {
    cout << "\nScore Matrix:\n";
    for (int i = 0; i < numPupils; i++) {
        for (int j = 0; j < numCourses; j++) {
            cout << *(scoreMatrix + i * numCourses + j) << "\t";
        }
        cout << endl;
    }

    cout << "\nAverage score per pupil:\n";
    for (int i = 0; i < numPupils; i++) {
        int total = 0;
        for (int j = 0; j < numCourses; j++) {
            total += *(scoreMatrix + i * numCourses + j);
        }
        double average = (double)total / numCourses;
        cout << "Pupil " << i + 1 << ": " << average << endl;
    }

    int maxScore = *scoreMatrix;
    for (int i = 0; i < numPupils; i++) {
        for (int j = 0; j < numCourses; j++) {
            int value = *(scoreMatrix + i * numCourses + j);
            if (value > maxScore) {
                maxScore = value;
            }
        }
    }
    cout << "\nHighest score in the matrix: " << maxScore << endl;
}

int main() {
    int numStudents, numSubjects;
    cout << "Enter number of pupils: ";
    cin >> numStudents;
    cout << "Enter number of courses: ";
    cin >> numSubjects;

    int *marks = new int[numStudents * numSubjects];
    cout << "\nEnter scores:\n";
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numSubjects; j++) {
            cout << "Pupil " << i + 1 << ", Course " << j + 1 << ": ";
            cin >> *(marks + i * numSubjects + j);
        }
    }

    processScores(marks, numStudents, numSubjects);
    delete[] marks;
    return 0;
}
