#include <iostream>
#include <string>
using namespace std;

template <typename T>
class DynamicArr {
    T* array;
    int size;
    int capacity;

public:
    DynamicArr() {
        capacity = 1;
        array = new T[capacity];
        size = 0;
    }

    ~DynamicArr() {
        delete[] array;
    }

    void get_size() {
        cout << size << endl;
    }

    void get_capacity() {
        cout << capacity << endl;
    }

    void get_el(int index) {
        cout << array[index] << endl;
    }

    void set_el(int index, T number) {
        array[index] = number;
    }

    void insert_el(int index, T* numbers, int N) {
        if (size + N >= capacity) {
            while (size + N >= capacity) {
                capacity *= 2;
            }
            T* newArray = new T[capacity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }

        T* newArray = new T[capacity];

        for (int i = 0; i < index && index > 0; i++) {
            newArray[i] = array[i];
        }
        for (int i = index, j = 0; j < N; i++, j++) {
            newArray[i] = numbers[j];
        }
        for (int i = index + N, j = index; j < size; i++, j++) {
            newArray[i] = array[j];
        }
        size += N;
        delete[] array;
        array = newArray;
    }

    void erase_el(int index1, int num) {
        int index2 = index1 + num - 1;
        T* newArray = new T[capacity];
        for (int i = 0; i < index1; i++) {
            newArray[i] = array[i];
        }
        for (int i = index1, j = index2 + 1; j < size; i++, j++) {
            newArray[i] = array[j];
        }
        size = size - num;
        delete[] array;
        array = newArray;
    }

    friend ostream& operator<<(ostream& out, DynamicArr<T>& array) {
        for (int i = 0; i < array.size; i++) {
            out << array.array[i] << " ";
        }
        return out;
    }
};

int main() {
    DynamicArr<int> arr;
    int Q;
    cin >> Q;
    string requests;
    for (int i = 0; i < Q; i++) {
        cin >> requests;
        if (requests == "insert") {
            int index, N;
            cin >> index >> N;
            int* numbers = new int[N];
            for (int i = 0; i < N; i++) {
                cin >> numbers[i];
            }
            arr.insert_el(index, numbers, N);
            delete[] numbers;
        } else if (requests[0] == 's' && requests[1] == 'i') {
            arr.get_size();
        } else if (requests[0] == 'c') {
            arr.get_capacity();
        } else if (requests[0] == 'g') {
            int index;
            cin >> index;
            arr.get_el(index);
        } else if (requests[0] == 's' && requests[1] == 'e') {
            int index, number;
            cin >> index >> number;
            arr.set_el(index, number);
        } else if (requests[0] == 'p') {
            cout << arr;
        } else if (requests[0] == 'e') {
            int index1, num;
            cin >> index1 >> num;
            arr.erase_el(index1, num);
        }
    }
    return 0;
}
