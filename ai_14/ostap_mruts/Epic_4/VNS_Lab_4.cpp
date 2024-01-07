#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int>& arr, int start, int end) {
    for (int i = start; i <= end; ++i) {
        cout << arr[i % arr.size()] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> circular_array = {1, 5, 12, 97, 18, 36, 77, 19, 56, 23};

    cout << "Початкове кільце: ";
    printArray(circular_array, 0, circular_array.size() - 1);

    int K = 3;

    cout << "Елементи від K до K+1: ";
    printArray(circular_array, K, K + 1);

    circular_array.push_back(circular_array[0]);
    circular_array.push_back(circular_array[circular_array.size() - 2]);

    vector<int> updated_array;
    for (int num : circular_array) {
        if (num % 2 == 0) {
            updated_array.push_back(num);
        }
    }

    cout << "Оновлене кільце без непарних елементів: ";
    printArray(updated_array, 0, updated_array.size() - 1);

    cout << "Елементи від K до K+1 після змін: ";
    printArray(updated_array, K, K + 1);

    return 0;
}
