#include <iostream>

using namespace std;

void element_delete(int *&arr, int &size, int x1, int x2, int x3) {
    int ind = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] != x1 && arr[i] != x2 && arr[i] != x3) {
            arr[ind++] = arr[i];
        }
    }

    size = ind;
}

void sum(int *&arr, int &size) {
    size--;

    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] + arr[i + 1];
    }
}

int main() {
    int N, del1, del2, del3;
    cin >> N;
    int *arr = new int[N];
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> del1 >> del2 >> del3;

    element_delete(arr, N, del1, del2, del3);
    sum(arr, N);

    if(N <= 1){
        cout << "0";
    }
    else{
        cout << N << endl;

        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
    }

    delete[] arr;
    return 0;
}