#include <iostream>

using namespace std;


void users_array(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
        cout << endl;
}


void remove_elements(int arr[], int &size) {
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {
            arr[j++] = arr[i];
        }
    }
    size = j;
}

int main() {
  
    int size;
    cout << "Введіть розмір масиву цілих чисел: ";
    cin >> size;

    int *arr = new int[size];

    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Оригінальний масив: ";
    users_array(arr, size);

    remove_elements(arr, size);

    cout << "Масив без парних елементів: ";
    users_array(arr, size);

    delete[] arr;

    return 0;
}
