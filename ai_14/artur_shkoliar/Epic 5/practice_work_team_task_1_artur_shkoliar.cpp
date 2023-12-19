#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) 
{
    ofstream file(name, ios::out);

    if (!file.is_open()) 
    {
        cerr << "Помилка у відкриванні файлу " << name << endl;
        return FileOpResult::Failure;
    }

    file << content;

    if (file.fail()) 
    {
        cerr << "Помилка запису у файл " << name << endl;
        file.close();
        return FileOpResult::Failure;
    }

    file.close();

    if (file.fail()) 
    {
        cerr << "Помилка закриття файлу " << name << endl;
        return FileOpResult::Failure;
    }

    return FileOpResult::Success;
}

int main() 
{
    const char *filename = "testing.txt";
    const char *content = "I love C++";

    FileOpResult result = write_to_file(filename, content);

    if (result == FileOpResult::Success) 
    {
        cout << "Файл успішно записаний " << filename << endl;
    } 
    else 
    {
        cerr << "Помилка у написанні " << filename << endl;
    }

    return 0;
}
