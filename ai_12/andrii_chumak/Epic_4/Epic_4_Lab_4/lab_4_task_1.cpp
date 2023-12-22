#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    // Сформувати одновимірний масив цілих чисел, використовуючи генератор випадкових чисел
    // Роздрукувати отриманий масив
    cout << "What size should be in your array?" << endl;
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
        cout << arr[i] << "; ";
    }
    // Знищити 5 перших елементів масиву
    cout << "\n Array without five elements: " << endl;
    for (int i = 5; i < size; ++i) {
        cout << arr[i] << "; ";
    }   
    // Додати в кінець масиву 3 нових елементи
    // Роздрукувати отриманий масив
    for (int i = 0; i < 3; ++i) {
        arr[size + i] = rand();
    }
    cout << "\n Масив після додавання нових елементів: ";
    for (int i = 0; i < size + 3; ++i) {
        cout << arr[i] << "; ";
    }
}
