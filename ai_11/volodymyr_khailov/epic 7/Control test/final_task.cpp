// ТЕКСТ ЗАДАЧІ

// Загальні відомості
// В американській системі виміру довжин використовуються ярди, фути, дюйми. 1 Ярд = 3 фути. 1 Фут = 12 дюймів. 1 Дюйм = 2.54 см.
// Футбольні поля мають можуть мати різну довжину
// Довжина: мінімум 100 ярдів, максимум 130 ярдів.
// Ширина: мінімум 50 ярдів, максимум 100 ярдів.

// // Довжина задається по варіанту 100 - 110 -120 - 130 для кожної групи інший розмір поля. ШІ -11  100 ярдів, ШІ -12 110 ярдів … і т.д.

// Використовуючи Ваше прізвище розрахувати найменшу довжину, яка необхідна для розміщення банера з Вашим прізвищем.
//  За умови, що прізвище можна записати лише в 1 ряд, а ширина букви(разом з інтервалом між символами) = кількості голосних букв у Вашому прізвищі * 0.8 метра.
// На основі обчислених розмірів букви визначити символи, які будуть знаходитись на 3-х центральних(по довжині) метрах поля. 

// Обчислення зробити для 2-х випадків:
// 1) при написанні прізвища з лівого краю поля —>  до правого
// 2) при написанні прізвища з правого краю поля <—  до лівого.
// Результат записати.

// Ширину не потрібно було використовувати, була реалізовано структура для преведення з ярдів до метрів,
// також використано for та while для виведення остаточного резултату. (Додатково використано і файл введеня та зчитування.)

#include <iostream>
#include <fstream>  // Додано бібліотеку для роботи з файлами

using namespace std;

// Структура для конвертації довжини з ярдів, футів, дюймів в метри
struct LengthConverter {
    double yardsToMeters;
    double feetToMeters;
    double inchesToCentimeters;

    LengthConverter() {
        yardsToMeters = 0.9144;
        feetToMeters = 0.3048;
        inchesToCentimeters = 2.54;
    }

    // Метод для конвертації довжини з ярдів в метри
    double convertYardsToMeters(double yards) {
        return yards * yardsToMeters;
    }

    // Метод для конвертації довжини з футів в метри
    double convertFeetToMeters(double feet) {
        return feet * feetToMeters;
    }

    // Метод для конвертації довжини з дюймів в сантиметри
    double convertInchesToCentimeters(double inches) {
        return inches * inchesToCentimeters;
    }
};

// Функція для запису результату в файл (в коді використано функції роботи з файлами, для того, щоб записати у файл)
void writeToTextFile(double bannerSize, const string& resultFileName) {
    ofstream outFile(resultFileName);  // Відкриття файлу для запису

    // Перевірка, чи файл успішно відкрито
    if (outFile.is_open()) {
        outFile << "Banner Size: " << bannerSize << " meters" << endl;
        cout << "Результат записано в файл '" << resultFileName << "'." << endl;

        outFile.close();  // Закриття файлу
    } else {
        cerr << "Не вдалося відкрити файл для запису." << endl;
    }
}

// Функція для виведення символів з лівого краю до правого з використанням циклу for
void printLeftToRightWhile(const string& surname, int start, int end) {
    cout << "при написанні прізвища з лівого краю поля —>  до правого: ";
    int i = start;
    for (int i = start; i < end; i++) {
        cout << surname[i % surname.length()] << " ";
    }
    cout << endl;
}

// Функція для виведення символів з правого краю до лівого з використанням циклу while
void printRightToLeftWhile(const string& surname, int start, int end) {
    cout << "при написанні прізвища з правого краю поля <—  до лівого: ";
    int i = end - 1;
    while (i >= start) {
        cout << surname[i % surname.length()] << " ";
        i--;
    }
    cout << endl;
}

// Функція для зчитування та виведення інформації з файлу
void readAndPrintFromFile(const string& fileName) {
    ifstream inFile(fileName);  // Відкриття файлу для читання

    // Перевірка, чи файл успішно відкрито
    if (inFile.is_open()) {
        string line;

        // Зчитування та виведення кожного рядка з файлу
        while (getline(inFile, line)) {
            cout << line << endl;
        }

        inFile.close();  // Закриття файлу
    } else {
        cerr << "Не вдалося відкрити файл для читання." << endl;
    }
}

int main() {
    // Задане прізвище
    string surname = "Khailov";  

    // Розмір букви і проміжку між символами (використана дійсна змінна)
    float letterWidth = 0.8;  // метри
    
    // Кількість голосних букв у прізвищі (використана цілочисельна змінна)
    int vowelsCount = 0;

    // Підрахунок кількості голосних букв у прізвищі (використано foreach)
    for (char letter : surname) {
        if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' ||
            tolower(letter) == 'o' || tolower(letter) == 'u') {
            vowelsCount++;
        }
    }

    // Розмір банера (використана дійсна змінна)
    double bannerSize = vowelsCount * letterWidth;

    // Виведення результату
    cout << "Banner Size: " << bannerSize << " meters" << endl;

    // Запис результату в файл
    writeToTextFile(bannerSize, "result.txt");

    // Визначення символів на центральних трьох метрах (використано cтруктуру)
    // 1 Ярд = 3 фути. 1 Фут = 12 дюймів. 1 Дюйм = 2.54 см.
    LengthConverter converter;

    double fieldLengthInYards = 100.0;  // Довжина поля в ярдах
    double fieldLengthInMeters = converter.convertYardsToMeters(fieldLengthInYards);  // Переведення в метри

    int centralMeters = 3;  // Кількість центральних метрів

    // Визначення позицій символів для лівого написання (використано цілочисельні змінні та одновимірний масив)
    int startLeft = (fieldLengthInYards * 3) / 2 - centralMeters;
    int endLeft = startLeft + centralMeters;

    // Визначення позицій символів для правого написання (використано цілочисельні змінні та одновимірний масив)
    int startRight = (fieldLengthInYards * 3) / 2;
    int endRight = startRight + centralMeters;

    // Виведення результату (в коді використано оператори виведення та введення даних)
    printLeftToRightWhile(surname, startLeft, endLeft);
    printRightToLeftWhile(surname, startRight, endRight);

    // Зчитування та виведення інформації з файлу ( коді використано функції роботи з файлами, для того, щоб зчитати з файлу)
    readAndPrintFromFile("result.txt");

    return 0;
}
