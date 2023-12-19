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

// Функція для запису результату в файл
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

int main() {
    // Задане прізвище
    string surname = "Khailov";  // Замініть "YourSurname" на своє прізвище

    // Розмір букви і проміжку між символами (використана дійсна з подвійною точністю змінна)
    double letterWidth = 0.8;  // метри
    
    // Кількість голосних букв у прізвищі (використана цілочисельна змінна)
    int vowelsCount = 0;

    // Підрахунок кількості голосних букв у прізвищі
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

    // Визначення символів на центральних трьох метрах (використано умовний оператор та математичні операції)

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

    // Виведення результату
    cout << "при написанні прізвища з лівого краю поля —>  до правого: ";
    for (int i = startLeft; i < endLeft; i++) {
        cout << surname[i % surname.length()] << " ";
    }
    cout << endl;

    cout << "при написанні прізвища з правого краю поля <—  до лівого: ";
    for (int i = endRight - 1; i >= startRight; i--) {
        cout << surname[i % surname.length()] << " ";
    }
    cout << endl;

    return 0;
}
