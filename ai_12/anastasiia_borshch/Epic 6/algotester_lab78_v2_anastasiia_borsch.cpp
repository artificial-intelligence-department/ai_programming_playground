#include <iostream>
using namespace std;

class DynamicArray {
private:
    int *array;
    int currentSize;
    int currentCapacity;

    void resize(int newCapacity) {
        int *tempArray = new int[newCapacity];
        for (int i = 0; i < currentSize; ++i) {
            tempArray[i] = array[i];
        }
        delete[] array;
        array = tempArray;
        currentCapacity = newCapacity;
    }

public:
    DynamicArray() : array(nullptr), currentSize(0), currentCapacity(1) {
        array = new int[currentCapacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void insert(int index, int N, int *elements) {
        if (currentSize + N >= currentCapacity) {
            while (currentSize + N >= currentCapacity) {
                currentCapacity *= 2;
            }
            resize(currentCapacity);
        }

        for (int i = currentSize - 1; i >= index; --i) {
            array[i + N] = array[i];
        }

        for (int i = 0; i < N; ++i) {
            array[index + i] = elements[i];
        }

        currentSize += N;
    }void erase(int index, int n) {
        for (int i = index; i < currentSize - n; ++i) {
            array[i] = array[i + n];
        }
        currentSize -= n;
    }

    int get(int index) {
        return array[index];
    }

    void set(int index, int value) {
        array[index] = value;
    }

    int size() {
        return currentSize;
    }

    int capacity() {
        return currentCapacity;
    }

    // Перегрузка оператора []
    int &operator[](int index) {
        return array[index];
    }

    // Перегрузка оператора <<
    friend ostream &operator<<(ostream &os, const DynamicArray &dArray) {
        for (int i = 0; i < dArray.currentSize; ++i) {
            os << dArray.array[i] << " ";
        }
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;

    DynamicArray dynamicArray;

    for (int i = 0; i < Q; ++i) {
        string query;
        cin >> query;
                if (query == "insert") {
            int index, N;
            cin >> index >> N;
            int *elements = new int[N];
            for (int j = 0; j < N; ++j) {
                cin >> elements[j];
            }
            dynamicArray.insert(index, N, elements);
            delete[] elements;
        } else if (query == "erase") {
            int index, n;
            cin >> index >> n;
            dynamicArray.erase(index, n);
        } else if (query == "size") {
            cout << dynamicArray.size() << endl;
        } else if (query == "capacity") {
            cout << dynamicArray.capacity() << endl;
        } else if (query == "get") {
            int index;
            cin >> index;
            cout << dynamicArray.get(index) << endl;
        } else if (query == "set") {
            int index, value;
            cin >> index >> value;
            dynamicArray.set(index, value);
        } else if (query == "print") {
            cout << dynamicArray << endl;
        }
    }

    return 0;
}