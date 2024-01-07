#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const string& name, const string& content) 
{
    ofstream file(name);

    if (!file.is_open()) 
    {
        cerr << "Error opening file for writing: " << name << endl;
        return FileOpResult::Failure;
    }

    file << content;

    if (file.fail()) 
    {
        cerr << "Error writing content to file: " << name << endl;
        file.close();
        return FileOpResult::Failure;
    }

    file.close();
    return FileOpResult::Success;
}

FileOpResult copy_from_file(const string& source, const string& destination) {
    ifstream sourceFile(source, ios::binary);
    ofstream destFile(destination, ios::binary);

    if (!sourceFile.is_open()) 
    {
        cerr << "Error opening source file for reading: " << source << endl;
        return FileOpResult::Failure;
    }

    if (!destFile.is_open()) 
    {
        cerr << "Error opening destination file for writing: " << destination << endl;
        sourceFile.close();
        return FileOpResult::Failure;
    }

    destFile << sourceFile.rdbuf();

    if (destFile.fail()) 
    {
        cerr << "Error copying content from source to destination" << endl;
        sourceFile.close();
        destFile.close();
        return FileOpResult::Failure;
    }

    sourceFile.close();
    destFile.close();
    return FileOpResult::Success;
}

int main() {
    string filename, content;

    cout << "Enter the filename: ";
    cin >> filename;

    string relativePath = "C:/Users/Gil/OneDrive/Documents/GitHub/desktop-tutorial/Programming/Code/Epic 5/" + filename;

    cout << "Enter the content: ";
    cin.ignore(); 
    getline(cin, content);

    FileOpResult result = write_to_file(relativePath, content);

    if (result == FileOpResult::Success) 
    {
        cout << "File write successful!" << endl;

        string destinationPath = "C:/Users/Gil/OneDrive/Documents/GitHub/desktop-tutorial/Programming/Code/Epic 5/copy_" + filename;
        FileOpResult copyResult = copy_from_file(relativePath, destinationPath);

        if (copyResult == FileOpResult::Success) 
        {
            cout << "File copy successful!" << endl;
        } 

        else 
        {
            cout << "File copy failed!" << endl;
        }
    } 

    else 
    {
        cout << "File write failed!" << endl;
    }

    return 0;
}