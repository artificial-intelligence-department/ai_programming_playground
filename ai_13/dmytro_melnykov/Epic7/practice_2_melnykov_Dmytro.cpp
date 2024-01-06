#include <iostream>
#include <fstream>
#include <cstring>

const int MAX_NAME_LENGTH = 50;
const int MAX_FIELD_LENGTH = 120;

struct Banner {
    char* text;
    int length;
};

void printBanner(const Banner& banner) {
    // Вивід банера по центру поля
    int padding = (banner.length - std::strlen(banner.text)) / 2;
    std::cout << std::string(padding, ' ') << banner.text << std::endl;
}

int countVowels(const char* name) {
    // Підрахунок кількості голосних букв у прізвищі
    int count = 0;
    while (*name != '\0') {
        char lowercase = tolower(*name);
        if (lowercase == 'a' || lowercase == 'e' || lowercase == 'i' || lowercase == 'o' || lowercase == 'u') {
            count++;
        }
        name++;
    }
    return count;
}

Banner generateBanner(const char* name) {
    // Генерація банера
    float letterWidth = countVowels(name) * 0.8;
    int minBannerLength = static_cast<int>(letterWidth) + 10;

    if (minBannerLength > MAX_FIELD_LENGTH) {
        std::cout << "Помилка: Надто коротке поле для розміщення банера." << std::endl;
        return {nullptr, 0};
    }

    Banner banner;
    banner.text = new char[MAX_NAME_LENGTH + 1];
    std::strcpy(banner.text, name);
    banner.length = MAX_FIELD_LENGTH;

    return banner;
}

void deleteBanner(Banner& banner) {
    delete[] banner.text;
    banner.text = nullptr;
    banner.length = 0;
}

int main() {
    std::cout << "Введіть ваше прізвище: ";
    
    char lastName[MAX_NAME_LENGTH];
    std::cin.getline(lastName, MAX_NAME_LENGTH);

    Banner generatedBanner = generateBanner(lastName);

    // Варіант 1: Виведення з лівого краю до правого
    std::cout << "1) З лівого краю до правого:" << std::endl;
    printBanner(generatedBanner);

    // Варіант 2: Виведення з правого краю до лівого
    std::cout << "2) З правого краю до лівого:" << std::endl;
    int padding = generatedBanner.length - std::strlen(generatedBanner.text);
    std::cout << std::string(padding, ' ') << generatedBanner.text << std::endl;

    // Запис банера у файл
    std::ofstream outFile("banner.txt");
    outFile << generatedBanner.text;
    outFile.close();

    // Зчитування банера з файлу
    Banner readBanner;
    readBanner.text = new char[MAX_NAME_LENGTH + 1];
    std::ifstream inFile("banner.txt");
    inFile.getline(readBanner.text, MAX_NAME_LENGTH);
    readBanner.length = MAX_FIELD_LENGTH;
    std::cout << "Банер, зчитаний з файлу: " << readBanner.text << std::endl;

    // Звільнення пам'яті
    deleteBanner(generatedBanner);
    deleteBanner(readBanner);

    return 0;
}
