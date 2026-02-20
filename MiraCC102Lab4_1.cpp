#include <iostream>
#include <iomanip>


using namespace std;


int main() {
    char choice;

    do {
        int numStudents, numQuizzes;

        cout << "Enter number of students: ";
        cin >> numStudents;
        cout << "Enter number of quizzes: ";
        cin >> numQuizzes;
        cout << endl;
        
        double scores[100][100]; 

        for (int i = 0; i < numStudents; i++) {
            cout << "Student " << (i + 1) << " scores: ";
            for (int j = 0; j < numQuizzes; j++) {
               
                cin >> scores[i][j]; 
            }
        }

        cout << "\nStudent\t";
        for (int j = 0; j < numQuizzes; j++) {
            cout << "Q" << (j + 1) << "\t";
        }
        cout << "Average" << endl;
        cout << "--------------------------------------------------------" << endl;

        for (int i = 0; i < numStudents; i++) {
            double sum = 0;
            cout << (i + 1) << "\t"; 

            for (int j = 0; j < numQuizzes; j++) {
                cout << scores[i][j] << "\t";
                sum += scores[i][j];
            }

            double average = sum / numQuizzes;
            cout << fixed << setprecision(2) << average << endl;
        }

        cout << "\nWould you like to run the program again? [Y/N]: ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\nProgram exited..." << endl;

    return 0;
}