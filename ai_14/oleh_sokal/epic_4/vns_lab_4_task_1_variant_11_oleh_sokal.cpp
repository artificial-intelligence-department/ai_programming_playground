#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    int random_array[10] = {1, 5, 12, 97, 18, 36, 77, 19, 56, 23};
    cout << "Початковий масив: ";
    for (int i = 0; i < 10; ++i) {
        cout << random_array[i] << " ";
    }
    cout << endl;

    int elements_to_remove = 6;
    int new_array_size = 10 - elements_to_remove;
    int new_elements[3];
    for (int i = 0; i < 3; ++i) {
        new_elements[i] = random_array[i + 1] + 2;
    }
    for (int i = new_array_size; i >= 0; --i) {
        random_array[i + 3] = random_array[i];
    }
    for (int i = 0; i < 3; ++i) {
        random_array[i] = new_elements[i];
    }
    cout << "Оновлений масив: ";
    for (int i = 0; i <= new_array_size + 3; ++i) {
        cout << random_array[i] << " ";
    }
    cout << endl;

    return 0;
}