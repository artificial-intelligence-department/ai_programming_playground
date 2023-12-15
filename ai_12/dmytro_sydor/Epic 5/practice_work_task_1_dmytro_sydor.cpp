#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult write_to_file(string name, string content)
{
    ofstream file(name);

    if (!file.is_open())
    {
        return FileOpResult::Failure;
    }

    file << content << endl;

    if (file.fail())
    {
        return FileOpResult::Failure;
    }

    file.close();
    return FileOpResult::Success;
}

int main()
{
    string fname = "task.txt";
    string content;
    cout << "Enter a content you want to add to ur file: " << endl;
    getline(cin, content);

    FileOpResult result = write_to_file(fname, content);
    if (result == FileOpResult::Success)
    {
        cout << "Succesful! " << endl;
    }
    else if (result == FileOpResult::Failure)
    {
        cout << "Failure( " << endl;
    }
    return 0;
}
