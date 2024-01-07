#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

template <class T>
class DynamicArray {
private:
    T* data;          
    size_t size;       
    size_t capacity;   
    const int growthFactor = 2; 

    void resize() {
        do {
            capacity *= growthFactor;
        } while (capacity <= size);
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray() : size(0), capacity(1) {
        data = new T[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int index, size_t N, T* values) {
        if (index > size) {
            return;
        }
        size += N;
        while (size >= capacity) {
            resize();
        }
        copy_backward(data + index, data + size - N, data + size);
        for (size_t i = 0; i < N; ++i) {
            data[index + i] = values[i];
        }
    }

    void erase(int index, size_t n) {
        if (index >= size) {
            return;
        }
        size_t elementsToRemove = min(n, size - index);
        for (size_t i = index; i < size - elementsToRemove; ++i) {
            data[i] = data[i + elementsToRemove];
        }
        size -= elementsToRemove;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        data[index] = value;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int Q;
    cin >> Q;
    DynamicArray<int> dynamicArray;
    string* commands = new string[Q];  

    for (int i = 0; i < Q; i++) {
        cin >> commands[i];
        if (commands[i] == "size") {
            cout << dynamicArray.getSize() << endl;
        }
        else if (commands[i] == "capacity") {
            cout << dynamicArray.getCapacity() << endl;
        }
        else if (commands[i] == "insert") {
            int index, N;
            cin >> index >> N;
            int* values = new int[N];
            for (int j = 0; j < N; ++j) {
                cin >> values[j];
            }
            dynamicArray.insert(index, N, values);
            delete[] values;
        }
        else if (commands[i] == "erase") {
            int index, n;
            cin >> index >> n;
            dynamicArray.erase(index, n);
        }
        else if (commands[i] == "set") {
            int index, value;
            cin >> index >> value;
            dynamicArray.set(index, value);
        }
        else if (commands[i] == "get") {
            int index;
            cin >> index;
            cout << dynamicArray[index] << endl;
        }
        else if (commands[i] == "print") {
            dynamicArray.print();
        }
    }
    delete[] commands; 
    return 0;
}
