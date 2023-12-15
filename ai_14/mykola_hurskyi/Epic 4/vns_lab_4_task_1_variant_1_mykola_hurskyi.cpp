#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <cmath>   

using namespace std;

void randarray(int arr[], int size) { 
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 101 - 50; 
    }
}

void print(int arr[], int size) { 
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void cond1(int arr[], int &size) {
    if (size > 5) {
        size -= 5;
    } else {
        size = 0;
    }
}

void cond2(int M[], int &size) {
    int newSize = size + 3; 
    for (int i = newSize - 1; i >= 3; --i) {
        M[i] = M[i - 3]; 
    }
    for (int i = 0; i < 3; ++i) {
        M[i] = M[i + 3] + 2; 
    }
    size = newSize;
}

int main() {
    srand(static_cast<unsigned>(time(0))); 

    int size = 25; 
    int array[size];

    randarray(array, size);

    cout << "orig array: ";
    print(array, size);

    cond1(array, size);

    cond2(array, size);

    cout << "new array: ";
    print(array, size);

    return 0;
}
