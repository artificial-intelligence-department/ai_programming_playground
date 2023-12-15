#include <iostream>
#include <ctime>
#include <cstdlib>
 
int main() {
    const short n=100;
    int array[n];
    std::cout << "Enter length of array: \n";
    short size;
    std::cin >> size;
    srand(time(0));
    std::cout << "Random-generated array: \n";
    for (short i = 0; i < size; i++) { 
        array[i] = rand(); 
        std::cout << array[i] << "  ";
    }
    std::cout << "\nEnter number of element you want to erase: \n";
    short destroy;
    std::cin >> destroy;
    destroy--, size--;
    for (; destroy < size; destroy++) { array[destroy] = array[destroy+1]; }

    for (short i = 0; i <size; i++) {
        if (array[i] % 2 == 0) {
            for (short b = size; b > i+1; b--) { array[b] = array[b-1]; }
            size++, i++;
            array[i] = array[i-1] + 2; 
            break;
        }
    }
    std::cout << "Updated array: \n";
    for (short i = 0; i<size; i++) {
        std::cout << array[i] << "  ";
    }
    return 0;
}