#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
class CustomArray {
private:
    T* elements;
    long int size;
    long int capacity;

public:

    CustomArray() : size(0), capacity(1) {
        elements = new T[capacity];
    }

    ~CustomArray() {
        delete[] elements;
    }

    void insert(long int index, long int count, T* values) {
        if (index < 0 || index > size)
            return;

        if (size + count >= capacity) {
            long int changedCapacity = capacity;

            while (size + count >= changedCapacity) {
                changedCapacity *= 2;
            }
            T* changedElements = new T[changedCapacity];
            size += count;

            for (int i = 0; i < size; ++i) {
                changedElements[i] = elements[i];
            }

            delete[] elements;
            elements = changedElements;

            std::copy_backward(elements + index, elements + size - count, elements + size);
            for (size_t i = 0; i < count; ++i) {
                elements[index + i] = values[i];
            }

            capacity = changedCapacity;
        } else {

            for (int i = size - 1; i >= index; --i) {
                elements[i + count] = elements[i];
            }

            for (int i = 0; i < count; ++i) {
                elements[index + i] = values[i];
            }

            size += count;
        }
    }


    void erase(long int index, long int count) {

        long int deleteCount = std::min(count, size - index);
        for (int i = index; i < size - deleteCount; ++i) {
            elements[i] = elements[i + deleteCount];
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
            std::cout << elements[i] << " ";
        }

    }
    T& operator[](long int index) {
        return elements[index];
    }
};

int main() {
    using namespace std;

    long int Q;
    cin >> Q;

    CustomArray<long int> customArray;

    while (Q--) {
        string command;
        cin >> command;
        char action = command[0];

        long int index, count;
        long int* values;

        switch (action) {
            case 'i':
                cin >> index >> count;

                values = new long int[count];
                for (int i = 0; i < count; ++i) {
                    cin >> values[i];
                }

                customArray.insert(index, count, values);
                delete[] values;

                break;

            case 'e':
                cin >> index >> count;
                customArray.erase(index, count);

                break;

            case 's':
                if (command == "size") {
                    cout << customArray.Size() << endl;
                } else if (command == "set") {
                    cin >> index >> count;

                    if (index >= 0 && index < customArray.Size()) {
                        customArray[index] = count;
                    }
                }
                break;

            case 'c':
                cout << customArray.Capacity() << endl;
                break;

            case 'g':
                cin >> index;

                if (index >= 0 && index < customArray.Size()) {
                    cout << customArray[index] << endl;
                }
                break;

            case 'p':
                customArray.print();
                cout << endl;

                break;

            default:
                cout << "Unknown action\n";
        }
    }

    return 0;
}
