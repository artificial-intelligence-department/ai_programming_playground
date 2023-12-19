#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult 
{
    Success,
    Failure
};

FileOpResult write_to_file(const char *name, const char *content)
{
    if (name == nullptr || content == nullptr)
        return Failure;

    ofstream file(name);

    if (!file.is_open())
        return Failure;

    file << content;

    if (file.fail())
    {
        file.close();
        return Failure;
    }

    file.close();

    return Success;
}

int main()
{
    const char *fileName = "example.txt";
    const char *content = "Hello, world!";

    FileOpResult result = write_to_file(fileName, content);

    if (result == Success)
        cout << "Запис до файлу пройшов успішно." << endl;
    else
        cerr << "Помилка при записі до файлу." << endl;

    return 0;
}
