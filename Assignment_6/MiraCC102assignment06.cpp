#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int n) {

    if (n < 2) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {

            return false;
        }
    }

    return true;
}

int main() {

    ifstream myFile("NUMS.TXT");

    int currentNumber;
    int count = 0;

    if (!myFile.is_open()) {
        cout << "Could not find NUMS.TXT!" << endl;
        return 1;
    }

    while (myFile >> currentNumber) {
        if (isPrime(currentNumber)) {
            count = count + 1; //
        }
    }

    cout << "There are " << count << " prime numbers in the file." << endl;

    myFile.close();

    return 0;
}
