#include <iostream>
using namespace std;

int quantity_el(int arr[100][100], int n) {
    int counter = 0;

    int d_element = arr[0][0]; 
    for (int i = 0; i < n; i++) {
        if (arr[i][i] > d_element) {
            d_element = arr[i][i];
        }    
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > d_element) {
                counter++;
            }
        }
    }

    return counter;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
   
    int arr[100][100];

    cout << "Enter number: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr [i][j];
        }
    }

    cout << "Array: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr [i][j] << " ";
        } cout << endl;
    }

    int result = quantity_el(arr, n);
    cout << "Кількість елементів більших від найбільшого елемента на головній діагоналі: " << result <<endl;
    return 0;
}
