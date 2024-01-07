#include <iostream>
using namespace std;

// Клас для роботи з власноруч реалізованим динамічним масивом
class CustomArray {
private:
    int *data;      // Вказівник на динамічний масив
    int size;       // Поточний розмір масиву
    int capacity;   // Поточна ємність масиву

    // Функція для зміни розміру масиву
    void resize(int newCapacity) {
        int *tempData = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            tempData[i] = data[i];
        }
        delete[] data;
        data = tempData;
        capacity = newCapacity;
    }

public:
    // Конструктор класу
    CustomArray() : data(nullptr), size(0), capacity(1) {
        data = new int[capacity];
    }

    // Деструктор класу
    ~CustomArray() {
        delete[] data;
    }

    // Метод для вставки елементів за вказаним індексом
    void insert(int index, int N, int* elements) {
        // Перевірка, чи необхідно збільшити ємність масиву
        if (size + N >= capacity) {
            while (size + N >= capacity) {
                capacity *= 2;
            }
            resize(capacity);
        }

        // Зсув елементів для вставки нових значень
        for (int i = size - 1; i >= index; --i) {
            data[i + N] = data[i];
        }

        // Вставка нових значень
        for (int i = 0; i < N; ++i) {
            data[index + i] = elements[i];
        }

        // Оновлення розміру масиву
        size += N;
    }

    // Метод для видалення елементів за вказаним індексом
    void remove(int index, int n) {
        // Зсув елементів для видалення вказаного діапазону
        for (int i = index; i < size - n; ++i) {
            data[i] = data[i + n];
        }

        // Оновлення розміру масиву
        size -= n;
    }

    // Метод для отримання значення за вказаним індексом
    int getElement(int index) {
        return data[index];
    }

    // Метод для встановлення значення за вказаним індексом
    void setElement(int index, int value) {
        data[index] = value;
    }

    // Метод для отримання поточного розміру масиву
    int getSize() {
        return size;
    }

    // Метод для отримання поточної ємності масиву
    int getCapacity() {
        return capacity;
    }

    // Метод для виведення всіх елементів масиву
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int Q;
    cin >> Q;

    CustomArray customArray;

    // Цикл обробки операцій
    for (int i = 0; i < Q; ++i) {
        // Введення операції, яку будемо виконувати
        string operation;
        cin >> operation;

        // Обробка різних операцій
        if (operation == "insert") {
            // Виклик методу insert
            int index, N;
            cin >> index >> N;
            int *elements = new int[N];
            for (int j = 0; j < N; ++j) {
                cin >> elements[j];
            }
            customArray.insert(index, N, elements);
            delete[] elements;
        } else if (operation == "erase") {
            // Виклик методу remove
            int index, n;
            cin >> index >> n;
            customArray.remove(index, n);
        } else if (operation == "size") {
            // Виведення поточного розміру масиву
            cout << customArray.getSize() << endl;
        } else if (operation == "capacity") {
            // Виведення поточної ємності масиву
            cout << customArray.getCapacity() << endl;
        } else if (operation == "get") {
            // Отримання та виведення елементу за індексом
            int index;
            cin >> index;
            cout << customArray.getElement(index) << endl;
        } else if (operation == "set") {
            // Встановлення значення за індексом
            int index, value;
            cin >> index >> value;
            customArray.setElement(index, value);
        } else if (operation == "print") {
            // Виведення всіх елементів масиву
            customArray.display();
        }
    }

    return 0;
}
