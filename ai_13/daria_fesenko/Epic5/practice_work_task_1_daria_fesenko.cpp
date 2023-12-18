#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const std::string &name, const std::string &content) {
    std::ofstream file(name); 

    if (!file.is_open()) {
        std::cerr << "Помилка відкриття файлу для запису!" << std::endl;
        return FileOpResult::Failure;
    }
    file << content;
    file.close();

    return FileOpResult::Success;
}

int main() {
    std::string filename, content;
    std::cout << "Введіть ім'я файлу: ";
    std::getline(std::cin, filename);

    std::cout << "Введіть вміст для запису в файл: ";
    std::getline(std::cin, content);


    FileOpResult result = write_to_file(filename, content);

    if (result == FileOpResult::Success) {
        std::cout << "Файл успішно створено та записано!" << std::endl;
    } else {
        std::cout << "Сталася помилка при роботі з файлом." << std::endl;
    }

    return 0;
}
