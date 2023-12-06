#include <iostream>
using namespace std;

void find(int N, int** arr);
void IsDiagonalSequenceDescending (int N, int** arr);

int main() {

    int n;
    cout << "Enter n:\n ";
    cin >> n;

    int** mas = new int*[n];
    for (int i = 0; i <= n-1; i++) {
        mas[i] = new int[n];
    }

    for (int i = 0; i <= n-1; i++) {
        for (int j = 0; j <= n-1; j++) {
            cout << "Enter value of element[" << i+1 << "][" << j+1 << "]: \n";
            cin >> mas[i][j];
        }
    }
    cout << "Your Array:\n";
    for (int i = 0; i <= n-1; i++) {
        for (int j = 0; j <= n-1; j++) {
            cout << mas[i][j] << " ";
        }
        cout <<"\n";
    }

   
    find(n, mas);

    cout << "Modified Array:\n";
    for (int i = 0; i <= n-1; i++) {
        for (int j = 0; j <= n-1; j++) {
            cout << mas[i][j] << " ";
        }
        cout <<"\n";
    }
IsDiagonalSequenceDescending(n, mas);

    
  
    for (int i = 0; i <= n-1; i++) {
        delete[] mas[i];
    }
    delete[] mas;

    return 0;
}


void find(int N, int** arr) {
    int index1OfMaxEl = 0;
    int index2OfMaxEl = N - 1;

    for (int i = 0; i <= N-1; ++i) {
        for (int j = N - 1; j >= 0; --j) {
            if (arr[i][j] > arr[index1OfMaxEl][index2OfMaxEl]) {
                swap(arr[i][j], arr[index1OfMaxEl][index2OfMaxEl]);
            }
        }
    }
}
void IsDiagonalSequenceDescending(int N, int** arr) {
    bool isDescending = true;

    for (int i = 0; i < N - 1; ++i) {
        if (arr[i][N - (i+ 1)] < arr[i + 1][N -( i + 2)]) {
            isDescending = false;
            break;
        }
    }

    if (isDescending) {
        cout << "Sequence is descending " ;
    } else {
        cout << "Sequence is not descending ";
    }
}