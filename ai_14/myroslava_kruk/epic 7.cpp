#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Структура даних представлення
struct Data {
    int intValue;
    double doubleValue;
    float floatValue;
};

// Функція для додавання двох об'єктів типу Data
Data add(const Data& a, const Data& b) {
    Data result;
    result.intValue = a.intValue + b.intValue;
    result.doubleValue = a.doubleValue + b.doubleValue;
    result.floatValue = a.floatValue + b.floatValue;
    return result;
}

// Функція для виведення даних структури Data
void printData(const Data& data) {
    cout << "Int: " << data.intValue << ", Double: " << data.doubleValue << ", Float: " << data.floatValue << endl;
}

// Структура для представлення даних розмірів букв та інформації про банер
struct BannerInfo {
    double minLength;
    string symbolsLeftToRight;
    string symbolsRightToLeft;
};

// Функція для розрахунку розмірів букв та символів для банера
BannerInfo calculateBannerInfo(const string& lastName) {
    int vowelCount = 0;

    for (char ch : lastName) {
        char lowerCh = tolower(ch);
        if (lowerCh == 'u') {
            vowelCount++;
        }
    }

    double letterWidth = vowelCount * 0.8;

    // Мінімальна довжина для розміщення банера
    double minLength = letterWidth * lastName.length();

    // Визначення середини прізвища
    int middleIndex = lastName.length() / 2;

    // Визначення діапазону символів на 3-х центральних метрах (зліва направо)
    int startLeftToRight = middleIndex;
    int endLeftToRight = middleIndex + 3;
    string symbolsLeftToRight = lastName.substr(startLeftToRight, endLeftToRight - startLeftToRight);

    // Визначення діапазону символів на 3-х центральних метрах (справа наліво)
    int startRightToLeft = middleIndex - 2;
    int endRightToLeft = middleIndex + 1;
    string symbolsRightToLeft = lastName.substr(startRightToLeft, endRightToLeft - startRightToLeft);

    // Створення об'єкта BannerInfo з результатами
    BannerInfo bannerInfo;
    bannerInfo.minLength = minLength;
    bannerInfo.symbolsLeftToRight = symbolsLeftToRight;
    bannerInfo.symbolsRightToLeft = symbolsRightToLeft;

    return bannerInfo;
}

// Рекурсивна функція для обчислення факторіалу
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Функція з параметрами та аргументами для обчислення експоненти
double calculateExponential(double base, int exponent) {
    return pow(base, exponent);
}

// Функція для роботи із вказівниками
void pointerDemo() {
    // Створення об'єкта структури
    Data data1 = {1, 2.5, 3.14};

    // Вказівник на структуру
    Data* ptrData = &data1;

    // Звертання до полів через вказівник
    cout << "Accessing fields using pointers: " << ptrData->intValue << " " << ptrData->doubleValue << " " << ptrData->floatValue << endl;

    // Динамічне виділення пам'яті для структури
    Data* dynamicData = new Data;
    dynamicData->intValue = 5;
    dynamicData->doubleValue = 1.5;
    dynamicData->floatValue = 2.71;

    // Виклик функції для додавання двох структур
    Data sum = add(data1, *dynamicData);

    // Виведення результату
    cout << "Sum of two structs: ";
    printData(sum);

    // Очистка пам'яті
    delete dynamicData;
}

// Функція для роботи з файлами (запис у файл)
void writeToTextFile(const string& fileName, const string& content) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
    }
}

// Функція для роботи з файлами (зчитування з файлу)
string readFromTextFile(const string& fileName) {
    ifstream inFile(fileName);
    string fileContent;
    if (inFile.is_open()) {
        getline(inFile, fileContent);
        inFile.close();
    }
    return fileContent;
}

int main() {
    // Ваше прізвище (замість "Kruk")
    string lastName = "Kruk";

    // Максимальна довжина поля (130 ярдів)
    const double maxLength = 130.0;

    // Розрахунок мінімальної довжини для розміщення банера та символів на 3-х центральних метрах
    BannerInfo bannerInfo;
    bool bannerFits = false;

    for (int i = 0; i < 10; ++i) {
        bannerInfo = calculateBannerInfo(lastName);

        if (bannerInfo.minLength <= maxLength) {
            bannerFits = true;
            break; // вийти з циклу, якщо банер влазить на поле
        }

        // Збільшення кількості голосних букв, якщо банер не влазить на поле
        lastName += 'a';
    }

    if (bannerFits) {
        // Виведення результатів
        cout << "Мінімальна довжина для розміщення банера: " << bannerInfo.minLength << " метрів" << endl;
        cout << "Символи на 3-х центральних метрах (зліва направо): " << bannerInfo.symbolsLeftToRight << endl;
        cout << "Символи на 3-х центральних метрах (справа наліво): " << bannerInfo.symbolsRightToLeft << endl;

        // Використання оператора continue
        for (int i = 0; i < 10; ++i) {
            if (i % 2 == 0) {
                cout << "Це парне число: " << i << endl;
                continue; // перейти до наступної ітерації циклу, якщо число парне
            }
            cout << "Це непарне число: " << i << endl;
        }

        // Використання рекурсивної функції та обчислення факторіалу
        int factorialResult = factorial(5);
        cout << "Факторіал числа 5: " << factorialResult << endl;

        // Використання функції з параметрами та аргументами
        double expResult = calculateExponential(2.0, 3);
        cout << "Експонента (2^3): " << expResult << endl;

        // Використання функцій для роботи з файлами та операторів виведення та введення даних
        writeToTextFile("output.txt", "7 epic");
        string fileContent = readFromTextFile("output.txt");
        cout << "Зміст файлу: " << fileContent << endl;
    } else {
        cout << "Банер надто великий для поля." << endl;
    }

    return 0;
}
