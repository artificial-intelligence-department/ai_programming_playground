#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Оголошення перелічення для результату операції з файлом
enum class FileOpResult
{
    Success,
    Failure
};

// Функція для запису вмісту в файл
FileOpResult writeToFile(const string &name, const string &content)
{
    // Використання конструктора для відразу відкриття файлу
    ofstream file(name);

    // Перевірка, чи вдалося відкрити файл
    if (!file.is_open())
    {
        return FileOpResult::Failure; // Повернення Failure при невдалому відкритті
    }

    // Запис вмісту в файл
    file << content;

    // Перевірка, чи вдалося записати в файл
    if (!file)
    {
        return FileOpResult::Failure; // Повернення Failure при помилці запису
    }

    // Файл автоматично закриється при знищенні об'єкта file

    return FileOpResult::Success; // Повернення Success при успішному відкритті та записі
}

int main()
{
    string filename = "test.txt";
    string content = "Це приклад вмісту файлу.";

    FileOpResult result = writeToFile(filename, content);

    // Використання перелічення для зрозумілості коду
    if (result == FileOpResult::Success)
    {
        cout << "Success\n";
    }
    else
    {
        cout << "Error" << endl;; 
    }

    return 0;
}
