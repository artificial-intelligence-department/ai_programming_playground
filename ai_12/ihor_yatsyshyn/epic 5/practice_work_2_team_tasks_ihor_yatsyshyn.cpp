#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to);

int main() 
{
    char *name_to, *name_from;

    cout << "Enter file name that should be coppied: ";
    cin >> name_from;

    cout << "Enter file name that should be destination: ";
    cin >> name_to;

    FileOpResult result = copy_file(name_from, name_to);

    if (result == FileOpResult::Success) 
    {
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }

    return 0;
}

FileOpResult copy_file(const char *file_from, const char *file_to)
{
    ifstream file1(file_from);

    if (!file1.is_open()) 
    {
        return FileOpResult::Failure;
    }

    ofstream file2(file_to);

    if (!file2.is_open()) 
    {
        file1.close();

        return FileOpResult::Failure;
    }

    file2 << file1.rdbuf();

    if (file2.fail())
    {
        file1.close();
        file2.close();

        return FileOpResult::Failure;
    }
    

    return FileOpResult::Success;
}