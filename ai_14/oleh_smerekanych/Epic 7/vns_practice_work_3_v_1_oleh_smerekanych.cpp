#include <iostream>         //бібліотека 
using namespace std;

double poundsToKilograms(double pounds) {
    const double GRAMS_IN_POUND = 453.592;  // Один фунт = 453.592 грамів
    const double KILOGRAMS_IN_GRAM = 0.001;  // Один грам = 0.001 кілограма

    // Перерахунок ваги
    double kilograms = (pounds * GRAMS_IN_POUND) * KILOGRAMS_IN_GRAM;
    return kilograms;
}


int main() {
    cout << "Volume of a parallelepiped.\n";        //виведення стрічки
    
    double length, width, height;           //ініціалізація дійсних змінних
    cout << "Enter length : ";
    cin >> length;
    cout << "Enter width : ";               //зчитування даних
    cin >> width;
    cout << "Enter height : ";
    cin >> height;
    double volume = length * width * height;
    cout << "Volume:" << volume << endl;

    double weightInPounds;
    cout << "Enter weight in pounds: ";
    cin >> weightInPounds;

    // Виклик функції та вивід результату
    double weightInKilograms = poundsToKilograms(weightInPounds);
    cout << "weight in pounds: " << weightInKilograms << " kilos" << endl;

    return 0;
}
