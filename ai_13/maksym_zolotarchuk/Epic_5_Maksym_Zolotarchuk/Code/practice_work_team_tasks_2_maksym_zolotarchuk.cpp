#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum class OperationResult
{
    Success,
    Failure
};

OperationResult copyFileContents(const string &sourcePath, const string &destinationPath)
{
    if (sourcePath.empty() || destinationPath.empty())
    {
        cout << "Error: Source or destination path is empty." << endl;
        return OperationResult::Failure;
    }

    ifstream sourceFile(sourcePath, ios::binary);
    if (!sourceFile)
    {
        cout << "Error: Unable to open source file at " << sourcePath << endl;
        return OperationResult::Failure;
    }

    ofstream destinationFile(destinationPath, ios::binary);
    if (!destinationFile)
    {
        cout << "Error: Unable to open or create destination file at " << destinationPath << endl;
        return OperationResult::Failure;
    }

    destinationFile << sourceFile.rdbuf();
    if (!destinationFile)
    {
        cout << "Error: Failure during the file copy process." << endl;
        return OperationResult::Failure;
    }

    return OperationResult::Success;
}

int main()
{
    const string sourceFilePath = "source.txt";
    const string destinationFilePath = "destination.txt";

    OperationResult result = copyFileContents(sourceFilePath, destinationFilePath);
    if (result == OperationResult::Success)
    {
        cout << "File was successfully copied.\n";
    }
    else
    {
        cout << "Error occurred during file copy.\n";
    }

    return 0;
}
