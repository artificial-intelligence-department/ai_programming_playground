#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {

    
    const int MAX_SIZE = 100; 

    int arr[MAX_SIZE], actualSize;
    
    cout << "Actual array size: " ;
    cin >> actualSize ;

    for (int i = 0; i < actualSize; i++) {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Initial array: ";
    for (int i = 0; i < actualSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    actualSize -= 5; 
    
    int addition = 3;
    for (int i = actualSize - 1; i >= 0; i--) {
        arr[i + addition] = arr[i];
    }

    for (int i = 0; i < addition; i++) {
        arr[i] = arr[addition + i + 1] + 2;
    }
    
    actualSize += addition;

    cout << "Modified array: ";
    for (int i = 0; i < actualSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
