#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct DynamicArray {
    long int* massive;
    long int size;
    long int capacity;

    DynamicArray() : size(0), capacity(1) {
        massive = new long int[capacity];
    }

    ~DynamicArray() {
        delete[] massive;
    }

    void insert(long int a, long int N, long int* value) {
        if (a < 0 || a > size)
            return;

        if (size + N >= capacity) {
            long int changedCapacity = capacity;

            while (size + N >= changedCapacity) {
                changedCapacity *= 2;
            }
            long int* changedArr = new long int[changedCapacity];
            size += N;

            for (int i = 0; i < size; ++i) {
                changedArr[i] = massive[i];
            }

            delete[] massive;
            massive = changedArr;

            copy_backward(massive + a, massive + size - N, massive + size);
            for (size_t i = 0; i < N; ++i) {
                massive[a + i] = value[i];
            }

            capacity = changedCapacity;
        } else {

            for (int i = size - 1; i >= a; --i) {
                massive[i + N] = massive[i];
            }

            for (int i = 0; i < N; ++i) {
                massive[a + i] = value[i];
            }

            size += N;
        }
    }

    void erase(long int a, long int n) {
        long int deleteCount = min(n, size - a);
        for (int i = a; i < size - deleteCount; ++i) {
            massive[i] = massive[i + deleteCount];
        }

        size -= deleteCount;
    }

    long int Size() const {
        return size;
    }

    long int Capacity() const {
        return capacity;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << massive[i] << " ";
        }
    }

    long int& operator[](long int a) {
        return massive[a];
    }
};

int main() {

    long int N;
    cin >> N;

    DynamicArray dynArray;

    while (N--) {
        string answer;
        cin >> answer;
        char sym = answer[0];

        long int a, n;
        long int* value;

        switch (sym) {
            case 'i':
                cin >> a >> n;

                value = new long int[n];
                for (int i = 0; i < n; ++i) {
                    cin >> value[i];
                }

                dynArray.insert(a, n, value);
                delete[] value;

                break;

            case 'e':
                cin >> a >> n;
                dynArray.erase(a, n);

                break;

            case 's':
                if (answer == "size") {
                    cout << dynArray.Size() << endl;
                } else if (answer == "set") {
                    cin >> a >> n;

                    if (a >= 0 && a < dynArray.Size()) {
                        dynArray[a] = n;
                    }
                }
                break;

            case 'c':
                cout << dynArray.Capacity() << endl;
                break;

            case 'g':
                cin >> a;

                if (a >= 0 && a < dynArray.Size()) {
                    cout << dynArray[a] << endl;
                }
                break;

            case 'p':
                dynArray.print();
                cout << endl;

                break;

            default:
                cout << "Error" << endl;
        }
    }

    return 0;
}
