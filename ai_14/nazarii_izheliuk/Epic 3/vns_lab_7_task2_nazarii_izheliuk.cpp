#include <iostream>
#include <algorithm>


void Left(int arr[], int size) {
    std::rotate(arr, arr + 1, arr + size);
}

void Right(int arr[], int size) {
    std::rotate(arr, arr + size - 1, arr + size);
}

int main() {
    int size;
    std::cout << "Введіть розмір масиву: ";
    std::cin >> size;



    int array[size];

    std::cout << "Введіть елементи масиву: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    std::cout << "Масив перед зсувом: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;


    if (array[0] % 2 == 0) {
        Left(array, size);
        std::cout << "Зсув вліво \n";
    } else {
        Right(array, size);
        std::cout << "Зсув вправо \n";
    }

    std::cout << "Результат зсуву: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }


    return 0;
}
