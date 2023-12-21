#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult
{
    Success, Failure
};

FileOpResult write_to_file (const char *name, const char *content)
{
    ofstream file(name);

    if (!file.is_open())
    {
        return Failure;
    }

    file << content;

    if (!file)
    {
        file.close();
        return Failure;
    }

    file.close();

    return Success;
}

FileOpResult copy_file (const char *file_from, const char *file_to)
{
    ifstream source (file_from, ios::binary);
    ofstream end (file_to, ios::binary);

    if (!source. is_open() || !end.is_open())
    {
        return Failure;
    }

    end << source.rdbuf();

    if (!end)
    {
        source.close();
        end.close();
        return Failure;
    }

    source.close();
    end.close();

    return Success;
}

int main()
{
    char file_name [40], file_content [500];
    char file_from [500], file_to [500]; 


    cout << "-----Ім'я файлу повинно мати 40 символів!-----\n";
    cout << "-----Текст повиннен містити 500 символів!-----\n\n";

    cout << "Введіть назву файла - ";
    cin.getline (file_name, sizeof(file_name));

    cout << "Введіть текст, для збереження в файлі - ";
    cin.getline (file_content, sizeof(file_content));

    FileOpResult result_1 = write_to_file (file_name, file_content);

    cout << endl << (result_1 == Success ? "Все Збережено" : "Помилка збереження");

    cout << endl << endl << "-----Процес копіювання файлу!-----\n" << endl;

    cout << "Введіть шлях до файлу який потрібно скопіювати - ";
    cin.getline (file_from, sizeof (file_from));

    cout << "Введіть шлях до нового файлу - ";
    cin.getline (file_to, sizeof (file_to));

    FileOpResult result_2 = copy_file (file_from, file_to);

    cout << (result_2 == Success ? "Скопійовано успішно" : "Помилка копіювання");

    return 0;
}