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
    ofstream file(name, ios::out | ios::trunc);

    if (!file.is_open())
    {
        cerr << "Error: Unable to open file " << name << endl;
        return Failure;
    }

    file << content;

    if (file.fail())
    {
        cerr << "Error: Failed to write content to file " << name << endl;
        file.close();
        return Failure;
    }

    file.close();

    if (file.fail())
    {
        cerr << "Error: Failed to close file " << name << endl;
        return Failure;
    }

    return Success;
}

int main()
{
    const char *filename = "example.txt";
    const char *content = "This file has been just created!";

    FileOpResult result = write_to_file(filename, content);

    if (result == Success)
    {
        cout << "File operation succeeded." << endl;
    }
    else
    {
        cerr << "File operation failed." << endl;
    }

    return 0;
}
