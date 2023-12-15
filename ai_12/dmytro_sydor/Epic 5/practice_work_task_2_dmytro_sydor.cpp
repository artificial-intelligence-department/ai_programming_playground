#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult copy_file(string file_from, string file_to)
{
    ofstream file_out(file_from);
    if (!file_out.is_open())
    {
        return FileOpResult::Failure;
    }

    string text;

    cout << "Write a text you want to copy to another file: " << endl;
    getline(cin, text);
    file_out << text << endl;
    file_out.close();

    ifstream file_in(file_from);
    ofstream file2(file_to);

    if (!file_in.is_open())
    {
        cerr << "Error opening source file for reading: " << file_from << endl;
        return FileOpResult::Failure;
    }
    if (!file2.is_open())
    {
        cerr << "Error opening destination file: " << file_to << endl;
        file_in.close();
        return FileOpResult::Failure;
    }

    string textToCopy;

    while (getline(file_in, textToCopy))
    {
        file2 << textToCopy << endl;
    }

    file_in.close();
    file2.close();

    return FileOpResult::Success;
}

int main()
{
    string filename1 = "file_from.txt";
    string filename2 = "file_to.txt";

    FileOpResult result = copy_file(filename1, filename2);

    if (result == FileOpResult::Success)
    {
        cout << "Successfully." << endl;
    }
    else
    {
        cout << "Failed." << endl;
    }

    return 0;
}
