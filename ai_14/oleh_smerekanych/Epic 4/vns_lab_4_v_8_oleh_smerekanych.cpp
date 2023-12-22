#include <iostream>
using namespace std;

int main() {
    int arraysize = 10;

    int myArray[arraysize];
    for (int i = 0; i < arraysize; i++) {
        myArray[i] = rand() % 10;
    }

    cout << "Start array: ";
    for (int i = 0; i < arraysize; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    int valueToDelete = 5;

    int newSize = 0;
    for (int i = 0; i < arraysize; ++i) {
        if (myArray[i] != valueToDelete) {
            myArray[newSize++] = myArray[i];
        }
    }
    arraysize = newSize;

    for (int i = 0; i < arraysize; i++) {
        if (myArray[i] % 2 == 0) {
            for (int j = arraysize - 1; j > i; j--) {
                myArray[j] = myArray[j - 1];
            }
            myArray[i] = 0;
            arraysize++;
            i++;
        }
    }

    cout << "Changed array: ";
    for (int i = 0; i < arraysize; ++i) {
        cout << myArray[i] << " ";
    }
    return 0;
}
