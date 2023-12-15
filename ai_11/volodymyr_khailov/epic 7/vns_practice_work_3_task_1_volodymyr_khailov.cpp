// Варіант 20, задача 1
#include <iostream>

using namespace std;

int main() {
    // 1. в коді використана як мінімум одна цілочисельна змінна
    int timeMinutes, timeSeconds;
    // 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    double distance;

    // 21. в коді використано оператори виведення та введення даних
    // Введення довжини дистанції
    cout << "Введіть довжину дистанції (метрів) > ";
    cin >> distance;

    // Введення часу в хвилинах та секундах через scanf для формату вводу
    cout << "Введіть час (хвилини.секунди) > ";
    scanf("%i.%i", &timeMinutes, &timeSeconds);


    double totalSeconds = timeMinutes * 60 + timeSeconds;
    double speed = (distance / 1000) / (totalSeconds / 3600);

    // 21. в коді використано оператори виведення та введення даних
    // Виведення результатів
    cout << "Дистанція: " << distance << " м" << endl;
    cout << "Час: " << timeMinutes << " хв " << timeSeconds << " сек = " << totalSeconds << " сек" << endl;
    printf("Швидкість: %.2f км/год\n",speed);
    
    return 0;
}

