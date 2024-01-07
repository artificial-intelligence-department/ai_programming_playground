#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string PATH = "C:/files/university/programming-paradigms/data/";

const string FILE_FROM = "file_from.txt";
const string FILE_TO = "file_to.txt";

void createFile(string path, string content)
{
    ofstream deleteFile(path + ".txt", ios::trunc);
    deleteFile.close();

    ofstream writeFile;
    writeFile.open(path + ".txt", ios_base::app);
    if (!writeFile)
    {
        cout << "Failure\n";
        return;
    }
    writeFile << content;
    writeFile.close();
    cout << "Success\n";
}

void copyFile(string fromPath, string toPath)
{
    vector<string> output;
    string currentLine;
    ifstream readFile;
    readFile.open(fromPath, ios_base::app);
    if (!readFile)
    {
        cout << "Failure\n";
        return;
    }
    while (getline(readFile, currentLine))
    {
        cout << currentLine << "\n";
        output.push_back(currentLine);
    }
    readFile.close();

    ofstream deleteFile(toPath, ios::trunc);
    deleteFile.close();

    ofstream writeFile;
    writeFile.open(toPath, ios_base::app);
    if (!writeFile)
    {
        cout << "Failure\n";
        return;
    }
    for (int i = 0; i < output.size(); i++)
    {
        writeFile << output[i] << "\n";
    }
    writeFile.close();
    cout << "Success\n";
}

int main()
{
    cout << "--- Write File ---\n";

    cout << "Enter file name:\n";
    string name;
    cin >> name;

    cout << "Enter file content:\n";
    string content;
    cin >> content;

    createFile(PATH + name, content);

    cout << "--- Copy File ---\n";

    copyFile(PATH + FILE_FROM, PATH + FILE_TO);

    return 0;
}