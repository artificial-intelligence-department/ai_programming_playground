#include <iostream>
#include <cmath>
using namespace std;
void ConvertToDoubleMassif(int n[], int k) {
    int a = sqrt(k);  
    for (int i = 0; i < k - 1; ++i) {
        for (int j = 0; j < k - i - 1; ++j) {
            if (n[j] > n[j + 1]) {
                int temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
    }

    int n1[a][a];
    int s = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            n1[j][i] = n[s];
            s++;
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << n1[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int size, size1;
    int arr[] = {6, 2, 5, 8};
    int arr1[] = {4, 2, 3, 5, 9, 7, 1, 6, 0};
    size = sizeof(arr)/ sizeof(arr[0]);
    size1 = sizeof(arr1)/ sizeof(arr1[0]);
    cout << "Matrix from arr:" << endl;
    ConvertToDoubleMassif(arr, size);

    cout << "\nMatrix from arr1:" << endl;
    ConvertToDoubleMassif(arr1, size1);

    return 0;
}