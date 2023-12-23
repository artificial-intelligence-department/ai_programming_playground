#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult write_to_file(const char *name, char *text)
{
    ofstream outputFile(name);

    if (!outputFile.is_open())
    {
        cerr << "Error. Can't open file: " << name << endl;
        return Failure;
    }

    outputFile << text;
    outputFile.close();
    return Success;
}

int main()
{
    char text[1024];
    const char *name = "text.txt";
    cout << "Type text for file:" << std::endl;
    cin.getline(text, sizeof(text));
    FileOpResult result = write_to_file(name, text);
    if (result == Success)
    {
        cout << "Success, file has done.";
    }
    else
    {
        cout << "Apologise, can't do this .";
    }

    return 0;
}