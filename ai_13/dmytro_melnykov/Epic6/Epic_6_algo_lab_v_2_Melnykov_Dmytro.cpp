#include <iostream>
#include <string>

using namespace std;

template<typename Type>
struct MyArray {

    int size = 0;
    int capacity = 1;
    Type *data;

    MyArray() {
        data = new Type[1];
    }

    void insert(int index, int arrSize, Type* arr) {

        if (capacity > size + arrSize) {

            for (int i = size - 1; i > index - 1; i--) {
                data[i + arrSize] = data[i];
            }

            for (int i = 0; i < arrSize; ++i) {
                data[i + index] = arr[i];
            }

            size += arrSize;

        } else {

            while (capacity <= size + arrSize) {
                capacity *= 2;
            }

            Type *newData = new Type[capacity];

            for (int i = 0; i < index; ++i) {
                newData[i] = data[i];
            }

            for (int i = 0; i < arrSize; ++i) {
                newData[i + index] = arr[i];
            }

            for (int i = index; i < size; ++i) {
                newData[i + arrSize] = data[i];
            }

            delete[] data;
            data = newData;
            size += arrSize;
        }
    }

    void erase(int index, int n) {

        for (int i = index; i < size; ++i) {
            data[i] = data[i + n];
        }
        size -= n;
    }

    int mySize() {
        return size;
    }

    int myCapacity() {
        return capacity;
    }

    Type &operator[](int index) {
        return data[index];
    }

    friend ostream &operator<<(ostream &os, const MyArray &array) {
        for (int i = 0; i < array.size; ++i) {
            os << array.data[i] << ' ';
        }
        return os;
    }
};

int main() {

    MyArray<int> myArray;

    int Q;
    cin >> Q;

    string ident;
    for (int i = 0; i < Q; ++i) {
        cin >> ident;

        if (ident == "insert") {
            int index, arrSize;
            cin >> index >> arrSize;

            int *arr = new int[arrSize];
            for (int j = 0; j < arrSize; ++j) {
                cin >> arr[j];
            }
            myArray.insert(index, arrSize, arr);
            delete[] arr;

        } else if (ident == "erase") {
            int index, n;
            cin >> index >> n;
            myArray.erase(index, n);

        } else if (ident == "size") {
            cout << myArray.mySize() << endl;

        } else if (ident == "capacity") {
            cout << myArray.myCapacity() << endl;

        } else if (ident == "get") {
            int index;
            cin >> index;
            cout << myArray[index] << endl;

        } else if (ident == "set") {
            int index;
            cin >> index;
            cin >> myArray[index];

        } else if (ident == "print") {
            cout << myArray << endl;
        }
    }

    return 0;
}
