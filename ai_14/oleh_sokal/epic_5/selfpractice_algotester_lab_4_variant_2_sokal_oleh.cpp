#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


void removeDuplicates(int arr[], int &n) {
    int newSize = 0;
    for (int i = 0; i < n; ++i) {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; ++j) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            arr[newSize++] = arr[i];
        }
    }
    n = newSize;
}


void rotateArray(int arr[], int n, int k) {
    k %= n;
    for (int i = 0; i < k; ++i) {
        int temp = arr[0];
        for (int j = 0; j < n - 1; ++j) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }
}


int main() {
    int N, K;
    cin >> N >> K;


    int a[1000];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }


    removeDuplicates(a, N);


    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (a[j] > a[j + 1]) {


                swap(a[j], a[j + 1]);
            }
        }
    }




    rotateArray(a, N, K);




    cout << N << endl;
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }


    return 0;
}
