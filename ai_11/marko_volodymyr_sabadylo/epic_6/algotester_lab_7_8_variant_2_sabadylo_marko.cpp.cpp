#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray() : arr(new int [1]), size(0), capacity(1) {}

    ~DynamicArray() {
        delete[] arr;
    }

    int& operator[](int index) {
        return arr[index];
    }

    void insert(int index, int N, int* values) {
        if (index < 0 || index > size) return;
        resize(N);

        for (int i = size - 1; i >= index; i--) {
            arr[i + N] = arr[i];
        }

        for (int i = 0; i < N; i++) {
            arr[index + i] = values[i];
        }

        size += N;
        resize();
    }

    void erase(int index, int n) {
        if (index < 0 || index >= size) return;

        for (int i = index + n; i < size; i++) {
            arr[i - n] = arr[i];
        }

        size -= n;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    friend ostream& operator<<(ostream& os, const DynamicArray& da) {
        for (int i = 0; i < da.size; i++) {
            os << da.arr[i] << " ";
        }
        return os;
    }

private:
    void resize(int N=0) {
        while(size + N >=capacity) {
            int newCapacity = capacity * 2;
            int *temp = new int[newCapacity];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            arr = temp;
            capacity = newCapacity;
         }
    }
};

int main() {
    int Q;
    cin >> Q;

    DynamicArray da;

    for(int j=0;j<Q;j++) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int index, N;
            cin >> index >> N;
            int* values = new int[N];
            for (int i = 0; i < N; i++) {
                cin >> values[i];
            }
            da.insert(index, N, values);
//            cout << da.getSize() << endl;   // Вивід розміру після вставки
//            cout << da.getCapacity() << endl; // Вивід ємності після вставки
            delete[] values;
        } else if (operation == "erase") {
            int index, n;
            cin >> index >> n;
            da.erase(index, n);
        } else if (operation == "size") {
            cout << da.getSize() << endl;
        } else if (operation == "capacity") {
            cout << da.getCapacity() << endl;
        } else if (operation == "get") {
            int index;
            cin >> index;
            cout << da[index] << endl;
        } else if (operation == "set") {
            int index, value;
            cin >> index >> value;
            da[index] = value;
        } else if (operation == "print") {
            cout << da << endl;
        }
    }

    return 0;
}