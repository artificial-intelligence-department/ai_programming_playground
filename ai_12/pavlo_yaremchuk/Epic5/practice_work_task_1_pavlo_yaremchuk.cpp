#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult {Success, Failure};
FileOpResult write_to_file(const char *name, const char *content)
{
    ofstream file(name);

    if (!file.is_open())
    {
        cout << "Помилка відкриття файлу" << endl;
        return Failure;
    }

    file << content;
    file.close();
    cout << "Файл успішно створений i заповнений" << endl;
    return Success;
}

FileOpResult copy_file(const char *file_from, const char *file_to)
{
    ifstream file1(file_from);
    ofstream file2(file_to);

    if (!file1.is_open())
    {
        cout << "Помилка відкриття файлу" << endl;
        return Failure;
    }

    if (!file2.is_open())
    {
        cout << "Помилка відкриття файлу" << endl;
        return Failure;
    }

    string text;
    while (getline(file1, text))
    {
        file2 << text;
    }
    file1.close();
    file2.close();

    cout << "Вміст файлу 1 успішно копійовано y файл 2" << endl;
    return Failure;
}

int main()
{
    string name, content, file_to, file_from;
    cout << "Введіть назву файлу: ";
    cin >> name;
    cout << "Введіть вміст файлу: ";
    cin >> content;
    cout << "Введіть назву файлу, в який потрібно копіювати: ";
    cin >> file_to;
    file_from = name;

    FileOpResult wrtfile = write_to_file(name.c_str(), content.c_str());

    FileOpResult cpfile = copy_file(file_from.c_str(), file_to.c_str());

    return 0;
}