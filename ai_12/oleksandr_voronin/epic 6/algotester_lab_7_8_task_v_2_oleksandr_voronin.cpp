#include <iostream>

using namespace std;

class DynamArray {
private:

    int *arr;
    int size;
    int capacity;

public:

    DynamArray() : arr(nullptr), size(0), capacity(1) {
        arr = new int[capacity];
    }

    ~DynamArray() {
        delete[] arr;
    }

    void resize(int newCapacity) {
        int *newArr = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

    void insert(int index, int n, int *data) {
        if (size + n >= capacity) {
            while (size + n >= capacity) {
                capacity *= 2;
            }

            resize(capacity);
        }

        for (int i = size - 1; i >= index; i--) {
            arr[i + n] = arr[i];
        }

        for (int i = 0; i < n; i++) {
            arr[index + i] = data[i];
        }

        size = size + n;
    }

    void erase(int index, int n) {
        int left = size - index - n;

        for (int i = 0; i < left; ++i) {
            arr[index + i] = arr[index + i + n];
        }

        size -= n;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    int get(int index) const {
        return arr[index];
    }

    void set(int index, int data) {
        arr[index] = data;
    }

    void printArr() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    int Q;
    DynamArray arr;

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string rqst;

        cin >> rqst;

        if (rqst == "size") {
            cout << arr.getSize() << endl;
        } 
        else if (rqst == "insert") {
            int index, num;

            cin >> index >> num;

            int *data = new int[num];

            for (int i = 0; i < num; i++) {
                cin >> data[i];
            }

            arr.insert(index, num, data);
            delete[] data;
        } 
        else if (rqst == "capacity") {
            cout << arr.getCapacity() << endl;
        } 
        else if (rqst == "erase") {
            int index, num;

            cin >> index >> num;
            arr.erase(index, num);
        } 
        else if (rqst == "set") {
            int index, data;

            cin >> index >> data;
            arr.set(index, data);
        } 
        else if (rqst == "get") {
            int index;
            cin >> index;
            cout << arr.get(index) << endl;
        } 
        else if (rqst == "print") {
            arr.printArr();
        }
    }

    return 0;
}