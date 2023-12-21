#include <iostream>

using namespace std;

void customSort(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int remainder_i = arr[i] % 3;
            int remainder_j = arr[j] % 3;

            if (remainder_i > remainder_j || (remainder_i == remainder_j && ((remainder_i == 0 && arr[i] > arr[j]) || (remainder_i == 1 && arr[i] < arr[j]) || (remainder_i == 2 && arr[i] > arr[j])))) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int removeDuplicates(int arr[], int N) {
    int uniqueIndex = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }
    return uniqueIndex + 1;
}

int main() {
    int N;

    cin >> N;

    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }


    customSort(arr, N);


    int uniqueSize = removeDuplicates(arr, N);

    cout << uniqueSize << endl;

    for (int i = 0; i < uniqueSize; i++) {
        cout << arr[i] << ' ';
    }

    delete[] arr;

    return 0;
}
