
#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;


template <typename T>
class DynamicArray {
private:
    T* arr;
    int size;          
    int capacity;      
    const int growthFactor = 2;


    void resize() {
        do {
            capacity *= growthFactor;
        } while (capacity <= size);
        T* newArr = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }


public:
    DynamicArray() : size(0), capacity(1) {
        arr = new T[capacity];
    }
    ~DynamicArray() {
        delete[] arr;
    }


    void insert(int index, int N, T* values) {  
        if (index > size) {
            return;
        }
        size += N;
        while (size >= capacity) {
            resize();
        }
        copy_backward(arr + index, arr + size - N, arr + size);
        for (int i = 0; i < N; ++i) {  
            arr[index + i] = values[i];
        }
    }


    void erase(int index, int n) {  
        if (index >= size) {
            return;
        }
        int elementsToRemove = min(n, size - index);
        for (int i = index; i < size - elementsToRemove; ++i) {
            arr[i] = arr[i + elementsToRemove];
        }
        size -= elementsToRemove;
    }


    int getSize() const {  
        return size;
    }


    int getCapacity() const {  
        return capacity;
    }


    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }


    void set(int index, T value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        arr[index] = value;
    }


    void print() const {
        for (int i = 0; i < size; ++i) {  
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    int Q;
    cin >> Q;
    DynamicArray<int> dynamicArray;


    for (int i = 0; i < Q; i++) {
        string operat;
        cin >> operat;


        if (operat == "insert") {
            int index, N;
            cin >> index >> N;
            int* values = new int[N];
            for (int j = 0; j < N; ++j) {
                cin >> values[j];
            }
            dynamicArray.insert(index, N, values);
            delete[] values;
        }
        else if (operat == "get") {
            int index;
            cin >> index;
            try {
                cout << dynamicArray[index] << endl;
            } catch (const out_of_range& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (operat == "size") {
            cout << dynamicArray.getSize() << endl;
        }
        else if (operat == "set") {
            int index, value;
            cin >> index >> value;
            try {
                dynamicArray.set(index, value);
            } catch (const out_of_range& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (operat == "erase") {
            int index, n;
            cin >> index >> n;
            dynamicArray.erase(index, n);
        }
        else if (operat == "print") {
            dynamicArray.print();
        }
        else if (operat == "capacity") {
            cout << dynamicArray.getCapacity() << endl;
        }
    }
    return 0;
}


