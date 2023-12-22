#include <iostream>
#include <fstream>
#include <string>

bool write_to_file(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Помилка відкриття файлу для запису.\n";
        return false;
    }

    std::string input_text;
    std::cout << "Введіть текст для запису в файл " << filename << ":\n";
    std::getline(std::cin >> std::ws, input_text);

    file << input_text;
    file.close();

    std::cout << "Текст успішно записано у файл " << filename << ".\n";
    return true;
}

bool copy_file(const std::string& source_filename, const std::string& destination_filename) {
    std::ifstream source_file(source_filename);
    if (!source_file.is_open()) {
        std::cout << "Помилка відкриття файлу для читання.\n";
        return false;
    }

    std::ofstream destination_file(destination_filename);
    if (!destination_file.is_open()) {
        std::cout << "Помилка відкриття/створення файлу для запису.\n";
        return false;
    }

    destination_file << source_file.rdbuf();

    source_file.close();
    destination_file.close();

    std::cout << "Вміст файлу " << source_filename << " успішно скопійовано в файл " << destination_filename << ".\n";
    return true;
}

int main() {
    const std::string filename = "C:\\Users\\MAHINA\\Desktop\\MyE5\\example.txt";
    std::string copy_destination_filename;

    if (write_to_file(filename)) {
        std::cout << "Введіть назву файлу, куди скопіювати вміст файлу " << filename << ":\n";
        std::cin >> copy_destination_filename;

        if (copy_file(filename, copy_destination_filename)) {
        } else {
            std::cout << "Не вдалося скопіювати вміст файлу.\n";
        }
    } else {
        std::cout << "Не вдалося записати у файл " << filename << ".\n";
    }

    return 0;
}