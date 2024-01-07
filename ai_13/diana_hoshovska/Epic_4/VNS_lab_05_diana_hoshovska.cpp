#include <iostream>
using namespace std;

int Sum(int n, int array[100][100]);

int main(){
    int N, sum = 0;
    cout << "Enter the size of matrix: ";
    cin >> N;
    int arr[100][100];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    sum = Sum(N, arr);

    cout << "The sum of elements under the main diagonal is " << sum;
    return 0;
}

int Sum(int n, int array[100][100]){
    int summa = 0;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            summa += array[i][j];
        }
    }
    return summa;
}