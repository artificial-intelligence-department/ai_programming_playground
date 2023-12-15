#include <iostream>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    size_t N = 100;
    int array[N];
    std::cout << "Enter the desired size of the array:" << std::endl;
    size_t realN;
        std::cin >> realN;
    for (int i = 0; i < realN; i++) {
        array[i] = rand() % 100;
    }

    std::cout << "Original array:" << std::endl;
    printArray(array, realN);
    std::cout << std::endl;

    for (int i = 0; i < realN / 2; i++) {
        std::swap(array[i], array[realN - i - 1]);
    }

    if (realN % 2 != 0) {
        int middleIndex = realN / 2;
        for (int i = middleIndex; i < realN - 1; ++i) {
            array[i] = array[i + 1];
        }
        realN--;
    }

    for (int i = 0; i < 3; i++) {
        array[i] = array[i + 10] - 2;
    }

    std::cout << "Final array:" << std::endl;
    printArray(array, realN);

    return 0;
}