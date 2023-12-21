#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult {Success, Failure};

FileOpResult write_to_file(const char *fileName, const char *fileContent)
{
    cout << endl;

    ofstream file_output(fileName);
    if(!file_output.is_open())
    {
        cout << "Error! (File couldn't be open)";
        return Failure;
    }

    file_output << fileContent;

    if(file_output.fail())
    {
        cout << "Error! (Content couldn't be written to file)";
        file_output.close();
        return Failure;
    }

    file_output.close();

    return Success;
}


FileOpResult copy_file(const char *file_from, const char *file_to)
{
    cout << endl;
    ifstream fileToCopy(file_from);
    if(!fileToCopy.is_open())
    {
        cout << "Error! (File couldn't be open)";
        return Failure;
    }

    ofstream fileInWhichCopy(file_to);
    if(!fileInWhichCopy.is_open())
    {
        cout << "Error! (File couldn't be opened)";
        fileInWhichCopy.close();
        return Failure;
    }

    fileInWhichCopy << fileToCopy.rdbuf();

    if(fileToCopy.fail() || fileInWhichCopy.fail())
    {
        cout << "Error! (Coping isn't done)";
        fileToCopy.close();
        fileInWhichCopy.close();
        return Failure;
    }

    fileToCopy.close();
    fileInWhichCopy.close();

    return Success;
}


int main()
{
    string fileNameToCopy, fileNameInWhichCopy, FILEcontent;

    cout << "Enter the name of file you want to copy here ->  ";
    cin >> fileNameToCopy;

    cout << "Enter information you want to write to the file here -> ";
    cin.ignore();
    getline(cin, FILEcontent);

    FileOpResult resultOf1Operation = write_to_file(fileNameToCopy.c_str(), FILEcontent.c_str());
    if(resultOf1Operation == Success)
    {
        cout << "Success!";
    }
    else
    {
        cout << endl;
        cout << "Failure!";
        return 1;
    }

    cout << endl;
    cout << "Enter the name of file you want to copy informtion in here -> ";
    cin >> fileNameInWhichCopy;

    FileOpResult resultOf2Operation = copy_file(fileNameToCopy.c_str(), fileNameInWhichCopy.c_str());
    if(resultOf2Operation == Success)
    {
        cout << "Success!";
    }
    else
    {
        cout << endl;
        cout << "Failure!";
        return 1;
    }

    return 0;
}
