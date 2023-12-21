#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

using namespace std;

// Оголошення заголовку шаблону класу MyVector
template<typename T>
struct MyVector {
    int size = 0;             // Поточний розмір вектора
    int capacity = 1;         // Поточна ємність вектора
    T* array = new T[1];      // Динамічний масив для зберігання даних

    // Повертає поточний розмір вектора
    int getSize() {
        return size;
    }

    // Повертає поточну ємність вектора
    int getCapacity() {
        return capacity;
    }

    // Оператор індексації для зручного доступу до елементів вектора
    T& operator[](int index) {
        return array[index];
    }

    // Перевантажений оператор виводу для виведення вектора у потік
    friend ostream& operator<< (ostream& os, const MyVector<T>& val) {
        for (int i = 0; i < val.size; i++) {
            os << val.array[i] << " ";
        }
        return os;
    }

    // Метод для видалення елементів з вектора
    void erase(int index, int count) {
        for (int i = 0; i < count; i++) {
            for (int i = index; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            size--;
        }
    }

    // Метод для вставки елементів у вектор
    void insert() {
        int index, count;
        cin >> index >> count; 

        while (count > 0) {
            T n;
            cin >> n;

            for (int i = size-1; i >= index; i--) {
                array[i + 1] = array[i];
            }
            array[index] = n;

            size++;
            count--;
            index++;

            // Якщо розмір вектора досягнув поточної ємності, збільшуємо ємність
            if (size == capacity) {
                capacity = capacity * 2;
                T* newArray = new T[capacity];

                for (int i = 0; i < size; i++) {
                    newArray[i] = array[i];
                }
                delete[] array;
                array = newArray;
            }
        }
    }
};

// Головна функція
int main() {
    MyVector<int> v;  // Створення об'єкту вектора типу int
    
    int n;
    cin >> n; // Зчитуємо кількість операцій

    // Цикл для виконання операцій
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name; // Зчитуємо назву операції

        // Обробка операцій
        if (name == "size") {
            cout << v.getSize() << endl;  // Вивід поточного розміру вектора
        }
        else if (name == "capacity") {
            cout << v.getCapacity() << endl;  // Вивід поточної ємності вектора
        }
        else if (name == "insert") {
            v.insert();  // Вставка елементів у вектор
        }
        else if (name == "erase") {
            int index, count;
            cin >> index >> count;
            v.erase(index, count);  // Видалення елементів з вектора
        }
        else if (name == "print") {
            cout << v << endl;  // Вивід вектора у потік
        }
        else if (name == "get") {
            int ind;
            cin >> ind;
            cout << v[ind] << endl;  // Вивід елементу вектора за індексом
        }
        else if (name == "set") {
            int ind, val;
            cin >> ind >> val;
            v[ind] = val;  // Задання значення елементу вектора за індексом
        }
    }

    return 0;
}
