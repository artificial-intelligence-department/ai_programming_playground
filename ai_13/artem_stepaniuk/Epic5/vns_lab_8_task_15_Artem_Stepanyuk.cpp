#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Car {
    char brand[50];
    int year;
    float price;
    char color[20];
};

void printCar(const Car& car) {
    cout << "Марка: " << car.brand << "\n";
    cout << "Рік випуску: " << car.year << "\n";
    cout << "Ціна: " << car.price << "\n";
    cout << "Колір: " << car.color << "\n\n";
}

void createFile(const char* filename, const Car* cars, int size) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка при відкритті файлу для запису.\n";
        exit(EXIT_FAILURE);
    }

    file.write(reinterpret_cast<const char*>(cars), sizeof(Car) * size);

    if (!file) {
        cerr << "Помилка при записі в файл.\n";
        exit(EXIT_FAILURE);
    }

    file.close();
}

void readFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка при відкритті файлу для читання.\n";
        exit(EXIT_FAILURE);
    }

    Car car;
    while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
        printCar(car);
    }

    file.close();
}

void modifyFile(const char* filename, int minYear, const Car& newCar) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Помилка при відкритті файлу для модифікації.\n";
        exit(EXIT_FAILURE);
    }

    Car car;
    while (file.read(reinterpret_cast<char*>(&car), sizeof(Car))) {
        if (car.year < minYear) {
            cout << "Вилучено елемент:\n";
            printCar(car);
        } else {
            file.seekp(-static_cast<std::ios::off_type>(sizeof(Car)), ios::cur);
            file.write(reinterpret_cast<const char*>(&car), sizeof(Car));
        }
    }

    file.seekp(0, ios::beg);
    file.write(reinterpret_cast<const char*>(&newCar), sizeof(Car));

    file.close();
}

int main() {
    Car cars[] = {
        {"Toyota", 2020, 25000.0, "Червоний"},
        {"Ford", 2018, 20000.0, "Синій"},
        {"PESPATRON", 2022, 30000.0, "Чорний"},
        {"BMW", 2019, 40000.0, "Чорний"},
    };

    const int size = sizeof(cars) / sizeof(Car);

    createFile("cars.dat", cars, size);

    cout << "Вміст файлу до модифікації:\n";
    readFile("cars.dat");

    int minYear = 2020;
    Car newCar = {"Nissan", 2021, 28000.0, "Зелений"};

    modifyFile("cars.dat", minYear, newCar);

    cout << "\nВміст файлу після модифікації:\n";
    readFile("cars.dat");

    return 0;
}