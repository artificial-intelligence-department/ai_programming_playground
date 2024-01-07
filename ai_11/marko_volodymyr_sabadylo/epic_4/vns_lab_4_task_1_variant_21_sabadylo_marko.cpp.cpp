#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

class CircularArray {
private:
    int array[MAX_SIZE];
    int size;
    int front;
    int rear;

public:
    CircularArray(int s) : size(s), front(-1), rear(-1) {
        for (int i = 0; i < MAX_SIZE; ++i) {
            array[i] = -1;
        }
    }

    void addElement(int value) {
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
            if (rear == front) {
                front = (front + 1) % size;
            }
        }
        array[rear] = value;
    }

    void printArray(int start, int end, int direction) {
        int i = start;
        while (true) {
            cout << array[i] << " ";

            if (i == end) {
                break;
            }

            i = (i + direction + size) % size;
        }
        cout << endl;
    }

    void addSpecialElements() {
        int firstElement = array[front];
        int thirdLastElement = array[(rear - 2 + size) % size];

        addElement(firstElement);
        addElement(thirdLastElement);
        addElement(thirdLastElement);
        addElement(thirdLastElement);
    }

    // Гетери для отримання значень приватних членів
    int getFront() const {
        return front;
    }

    int getRear() const {
        return rear;
    }
};

int main() {
    int K;

    cout << "Enter the size of the circular array: ";
    cin >> K;

    CircularArray circularArray(K);

    for (int i = 1; i <= K; ++i) {
        circularArray.addElement(i);
    }

    cout << "Original circular array (left direction): ";
    circularArray.printArray(circularArray.getFront(), circularArray.getRear(), 1);

    circularArray.addSpecialElements();

    cout << "Modified circular array (right direction): ";
    circularArray.printArray(circularArray.getFront(), circularArray.getRear(), -1);

    return 0;
}