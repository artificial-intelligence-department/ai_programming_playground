#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;

void some_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
    }
}

void my_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void remove_elements(int arr[], int &size, int value) {
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] != value) {
            arr[j++] = arr[i];
        }
    }
    size = j;
}

void zeros (int arr[], int &size) {
    for (int i = 0; i < size; i += 2) {
        for (int j = size; j > i; --j) {
            arr[j] = arr[j - 1];
        }
        arr[i] = 0;
        size++;
        i++;
    }
}

int main() {
    srand(time(0));
    int arr[MAX_SIZE];
    int size;

    cout << "Enter the array size: ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Invalid size." << endl;
        return 1;
    }

    some_array(arr, size);

    cout << "Initial array: ";
    my_array(arr, size);

    int deleted_value;
    cout << "Enter the value to remove: ";
    cin >> deleted_value;

    remove_elements(arr, size, deleted_value);

    cout << "Array after removing the elements with " << deleted_value << ": ";
    my_array(arr, size);

    zeros (arr, size);

    cout << " Array after adding 0 before even elements: ";
    my_array(arr, size);

    return 0;
}
