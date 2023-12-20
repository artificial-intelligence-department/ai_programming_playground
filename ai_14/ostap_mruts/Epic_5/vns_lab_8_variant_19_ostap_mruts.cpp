#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string file_path = "C:\\Users\\MAHINA\\Desktop\\MyE5\\t.txt";

    std::fstream file(file_path, std::ios::in | std::ios::out);
    
    if (!file.is_open()) {
        std::cout << "Не вдалося відкрити файл!" << std::endl;
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    std::string country, profit;

    std::cout << "Країна: ";
    std::getline(std::cin, country);

    std::cout << "Прибуток: ";
    std::getline(std::cin, profit);

    lines[lines.size() - 2] = country;
    lines.back() = profit;

    file.clear();
    file.seekp(0, std::ios::beg);

    for (const auto &l : lines) {
        file << l << std::endl;
    }

    std::cout << "Зміни внесено" << std::endl;

    file.close();

    return 0;
}
