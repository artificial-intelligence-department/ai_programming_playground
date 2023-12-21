#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class DynamicArray {
private:
    long int* elements;
    long int currentSize;
    long int maxCapacity;

public:
    DynamicArray() : currentSize(0), maxCapacity(1) {
        elements = new long int[maxCapacity];
    }

    ~DynamicArray() {
        delete[] elements;
    }

    void insert(long int index, long int count, long int* values) {
        if (index < 0 || index > currentSize)
            return;

        if (currentSize + count >= maxCapacity) {
            long int newCapacity = maxCapacity;

            while (currentSize + count >= newCapacity) {
                newCapacity *= 2;
            }
            long int* newArray = new long int[newCapacity];
            currentSize += count;

            for (int i = 0; i < currentSize; ++i) {
                newArray[i] = elements[i];
            }

            delete[] elements;
            elements = newArray;

            copy_backward(elements + index, elements + currentSize - count, elements + currentSize);
            for (size_t i = 0; i < count; ++i) {
                elements[index + i] = values[i];
            }

            maxCapacity = newCapacity;
        }
        else {
            for (int i = currentSize - 1; i >= index; --i) {
                elements[i + count] = elements[i];
            }

            for (int i = 0; i < count; ++i) {
                elements[index + i] = values[i];
            }

            currentSize += count;
        }
    }

    void erase(long int index, long int n) {
        long int deletionCount = min(n, currentSize - index);
        for (int i = index; i < currentSize - deletionCount; ++i) {
            elements[i] = elements[i + deletionCount];
        }

        currentSize -= deletionCount;
    }

    long int Size() {
        return currentSize;
    }

    long int Capacity() {
        return maxCapacity;
    }

    void print() {
        for (int i = 0; i < currentSize; ++i) {
            std::cout << elements[i] << " ";
        }
    }

    long int& operator[](long int index) {
        return elements[index];
    }
};

int main() {

    long int numCommands;
    cin >> numCommands;

    DynamicArray dynamicArray;

    while (numCommands--) {
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
            dynamicArray.insert(index, count, values);
            delete[] values;
            break;

        case 'e':
            cin >> index >> count;
            dynamicArray.erase(index, count);
            break;

        case 's':
            if (command == "size") {
                cout << dynamicArray.Size() << endl;
            }
            else if (command == "set") {
                cin >> index >> count;
                if (index >= 0 && index < dynamicArray.Size()) {
                    dynamicArray[index] = count;
                }
            }
            break;

        case 'c':
            cout << dynamicArray.Capacity() << endl;
            break;

        case 'g':
            cin >> index;
            if (index >= 0 && index < dynamicArray.Size()) {
                cout << dynamicArray[index] << endl;
            }
            break;

        case 'p':
            dynamicArray.print();
            break;

        default:
            cout << "Unknown action\n";
        }
    }

    return 0;
}
