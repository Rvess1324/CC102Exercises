#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char choice;

    do {
        
        double sales[5][4] = {0}; 
        int salesperson, product;
        double amount;
        char choice;

        cout << "--- Monthly Sales Input ---" << endl;
        while (true) {
            cout << "Salesperson number (1-4): ";
            cin >> salesperson;
            cout << "Product number (1-5): ";
            cin >> product;
            cout << " Amount sold: ";
            cin >> amount;

            sales[product - 1][salesperson - 1] += amount;

            cout << "Add another slip? (y/n): ";
            cin >> choice;
            if (choice == 'n' || choice == 'N') break;
            cout << endl;
        }

        cout << "\n" << setw(10) << "Product" << setw(10) << "1" << setw(10) << "2" 
             << setw(10) << "3" << setw(10) << "4" << setw(10) << "Total" << endl;
        cout << "------------------------------------------------------------" << endl;

        double grandTotal = 0;
        double colTotals[4] = {0}; 
        
        for (int i = 0; i < 5; i++) {
            double rowTotal = 0;
            cout << setw(10) << (i + 1);

            for (int j = 0; j < 4; j++) {
                cout << setw(10) << fixed << setprecision(2) << sales[i][j];
                rowTotal += sales[i][j];    
                colTotals[j] += sales[i][j]; 
            }
            cout << setw(10) << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "------------------------------------------------------------" << endl;
        cout << setw(10) << "Total";
        for (int j = 0; j < 4; j++) {
            cout << setw(10) << colTotals[j];
        }
        cout << setw(10) << grandTotal << endl;

        cout << "\nWould you like to run the program again? [Y/N]: ";
        cin >> runAgain;

    } while (choice == 'Y' || choice == 'y');

    cout << "Program terminated." << endl;
    return 0;
}