#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content);

int main() 
{
    char *name, *content;

    cout << "Enter file name (with extension): ";
    cin >> name;

    cout << "Enter content that should be written to file: ";
    cin >> content;

    FileOpResult result = write_to_file(name, content);

    if (result == FileOpResult::Success) 
    {
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }

    return 0;
}

FileOpResult write_to_file(const char* name, const char* content) 
{
    ofstream file(name);

    if (!file.is_open()) 
    {
        cout << "Failure" << endl;
    }

    file << content;

    if (file.fail()) 
    {
        cout << "Failure" << endl;
        file.close();
    }

    file.close();

    return FileOpResult::Success;
}