#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    // Генерування та виведення випадкових чисел
    cout << "Generated sequence of random numbers: ";
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        int random_number = rand() % 10 + 1;  // Генерує випадкове число від 1 до 10
        cout << random_number << " ";
        sum += random_number;
    }

    // Обчислення середнього арифметичного
    double average = static_cast<double>(sum) / 10;

    // Виведення середнього арифметичного
    cout << "\nAverage: " << average << endl;

    return 0;
}