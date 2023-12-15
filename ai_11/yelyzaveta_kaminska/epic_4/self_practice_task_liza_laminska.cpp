#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void my_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int size = 8;
    int arr[size] = {64, 25, 12, 22, 11, 90, 8, 3};

    cout << "Unsorted array: ";
    my_array (arr, size);

    bubble_sort (arr, size);

    cout << "Sorted array: ";
    my_array(arr, size);

    return 0;
}
