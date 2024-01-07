#include <iostream>

class DynamicArray {
private:
    int* array;
    int currentSize;
    int currentCapacity;

    void resize(int newCapacity) {
        int* tempArray = new int[newCapacity];
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

    void insert(int index, int N, int* elements) {
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
    }

    void erase(int index, int n) {
        for (int i = index; i < currentSize - n; ++i) {
            array[i] = array[i + n];
        }
        currentSize -= n;
    }

    int get(int index) const {
        return array[index];
    }

    void set(int index, int value) {
        array[index] = value;
    }

    int size() const {
        return currentSize;
    }

    int capacity() const {
        return currentCapacity;
    }

    void print() const {
        for (int i = 0; i < currentSize; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int Q;
    std::cin >> Q;

    DynamicArray dynamicArray;

    for (int i = 0; i < Q; ++i) {
        std::string query;
        std::cin >> query;

        if (query == "insert") {
            int index, N;
            std::cin >> index >> N;
            int* elements = new int[N];
            for (int j = 0; j < N; ++j) {
                std::cin >> elements[j];
            }
            dynamicArray.insert(index, N, elements);
            delete[] elements;
        } else if (query == "erase") {
            int index, n;
            std::cin >> index >> n;
            dynamicArray.erase(index, n);
        } else if (query == "size") {
            std::cout << dynamicArray.size() << std::endl;
        } else if (query == "capacity") {
            std::cout << dynamicArray.capacity() << std::endl;
        } else if (query == "get") {
            int index;
            std::cin >> index;
            std::cout << dynamicArray.get(index) << std::endl;
        } else if (query == "set") {
            int index, value;
            std::cin >> index >> value;
            dynamicArray.set(index, value);
        } else if (query == "print") {
            dynamicArray.print();
        }
    }

    return 0;
}

