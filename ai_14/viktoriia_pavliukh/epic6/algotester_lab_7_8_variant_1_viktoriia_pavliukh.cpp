#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T *array;
    int length;
    int currentCapacity;

    void resize(int newCapacity) {
        T *tempArray = new T[newCapacity];
        for (int i = 0; i < length; ++i) {
            tempArray[i] = array[i];
        }
        delete[] array;
        array = tempArray;
        currentCapacity = newCapacity;
    }

public:
    DynamicArray() : array(nullptr), length(0), currentCapacity(1) {
        array = new T[currentCapacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void insert(int index, int N, T* elements) {
        if (length + N >= currentCapacity) {
            while (length + N >= currentCapacity) {
                currentCapacity *= 2;
            }
            resize(currentCapacity);
        }

        for (int i = length - 1; i >= index; --i) {
            array[i + N] = array[i];
        }

        for (int i = 0; i < N; ++i) {
            array[index + i] = elements[i];
        }

        length += N;
    }

    void erase(int index, int n) {
        for (int i = index; i < length - n; ++i) {
            array[i] = array[i + n];
        }
        length -= n;
    }

    T getElement(int index) {
        return array[index];
    }

    void set(int index, T value) {
        array[index] = value;
    }

    int getLength() {
        return length;
    }

    int capacity() {
        return currentCapacity;
    }

    void print() {
        for (int i = 0; i < length; ++i) {
            cout << array[i] << " ";
        }
        cout <<endl;
    }
};

int main() {
    int Q;
    cin >> Q;

    DynamicArray<int> dynamicArray;

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
        } else if (query == "size") {
            cout << dynamicArray.getLength() << endl;
        } else if (query == "erase") {
            int index, n;
            cin >> index >> n;
            dynamicArray.erase(index, n);
        } else if (query == "capacity") {
            cout << dynamicArray.capacity() << endl;
        } else if (query == "get") {
            int index;
            cin >> index;
            cout << dynamicArray.getElement(index) << endl;
        } else if (query == "set") {
            int index, value;
            cin >> index >> value;
            dynamicArray.set(index, value);
        } else if (query == "print") {
            dynamicArray.print();
        }
    }

    return 0;
}
