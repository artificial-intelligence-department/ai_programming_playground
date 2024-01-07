#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100; // Розмір масиву

int main() {

    srand(time(0));

    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 10;
    }

    cout <<  "Initial array: ";

    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    int newN = N; // нова змінна для збeреження розміру масиву

    int middleIndex = newN / 2;

    if (newN % 2 != 0) {

        for (int i = middleIndex; i < newN - 1; ++i) {

            arr[i] = arr[i + 1];
                }
        newN--;
    }

    const int M = 2;
    for (int i = 0; i < 3; ++i) {
        arr[i] = arr[i + 10] - 2;
    }
    newN += 3;

    cout << "Modified array: ";
    for (int i = 0; i < newN; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
