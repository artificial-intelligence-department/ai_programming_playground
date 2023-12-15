#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Введення радіуса основи
    cout << "Enter the radius of the base:";
    double radius;
    cin >> radius;

    // Введення висоти циліндра
    cout << "Enter the height of cylinder ";
    double height;
    cin >> height;

    // Обчислення об'єму циліндра
    double volume = M_PI * pow(radius, 2) * height;

    // Виведення результату
    std::cout << "Volume - " << volume << " cubic centimetres \n";

    return 0;
}
