#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std; 

struct FieldDimensions {
    int length; 
    int width;
};

int calculateFieldLength(int variant) {
    return 100 + (variant - 11) * 10; // Використана цілочисельна змінна для розрахунку
}

// Функція для запису розмірів поля в файл
void writeFieldDimensionsToFile(const FieldDimensions& field) {
    ofstream file("field_dimensions.txt"); // Використано функції роботи з файлами для запису
    if (file.is_open()) {
        file << "Length: " << field.length << " yards\n";
        file << "Width: " << field.width << " yards\n";
        file.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

// Функція для зчитування розмірів поля з файлу
FieldDimensions readFieldDimensionsFromFile() {
    FieldDimensions field;
    ifstream file("field_dimensions.txt"); // Використано функції роботи з файлами для зчитування
    if (file.is_open()) {
        file >> field.length;
        file >> field.width;
        file.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
    }
    return field;
}

int main() {
    // Константи для перетворень одиниць вимірювання
    const double YARD_TO_METERS = 0.9144;
    const double FOOT_TO_YARDS = 0.333333;
    const double INCH_TO_FEET = 0.0833333;
    const double INCH_TO_CM = 2.54;

    // Варіант розміру поля
    int fieldVariant = 11; // Змініть значення відповідно до вибору варіанту

    // Розміри поля в ярдах
    FieldDimensions field; // Використана структура для збереження розмірів поля
    field.length = calculateFieldLength(fieldVariant);

    
    string surname = "Zastavnyy";

    // Кількість голосних букв у прізвищі
    const int vowelsCount = 2; // Використана цілочисельна константа

    // Ширина букви з інтервалом між символами
    double letterWidth = vowelsCount * 0.8; // Використана дійсна змінна

    // Кількість символів на 3 центральних метрах поля
    int charactersOnThreeMeters = static_cast<int>(3 / letterWidth);

    // 1) Написання прізвища з лівого краю до правого
    cout << "From left to right: ";
    for (int i = 0; i < charactersOnThreeMeters; ++i) {
        cout << surname[i];
    }
    cout << endl;

    // 2) Написання прізвища з правого краю до лівого
    cout << "From right to left: ";
    for (int i = 0; i < charactersOnThreeMeters; ++i) {
        cout << surname[surname.length() - 1 - i];
    }
    cout << endl;

   
    writeFieldDimensionsToFile(field);

   
    FieldDimensions readField = readFieldDimensionsFromFile();
    cout << "Read Field Length: " << readField.length << " yards\n";

    return 0;
}