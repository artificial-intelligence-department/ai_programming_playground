#include <iostream>
#include <cstdarg>

using namespace std;

// 12 Перевантаження функції average для роботи з масивами
double average(int amount, double numbers[]) {
    double sum = 0;    //13. в коді використано рекурсивну функцію
    
    for (int i = 0; i < amount; i++) {
        sum += numbers[i];
    }
    
    return sum / amount;
}

int main() {
    double numbers[5];//6. створення одновимірного масиву для збереження 5 введених чисел 
    
    for (int i = 0; i < 5; i++) {
        cout << "Enter the number # " << i + 1 << " : ";
        cin >> numbers[i];
    }

    //9. в коді використаний while цикл
    int i = 0;
    while (i < 5) {
        if (numbers[i] < 0) {
            cout << "Negative number encountered. Exiting the loop." << endl;
            break;    //11. в коді використано оператори break і continue

        }

        if (numbers[i] == 0) {
            cout << "Zero encountered. Skipping to the next iteration." << endl;
            i++;
            continue;
        }

        cout << "Processing number: " << numbers[i] << endl;
        i++;
    }

    // Знаходження та виведення середнього арифметичного з використанням перевантаженої функції
    double averageValue = average(5, numbers);
    cout << "The average value is " << averageValue << endl;

    return 0;
}
