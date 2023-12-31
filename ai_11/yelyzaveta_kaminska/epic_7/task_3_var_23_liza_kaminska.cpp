#include <iostream> // Підключення бібліотеки для введення/виведення на консоль
#include <cmath>    // Підключення бібліотеки для математичних функцій
using namespace std; // Використання простору імен std

int main() {
    // Оголошення 1 завдання
    cout << "Task 3.1" << endl;
    double a;  // Оголошення змінної для розміру куба
    cout << "Enter the size of cube: "; // Текстове повідомлення про введення розміру куба
    cin >> a;// Зчитування значення a
    if (a <= 0) { // Перевірка, чи введене значення не є від'ємним або нульовим
        
        cout << "Error!" << endl; // Виведення повідомлення про помилку та завершення програми з кодом помилки 1
        return 1;
    }

    double V = pow(a, 3);// Обчислення об'єму куба
    cout << "Volume of the cube is: " << V << endl; // Виведення обчисленого об'єму куба на екран


    cout << "Task 3.2" << endl; // Оголошення 2 завдання
    // Оголошення змінних для опорів у електричному ланцюгу
    double R_1;
    double R_2;
    double R;

    cout << "Value of the first resistance:" << endl;// Текстове повідомлення про введення значення першого опору
    cin >> R_1; // Зчитування значення першого опору та збереження його у змінну R_1
    cout << "Value of the second resistance:" << endl; //Текстове повідомлення про введення значення другого опору
    cin >> R_2; // Зчитування значення другого опору та збереження його у змінну R_2
    R = (R_1 * R_2) / (R_1 + R_2);// Обчислення загального опору ланцюгу та збереження результату у змінну R
    cout << "Circuit resistance:" << R << endl; // Виведення обчисленого опору ланцюгу на екран

    return 0; // Успішне завершення програми
}
