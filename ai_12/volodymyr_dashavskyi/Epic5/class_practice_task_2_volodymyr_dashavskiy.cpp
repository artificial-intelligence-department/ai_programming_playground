#include <iostream>
#include <fstream>
#include <sstream>

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult create_and_fill_file(const char *file_path, const std::string &content)
{
    std::ofstream file(file_path);
    if (!file.is_open())
    {
        std::cerr << "Error creating file: " << file_path << std::endl;
        return Failure;
    }
    file << content;
    file.close();
    return Success;
}

FileOpResult copy_file(const char *file_from, const char *file_to)
{
    // Зміст для запису в файл file_from
    std::string fileFromContent = "This is the content of file_from.";

    // Створення та заповнення вхідного файлу (file_from)
    FileOpResult createSourceResult = create_and_fill_file(file_from, fileFromContent);
    if (createSourceResult == Failure)
    {
        return Failure;
    }

    // Створення вихідного файлу (file_to), якщо він не існує
    FileOpResult createDestinationResult = create_and_fill_file(file_to, "");
    if (createDestinationResult == Failure)
    {
        return Failure;
    }

    // Відкриття вхідного файлу (file_from) для читання
    std::ifstream source(file_from, std::ios::binary);
    if (!source.is_open())
    {
        std::cerr << "Error opening source file: " << file_from << std::endl;
        return Failure;
    }

    // Відкриття вихідного файлу (file_to) для запису
    std::ofstream destination(file_to, std::ios::binary);
    if (!destination.is_open())
    {
        std::cerr << "Error opening destination file: " << file_to << std::endl;
        source.close();
        return Failure;
    }

    // Копіювання даних з вхідного файлу (file_from) в вихідний (file_to)
    destination << source.rdbuf();

    // Перевірка на помилки читання або запису
    if (destination.fail())
    {
        std::cerr << "Error copying data from " << file_from << " to " << file_to << std::endl;
        source.close();
        destination.close();
        return Failure;
    }

    // Закриття файлів
    source.close();
    destination.close();

    return Success;
}

int main()
{
    const char *file_from = "file_from.txt";
    const char *file_to = "file_to.txt";

    FileOpResult result = copy_file(file_from, file_to);

    if (result == Success)
    {
        std::cout << "Files created and copied successfully!" << std::endl;
    }
    else
    {
        std::cerr << "File creation or copy failed!" << std::endl;
    }

    return 0;
}
