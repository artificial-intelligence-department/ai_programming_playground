#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult { Success, Failure };

class FileWriter {
public:
    FileWriter(const std::string &fileName) : fileName(fileName) {}

    FileOpResult writeToCustomFile(const std::string &content) {
        std::ofstream customFile(fileName);

        if (!customFile.is_open()) {
            std::cerr << "Помилка відкриття файлу " << fileName << std::endl;
            return FileOpResult::Failure;
        }

        customFile << content;

        if (!customFile.good()) {
            std::cerr << "Помилка запису в файл " << fileName << std::endl;
            customFile.close();
            return FileOpResult::Failure;
        }

        customFile.close();

        return FileOpResult::Success;
    }

private:
    std::string fileName;
};

int main() {
    std::string customFileName = "custom_example.txt";
    std::string fileContent;

    std::cout << "Введіть вміст для запису в файл: ";
    std::getline(std::cin, fileContent);

    FileWriter fileWriter(customFileName);
    FileOpResult result = fileWriter.writeToCustomFile(fileContent);

    if (result == FileOpResult::Success) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << "Failure" << std::endl;
    }

    return 0;
}