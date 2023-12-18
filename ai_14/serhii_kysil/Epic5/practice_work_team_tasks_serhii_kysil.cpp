#include <iostream>
#include <fstream>
#include <string>
enum FileOpResult { Success, Failure };
FileOpResult write_to_file(const char *name, const char *content) {
    std::ofstream file(name, std::ios::out);
    if (!file.is_open()) {
        return Failure;
    }
    file << content;
    file.close();
    return Success;
}
FileOpResult copy_file(const char *file_from, const char *file_to) {
    std::ifstream source(file_from, std::ios::binary);
    std::ofstream destination(file_to, std::ios::binary);
    if (!source.is_open() || !destination.is_open()) {
        return Failure;
    }
    destination << source.rdbuf();
    if (!destination) {
        return Failure;
    }
    return Success;
}
int main() {
    const char *file_name = "file_from.txt";
    const char *file_content = "Hello, and wellcome to the LosPolos Germanos family, my name is Gustavo but you can call me Gus!";
    const char *file_copy_from = "file_from.txt";
    const char *file_copy_to = "file_to.txt";
    // Завдання №1 - Запис у файл
    FileOpResult write_result = write_to_file(file_name, file_content);
    if (write_result == Success) {
        std::cout << "Write to file: Success" << std::endl;
    } else {
        std::cout << "Write to file: Failure" << std::endl;
    }
    // Завдання №2 - Копіювання файлу
    FileOpResult copy_result = copy_file(file_copy_from, file_copy_to);
    if (copy_result == Success) {
        std::cout << "Copy file: Success" << std::endl;
    } else {
        std::cout << "Copy file: Failure" << std::endl;
    }
    return 0;
}
