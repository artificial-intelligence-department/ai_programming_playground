#include <iostream>
#include <fstream>
#include <sstream>


int main() 
{
    // Відкриття файлу F1 для считання
    std::ifstream f1("F1.txt");
    
    // Перевірка чи файл F1 вдалося відкрити
    if (!f1.is_open()) 
    {
        std::cout << "Unable to open F1.txt" << std::endl;
        return 1; // Помилка відкриття файлу
    }

    // Відкриття файлу F2 для запису
    std::ofstream f2("F2.txt");

    // Перевірка чи файл F2 вдалося відкрити
    if (!f2.is_open())
    {
        std::cout << "Unable to open F2.txt" << std::endl;
        return 1; // Помилка відкриття файлу
    }

    std::string line;

    // Зчитування рядків з F1
    while (std::getline(f1, line)) 
    {
        // Перевірка, чи рядок починається з букви "A"
        if (!line.empty() && line[0] == 'A') 
        {
            // Запис рядка у файл F2
            f2 << line << std::endl;
        }
    }

    // Закриття файлів
    f1.close();
    f2.close();

    // Відкриття файлу для підрахунку слів
    std::ifstream f2Count("F2.txt");

    // Перевірка, чи файл F2 вдалося відкрити
    if (!f2Count.is_open()) 
    {
        std::cout << "Unable to open F2.txt for word count" << std::endl;
        return 1; // Помилка відкриття файлу
    }

    int wordCount = 0;
    std::string word;

    // Підрахунок слів у файлі F2
    while (f2Count >> word) 
    {
        wordCount++;
    }

    // Виведення кількості слів
    std::cout << "Number of words in F2: " << wordCount << std::endl;

    f2Count.close();

    return 0;
}
