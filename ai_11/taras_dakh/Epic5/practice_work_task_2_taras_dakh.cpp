#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult {
    Success,
    Failure
};

FileOpResult writeToCustomFile(const std::string &fileName, const std::string &content) {
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

FileOpResult copy_file(string file_from, string file_to) {
    ofstream file_out(file_from);
    if (!file_out.is_open()) {
        return FileOpResult::Failure;
    }

    string text;

    cout << "Write a text you want to copy to another file: " << endl;
    getline(cin, text);
    file_out << text << endl;
    file_out.close();

    ifstream file_in(file_from);
    ofstream file2(file_to);

    if (!file_in.is_open()) {
        cerr << "Error opening source file for reading: " << file_from << endl;
        return FileOpResult::Failure;
    }
    if (!file2.is_open()) {
        cerr << "Error opening destination file: " << file_to << endl;
        file_in.close();
        return FileOpResult::Failure;
    }

    string textToCopy;

    while (getline(file_in, textToCopy)) {
        file2 << textToCopy << endl;
    }

    file_in.close();
    file2.close();

    return FileOpResult::Success;
}

int main() {
    // Викликаємо copy_file з іменами файлів file_from.txt та file_to.txt
    FileOpResult result = copy_file("file_from.txt", "file_to.txt");

    if (result == FileOpResult::Success) {
        cout << "Copy operation: Success" << endl;
    } else {
        cout << "Copy operation: Failure" << endl;
    }

    // Викликаємо writeToCustomFile з іменем файлу custom_example.txt
    std::string customFileName = "custom_example.txt";
    std::string fileContent;

    std::cout << "Введіть вміст для запису в файл: ";
    std::getline(std::cin, fileContent);

    FileOpResult customResult = writeToCustomFile(customFileName, fileContent);

    if (customResult == FileOpResult::Success) {
        std::cout << "Custom write operation: Success" << std::endl;
    } else {
        std::cout << "Custom write operation: Failure" << std::endl;
    }

    return 0;
}
