#include <iostream>
#include <fstream>
#include <sstream>

enum FileOpResult { Success, Failure};

FileOpResult write_to_file(const char *name, const char *content)
{
    std::ofstream outputFile(name);
    // Перевірка чи файл  вдалося відкрити
    if (!outputFile.is_open()) 
    {
        std::cout << "Unable to open" << std::endl;
        return Failure;
    }

    // cтворює об'єкт для читання із стрічки content у форматі потоку вводу
    std::istringstream contentStream(content); 
    std::string line;

    while (std::getline(contentStream, line)) 
    {
        if (!line.empty()) 
        {
            outputFile << line << std::endl;
        }
    }
    outputFile.close();
    return Success;
}

int main()
{
    std::string name;
    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::string content;
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, content);

    const char *nameCStr = name.c_str();
    const char *contentCStr = content.c_str();

    FileOpResult result = write_to_file(nameCStr, contentCStr);

    if (result == Success) 
    {
        std::cout << "File was successful" << std::endl;
    } 
    else
    {
        std::cout << "File was failed" << std::endl;
    }

}