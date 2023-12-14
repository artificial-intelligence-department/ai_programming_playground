#include <iostream>
#include <limits> // для використання констант std::numeric_limits

using namespace std;

int main()
{
    // ініціалізація
    int n; // кількість чисел у послідовності
    cout << "Введіть кількість чисел у послідовності: ";
    cin >> n;

    double number;                                         // змінна для введення чисел
    double sum = 0;                                        // сума чисел у послідовності
    double minNumber = std::numeric_limits<double>::max(); // Мінімальне число, початково встановлене на максимально можливе
    double maxNumber = std::numeric_limits<double>::min(); // Максимальне число, початково встановлене на мінімально можливе

    //
    for (int i = 1; i <= n; ++i)
    {
        cout << "Введіть число " << i << ": ";
        cin >> number;

        sum += number; // сума

        // перевірка на мінімальне та максимальне значення
        if (number < minNumber)
        {
            minNumber = number;
        }
        if (number > maxNumber)
        {
            maxNumber = number;
        }
    }

    // формула для обчислення середнього арифметичного
    double average = sum / n;

    // виведення результатів
    cout << "Середнє арифметичне: " << average << endl;
    cout << "Мінімальне число: " << minNumber << endl;
    cout << "Максимальне число: " << maxNumber << endl;

    return 0;
}
