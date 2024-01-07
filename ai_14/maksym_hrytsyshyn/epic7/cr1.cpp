#include <iostream>
#include <vector>
using namespace std;

const int number = 1026;

int** createarray() {
    int** arr = new int* [10];
    for (int i = 0; i < 10; i++) {
        arr[i] = new int[10];
    }
  
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                double o= (cos(i)-1) / (i+1);
                arr[i][j] = o;
            }
        }
    
    return arr;   
}


void sortcol(double arr[10][10]) {
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 9; i++) {
            for (int k=0; k<9-i; k++) {
            if (arr[k][j] > arr[k + 1][j]) {
                swap(arr[k][j], arr[k+1][j])
            }
        }
    }
}
}

void sortrow(int arr[10][10]) {
    for (int i = 0; i<9; i++) {
        for (int j=0; j<9-i) {
            if (arr[j][0]<arr[j+1][0]) {
                swap(arr[j], arr[j+1])
            }
        }
    }
}
void abcarr(double arr[10][10], double content) {
    sortcol(arr);
}
void abcarr(int arr[10][10], int content) {
    sortrow(arr);
}
int main () {
    int** arr = createarray();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    sortcol(arr);
    sortrow(arr);
    content = number;
    return 0;
}