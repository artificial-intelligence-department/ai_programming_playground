// Скласти програму, яка генерує послідовності з 10
// випадкових чисел в діапазоні від 1 до 10, виводить ці числа на екран
// і обчислює їх середнє арифметичне. 

#include <iostream>
#include <cstdlib>

using namespace std;


int main() {

    srand(time(NULL));

    int min = 1;
    int max = 10;

    int mass[10]; // в коді використано одновимірний масив
    float sum = 0;

    for (int i = 0; i < 10; i++) {  //в коді використано цикл for для введення елементів у масив

        mass[i] = min + rand() % (max - min + 1); // використано функцію srand/rand
        cout << mass[i] << " ";

        sum += mass[i];
    }

    cout << endl << "Середнє арифметичне цих чисел: " << sum/10; 

    return 0;
}