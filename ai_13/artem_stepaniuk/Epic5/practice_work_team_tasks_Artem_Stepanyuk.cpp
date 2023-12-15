#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    if (!name || !content) {
        return FileOpResult::Failure;
    }

    std::ofstream file(name, std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Помилка відкривая файл: " << name << std::endl;
        return FileOpResult::Failure;
    }

    file << content;

    if (file.fail()) {
        std::cerr << "Помилка запису у файл: " << name << std::endl;
        file.close();
        return FileOpResult::Failure;
    }

    file.close();

    return FileOpResult::Success;
}

int main() {
    const char fileName[] = "primertexta.txt";
    const char content[] = "Hello, World!";

    if (write_to_file(fileName, content) == FileOpResult::Success) {
        std::cout << "Файл успішно записано.\n";
    } else {
        std::cout << "Не вдалося записати у файл..\n";
    }

    return 0;
}