#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double radius, volume, surface ;//В коді використана як мінімум одна дійсна з подвійною точністю змінна
    const double PI = 3.14;//В коді використана як мінімум одна цілочисельна константа

    do { //В коді використаний do while цикл
        cout << "Введіть радіус кулі: ";
        cin >> radius;

        if (radius < 0 ) { //В коді використані умовні оператори та розгалуження
            cout << "Некоректний радіус. Будь ласка, введіть додатне число." << endl;
            
            return 0;
        }

        volume = (3.0 / 4.0) * PI * pow(radius, 3);
        surface = 4 * PI * pow(radius, 2);//В коді використано математичні операції та математичні функції -

        cout << "Об'єм кулі: " << volume << endl;
        cout << "Площа поверхні кулі: " << surface << endl;

        cout << "Бажаєте ввести новий радіус? (1 - Так, 0 - Ні): ";
        int choice;//В коді використана як мінімум одна цілочисельна змінна
        cin >> choice;

        if (choice != 1) {
            break;//В коді використано оператори break і continue
        }

    } while (true);

    return 0;
}