#include <iostream>     //Підключаю бібліотеку С++, а також математичну бібліотеку
#include <cmath>
using namespace std;

// Функція для обчислення площі поверхні циліндра
double calculateCylinderSurfaceArea(double radius, double height) {
    const double pi = 3.141592653589793;
    return 2 * pi * radius * (radius + height);
}

// Функція для обчислення опору електричного ланцюга
double calculateResistance(double resistor1, double resistor2) {
    // Формула для обчислення опору двох паралельно з'єднаних резисторів
    return (resistor1 * resistor2) / (resistor1 + resistor2);
}

int main() {
    // Обчислення площі поверхні циліндра
    cout << "Calculation of the surface area of a cylinder." << endl;
    
    double radius, height;
    
    // Введення даних
    cout << "Enter the radius of the base (cm) > ";
    cin >> radius;
    
    cout << "Enter the height of the cylinder (cm) > ";
    cin >> height;

    // Обчислення та вивід результату
    double surfaceArea = calculateCylinderSurfaceArea(radius, height);
    cout << "Surface area of the cylinder: " << surfaceArea << " sq.cm." << endl;

    // Обчислення опору електричного ланцюга
    cout << "\nCalculation of the resistance of an electrical circuit consisting of two parallel connected resistors." << endl;
    
    double resistor1, resistor2;
    
    // Введення даних
    cout << "Enter the resistance of the first resistor > ";
    cin >> resistor1;
    
    cout << "Enter the resistance of the second resistor > ";
    cin >> resistor2;

    // Обчислення та вивід результату
    double totalResistance = calculateResistance(resistor1, resistor2);
    cout << "Total resistance of the circuit: " << totalResistance << " ohms." << endl;

    return 0;
}
