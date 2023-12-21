#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Задаємо розмір масиву
    const int arraySize = 10;
    
    // Ініціалізуємо генератор випадкових чисел
    srand(time(0));
    
    // завд 1) Створюємо масив та заповнюємо його випадковими числами
    int susArray[arraySize]; //sus назва створеного масиву
    for (int i = 0; i < arraySize; ++i) {
        susArray[i] = rand() % 88;  // Генеруємо випадкові числа в діапазоні від 0 до 88
    }
    
    // завд 2) Роздруковуємо початковий масив
    cout << "Початковий масив: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << susArray[i] << " ";
    }
    cout << endl;

    // Знаходимо мінімальний та максимальний елементи
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < arraySize; ++i) {
        if (susArray[i] < susArray[minIndex]) {
            minIndex = i;
        }
        if (susArray[i] > susArray[maxIndex]) {
            maxIndex = i;
        }
    }

    // завд 3) Міняємо місцями мінімальний і максимальний елементи
    swap(susArray[minIndex], susArray[maxIndex]);

    // Роздруковуємо масив після заміни
    cout << "Масив після заміни мінімального і максимального елементів: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << susArray[i] << " ";
    }
    cout << endl;

    // Знаходимо середнє значення масиву
    double average = 0;
    for (int i = 0; i < arraySize; ++i) {
        average += susArray[i];
    }
    average /= arraySize;

    // завд 4) Видаляємо елементи, які перевищують середнє значення більш, ніж на 10%
    const double threshold = 0.1;  // 10%
    for (int i = 0; i < arraySize; ++i) {
        if (susArray[i] > (1 + threshold) * average) {
            susArray[i] = 0;  // Позначаємо елемент для видалення 
        }
    }

                //завд 5 ) 
    cout << "Масив після видалення елементів, що перевищують середнє значення на 10%: ";
    for (int i = 0; i < arraySize; ++i) {
        if (susArray[i] != 0) {
            cout << susArray[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
