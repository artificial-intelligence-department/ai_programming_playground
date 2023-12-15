#include <fstream>
#include <iostream>

using namespace std;

enum OperationResult
{
	Success,
	Failure
};

OperationResult copyFileContents(const char *sourcePath, const char *destinationPath)
{
	if (sourcePath == nullptr || destinationPath == nullptr)
	{
		cout << "Error: Source or destination path is null." << endl;
		return Failure;
	}

	ifstream sourceFile(sourcePath, ios::binary);
	if (!sourceFile)
	{
		cout << "Error: Unable to open source file at " << sourcePath << endl;
		return Failure;
	}

	ofstream destinationFile(destinationPath, ios::binary);
	if (!destinationFile)
	{
		cout << "Error: Unable to open or create destination file at " << destinationPath << endl;
		return Failure;
	}

	destinationFile << sourceFile.rdbuf();
	if (!destinationFile)
	{
		cout << "Error: Failure during the file copy process." << endl;
		return Failure;
	}

	return Success;
}

int main()
{
	const char *sourceFilePath = "source.txt";
	const char *destinationFilePath = "destination.txt";

	OperationResult result = copyFileContents(sourceFilePath, destinationFilePath);
	if (result == Success)
	{
		cout << "File was successfully copied.\n";
	}
	else
	{
		cout << "Error occurred during file copy.\n";
	}

	return 0;
}
