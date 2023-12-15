#include <iostream>
#include <fstream>
#include <sstream>

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to)
{
    std::ifstream outputFile(file_from);
    if (!outputFile.is_open()) 
    {
        std::cout << "Unable to open" << std::endl;
        return Failure;
    }

    std::ofstream inputFile(file_to);
    if (!inputFile.is_open())
    {
        std::cout << "Unable to open" << std::endl;
        return Failure; 
    }

    std::string line;

    while (std::getline(outputFile, line)) 
    {
        // перевірка чи лінія не пуста
        if (!line.empty()) 
        {
            // Запис в лінії з файлу
            inputFile << line << std::endl;
        }
    }
    return Success;
}

int main()
{
    std::string file_from;
    std::cout << "Enter name file_from: ";
    std::getline(std::cin, file_from);

    std::string file_to;
    std::cout << "Enter name file_to: ";
    std::getline(std::cin, file_to);

    const char *file_fromCStr = file_from.c_str();
    const char *file_toCStr = file_to.c_str();

    FileOpResult result = copy_file(file_fromCStr, file_toCStr);

    if (result == Success)
    {
        std::cout << "File copy was successful" << std::endl;
    }
    else
    {
        std::cout << "File copy failed" << std::endl;
    }

    return 0;
}
