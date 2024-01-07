#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <algorithm>

using namespace std;

enum FileOpResult
{
    Success,
    Failure,
    InvalidArguments
};

string convert(FileOpResult value)
{
    switch (value)
    {
    case Success:
        return "Success";
    case Failure:
        return "Failure";
    case InvalidArguments:
        return "InvalidArguments";
    }
}

FileOpResult write_to_file(char *name, const char *content)
{
    if (name == NULL)
    {
        return InvalidArguments;
    }

    ofstream fileWeWriteInfoTo(name);
    if (!fileWeWriteInfoTo)
    {
        return Failure;
    }
    fileWeWriteInfoTo << content;
    fileWeWriteInfoTo.close();
    return Success;
}

FileOpResult copy_file(char *file_from, char *file_to)
{
    if (file_from == NULL || file_to == NULL)
    {
        return InvalidArguments;
    }
    ifstream fileWeCopyFrom(file_from);
    if (!fileWeCopyFrom)
    {
        return Failure;
    }
    ofstream output(file_to);
    if (!output)
    {
        return Failure;
    }
    string tempPlace;
    while (getline(fileWeCopyFrom, tempPlace))
    {
        output << tempPlace << "\n";
    }
    return Success;
}

int main()
{
    char fileName1[] = "1.txt";
    char fileName2[] = "2.txt";
    char fileName3[] = "0";
    char *fileName4 = NULL;
    cout << "Which string do you want to write into file?" << endl;
    string answer;
    getline(cin, answer);
    auto result1 = write_to_file(fileName1, answer.c_str());
    cout << "The result of operation is: " << convert(result1) << endl;
    auto result2 = copy_file(fileName1, fileName2);
    cout << "Result of copiyng 1 to 2: " << convert(result2) << endl;
    auto result3 = copy_file(fileName3, fileName2);
    cout << "Result of copiyng 3 to 2: " << convert(result3) << endl;
    auto result4 = copy_file(fileName4, fileName2);
    cout << "Result of copiyng 4 to 2: " << convert(result4) << endl;
}
