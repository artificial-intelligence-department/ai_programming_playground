#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult copy_file(const char *file_from, const char *file_to)
{

    if (file_from == nullptr || file_to == nullptr)
        return Failure;

    ifstream source(file_from, ios::binary);

    if (!source.is_open())
        return Failure;

    ofstream destination(file_to, ios::binary);

    if (!destination.is_open())
    {
        source.close();
        return Failure;
    }

    destination << source.rdbuf();

    if (destination.fail())
    {
        source.close();
        destination.close();
        return Failure;
    }

    source.close();
    destination.close();
    return Success;
}

int main()
{
    const char *sourceFile = "source.txt";
    const char *destinationFile = "destination.txt";

    FileOpResult result = copy_file(sourceFile, destinationFile);

    if (result == Success)
        cout << "Копіювання файлу пройшло успішно." << endl;
    else
        cerr << "Помилка при копіюванні файлу." << endl;

    return 0;
}