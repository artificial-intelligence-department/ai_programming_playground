#include <iostream>

const int ARRAY_SIZE = 10;

class CircularArray {
private:
    int mas[ARRAY_SIZE];
    int head;

public:
    CircularArray() : head(0) {
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            mas[i] = i + 1;
        }
    }

    int getElement(int index) const {
        return mas[index];
    }

    void setElement(int index, int value) {
        mas[index] = value;
    }

    void printLeftCircular(int k) const {
        for (int i = k; i != (k - 1 + ARRAY_SIZE) % ARRAY_SIZE; i = (i - 1 + ARRAY_SIZE) % ARRAY_SIZE) {
            std::cout << getElement(i) << " ";
        }
        std::cout << std::endl;
    }

    void removeFirstAndLast() {
        head = (head + 1) % ARRAY_SIZE;
        setElement((head - 1 + ARRAY_SIZE) % ARRAY_SIZE, getElement(head));
        head = (head + 1) % ARRAY_SIZE;
    }

    void printRightCircular(int k) const {
        for (int i = k; i != (k + 1 + ARRAY_SIZE) % ARRAY_SIZE; i = (i + 1) % ARRAY_SIZE) {
            std::cout << getElement(i) << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularArray circularArray;

    std::cout << "Початковий масив: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << circularArray.getElement(i) << " ";
    }
    std::cout << std::endl;

    int k = 3;
    std::cout << "Масив, починаючи з " << k << "-го елемента і до " << k - 1 << ": ";
    circularArray.printLeftCircular(k);

    circularArray.removeFirstAndLast();

    std::cout << "Масив, починаючи з " << k << "-го елемента і до " << k + 1 << ": ";
    circularArray.printRightCircular(k);

    return 0;
}
