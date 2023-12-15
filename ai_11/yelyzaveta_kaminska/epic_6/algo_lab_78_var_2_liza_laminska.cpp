#include <iostream>
#include <cstdlib>

class DynamicArray {
private:
    int *array;
    int size;
    int capacity;

public:
    DynamicArray() : array(nullptr), size(0), capacity(1) {}

    ~DynamicArray() {
        delete[] array;
    }

    void insert(int index, int N, int *values) {
    if (index < 0 || index > size) {
        return;
    }

    if (size + N > capacity) {
        int newCapacity = std::max(2 * capacity, size + N);
        int *newArray = new int[newCapacity];

        for (int i = 0; i < index; ++i) {
            newArray[i] = array[i];
        }

        for (int i = 0; i < N; ++i) {
            newArray[index + i] = values[i];
        }

        for (int i = index; i < size; ++i) {
            newArray[index + N + i] = array[i];
        }

        delete[] array;
        array = newArray;
        capacity = newCapacity;
        size += N;
        } else {
            for (int i = size - 1; i >= index; --i) {
                array[i + N] = array[i];
            }

            for (int i = 0; i < N; ++i) {
                array[index + i] = values[i];
            }

            size += N;
        }
    }


    void erase(int index, int n) {
        if (index < 0 || index >= size || n <= 0) {
            return;
        }

        for (int i = index + n; i < size; ++i) {
            array[i - n] = array[i];
        }
        size -= n;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    int& operator[](int index) {
        return array[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& arr);
};

std::ostream& operator<<(std::ostream& os, const DynamicArray& arr) {
    for (int i = 0; i < arr.size; ++i) {
        os << arr.array[i] << " ";
    }
    return os;
}

int main() {
    int Q;
    std::cin >> Q;

    DynamicArray dynamicArray;

    for (int i = 0; i < Q; ++i) {
        std::string identifier;
        std::cin >> identifier;

        if (identifier == "insert") {
            int index, N;
            std::cin >> index >> N;

            int* values = new int[N];
            for (int j = 0; j < N; ++j) {
                std::cin >> values[j];
            }

            dynamicArray.insert(index, N, values);
            delete[] values;
        } else if (identifier == "erase") {
            int index, n;
            std::cin >> index >> n;

            dynamicArray.erase(index, n);
        } else if (identifier == "size") {
            std::cout << dynamicArray.getSize() << std::endl;
        } else if (identifier == "capacity") {
            std::cout << dynamicArray.getCapacity() << std::endl;
        } else if (identifier == "get") {
            int index;
            std::cin >> index;
            std::cout << dynamicArray[index] << std::endl;
        } else if (identifier == "set") {
            int index, value;
            std::cin >> index >> value;
            dynamicArray[index] = value;
        } else if (identifier == "print") {
            std::cout << dynamicArray << std::endl;
        }
    }

    return 0;
}
