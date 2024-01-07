#include <iostream>
#include <ctime>

using namespace std;

struct Array {
    int* elements;
    int size;
};

void initialize(Array& arr); 
void display(const Array& arr); 
void eraseElement(Array& arr, int index);
void eraseAllOccurrences(Array& arr, int num);
void sumAdjacentElements(Array& arr);

int main() {
    srand(time(0));
    Array array;
    cin >> array.size;
    array.elements = new int[array.size];

    initialize(array);

    int a, b, c;
    cin >> a >> b >> c;

    eraseAllOccurrences(array, a);
    eraseAllOccurrences(array, b);
    eraseAllOccurrences(array, c);

    if (array.size != 0) {
        sumAdjacentElements(array);
        cout << array.size << endl;
        display(array);
    } else {
        cout << 0 << endl;
    }

    delete[] array.elements;
    return 0;
}

void initialize(Array& arr) {
    for (int i = 0; i < arr.size; i++) {
        cin >> arr.elements[i];
    }
}

void display(const Array& arr) {
    for (int i = 0; i < arr.size; i++) {
        cout << arr.elements[i] << " ";
    }
}

void eraseElement(Array& arr, int index) {
    int* newArray = new int[--arr.size];
    for (int i = 0, j = 0; i < arr.size + 1; i++) {
        if (i != index) {
            newArray[j++] = arr.elements[i];
        }
    }
    delete[] arr.elements;
    arr.elements = newArray;
}

void eraseAllOccurrences(Array& arr, int num) {
    for (int i = 0; i < arr.size; i++) {
        if (arr.elements[i] == num) {
            eraseElement(arr, i);
            i--;
        }
    }
}

void sumAdjacentElements(Array& arr) {
    int* newArray = new int[--arr.size];
    for (int i = 0; i < arr.size; i++) {
        newArray[i] = arr.elements[i] + arr.elements[i + 1];
    }
    delete[] arr.elements;
    arr.elements = newArray;
}
