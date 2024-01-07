#include <iostream>
#include <fstream>

double parallelepipedVolume(double a, double b, double c);
double poundsToKilograms(double weight);
double poundsToKilograms(int weight);

int main() {
    double length, width, height, volume;

    std::cout << "Обчислення об'єму паралелепіпеда\n";
    std::cout << "Введіть початкові дані\n";
    std::cout << "Довжина (см) > ";
    std::cin >> length;
    std::cout << "Ширина (см) > ";
    std::cin >> width;
    std::cout << "Висота (см) > ";
    std::cin >> height;

    volume = parallelepipedVolume(length, width, height);

    //Вимога 19 - в коді використано функції роботи з файлами, для того, щоб записати у файл (змінна volume вводиться в файл)
    std::ofstream file_1("volume.txt");
    file_1 << volume;
    file_1.close();

    //Вимога 20 - в коді використано функції роботи з файлами, для того, щоб зчитати у файл (з файлу зчитується змінна volume)
    std::ifstream file_2("volume.txt");
    file_2 >> volume;
    file_2.close();

    std::cout << "Об'єм: " << volume << " куб.см" << std::endl;

    //ЗАВДАННЯ 2

    double pounds, kilograms;

    std::cout << "Enter weight in pounds: ";
    std::cin >> pounds;

    kilograms = poundsToKilograms(pounds);
    std::cout << pounds << " pounds in kilograms equals " << kilograms;

    return 0;
}

double parallelepipedVolume(double a, double b, double c) {
    double volume = a * b * c;

    return volume;
}

//Вимога 16 - в коді використано параметри та аргументи функції (як аргумент функція приймає дійсну змінну з подвійною точністю)
double poundsToKilograms(double weight) {
    return weight * 0.4059;
}
//Вимога 12 - в коді використано перевантаження функції (функція є перевантаженою для цілочисельних змінних)
double poundsToKilograms(int weight) {
    return weight * 0.4059;
}