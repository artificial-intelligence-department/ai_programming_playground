#include <iostream>
#include <string>

using namespace std;

class DynamicArray {
private:
    int* array;
    int capacity;
    int size;

    void reserve(int newCapacity) {
        if (newCapacity >= capacity) {
            while (newCapacity >= capacity) {
                capacity *= 2;
            }
            int* newArray = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }

public:
    DynamicArray() : array(nullptr), capacity(1), size(0) {}

    ~DynamicArray() {
        delete[] array;
    }

    void Insert(int index, int* insArray, int insSize) {
        int newSize = size + insSize;
        reserve(newSize);

        int* resultArray = new int[capacity];
        // Копіюємо елементи до вставки
        for (int i = 0; i < index; ++i) {
            resultArray[i] = array[i];
        }
        // Копіюємо елементи для вставки
        for (int i = 0; i < insSize; ++i) {
            resultArray[index + i] = insArray[i];
        }
        // Копіюємо елементи після вставки
        for (int i = 0; i < (size - index); ++i) {
            resultArray[index + insSize + i] = array[index + i];
        }

        delete[] array;

        array = resultArray;
        size = newSize;
    }

    void Erase(int index, int n) {
        if (size > 0) {
            int newSize = size - n;
            int* resultArray = new int[capacity];
            // Копіюємо елементи до видалення
            for (int i = 0; i < index; ++i) {
                resultArray[i] = array[i];
            }
            // Копіюємо залишок елементів після видалення
            for (int i = 0; i < newSize - index; ++i) {
                resultArray[index + i] = array[index + n + i];
            }

            delete[] array;

            array = resultArray;
            size = newSize;
        }
    }

    void Size() const {
        cout << size << endl;
    }

    void Capacity() const {
        cout << capacity << endl;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void Get(int index) const {
        if (!IsEmpty()) {
            cout << array[index] << endl;
        }
    }

    void Set(int index, int newElement) {
        if (!IsEmpty()) {
            array[index] = newElement;
        }
    }

    void Print() const {
        if (!IsEmpty()) {
            for (int i = 0; i < size; ++i) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DynamicArray dynamicArray;
    int Q;
    string identifier;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        cin >> identifier;
        if (identifier == "insert") {
            int index;
            cin >> index;
            int insSize;
            cin >> insSize;
            int insArray[insSize];
            for (int i = 0; i < insSize; ++i) {
                cin >> insArray[i];
            }
            dynamicArray.Insert(index, insArray, insSize);
        }
        else if (identifier == "erase") {
            if (!dynamicArray.IsEmpty()) {
                int index;
                cin >> index;
                int n;
                cin >> n;
                dynamicArray.Erase(index, n);
            }
        }
        else if (identifier == "size") {
            dynamicArray.Size();
        }
        else if (identifier == "capacity") {
            dynamicArray.Capacity();
        }
        else if (identifier == "get") {
            if (!dynamicArray.IsEmpty()) {
                int index;
                cin >> index;
                dynamicArray.Get(index);
            }
        }
        else if (identifier == "set") {
            if (!dynamicArray.IsEmpty()) {
                int index;
                cin >> index;
                int newElement;
                cin >> newElement;
                dynamicArray.Set(index, newElement);
            }
        }
        else if (identifier == "print") {
            dynamicArray.Print();
        }
    }

    return 0;
}
