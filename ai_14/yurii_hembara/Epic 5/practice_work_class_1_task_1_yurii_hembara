#include <iostream>
#include <fstream>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const std::string& content) {
    // Відкриття файлу для запису
    std::ofstream outFile(name);

    if (!outFile.is_open()) {
        // Помилка відкриття файлу
        std::cerr << "Error opening file: " << name << std::endl;
        return FileOpResult::Failure;
    }

    // Запис стрічки content у файл
    outFile << content;

    // Перевірка статусу запису та закриття файлу
    if (outFile.fail()) {
        std::cerr << "Error writing to file: " << name << std::endl;
        outFile.close();
        return FileOpResult::Failure;
    }

    // Успішне закриття файлу
    outFile.close();
    return FileOpResult::Success;
}

int main() {
    // Задання ім'я файлу та вміст стрічки
    const char *fileName = "example.txt";
    std::string content;

    // Введення стрічки вмісту з консолі
    std::cout << "Enter content to write to file: ";
    std::getline(std::cin, content);

    // Виклик функції запису в файл
    FileOpResult result = write_to_file(fileName, content);

    // Повідомлення про результат операції
    if (result == FileOpResult::Success) {
        std::cout << "File write successful." << std::endl;
    } else {
        std::cout << "File write failed." << std::endl;
    }

    return 0;
}
