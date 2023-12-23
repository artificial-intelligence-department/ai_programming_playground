#include <iostream>
#include <vector>

using namespace std;

class DynamicArray {
private:
    vector<int> elements;  // Вектор для зберігання елементів

public:
    // Вставка елемента в кінець динамічного масиву
    void insert(int value) {
        elements.push_back(value);
    }

    // Пошук елемента в динамічному масиві
    bool contains(int value) {
        for (int element : elements) {
            if (element == value) {
                return true;  // Якщо елемент знайдений, повертаємо true
            }
        }
        return false;  // Якщо елемент не знайдений, повертаємо false
    }

    // Отримання розміру динамічного масиву
    int size() {
        return elements.size();
    }

    // Виведення елементів динамічного масиву через пробіл
    void print() {
        for (int element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
    int Q;
    cin >> Q;

    DynamicArray dynamicArray;

    while (Q--) {
        string identifier;
        cin >> identifier;

        if (identifier == "insert") {
            int value;
            cin >> value;
            dynamicArray.insert(value);
        } else if (identifier == "contains") {
            int value;
            cin >> value;
            cout << (dynamicArray.contains(value) ? "Yes" : "No") << endl;
        } else if (identifier == "size") {
            cout << dynamicArray.size() << endl;
        } else if (identifier == "print") {
            dynamicArray.print();
        }
    }

    return 0;
}
//insert - вставка
//contains - пошук
//size - розмір
//print - вивід