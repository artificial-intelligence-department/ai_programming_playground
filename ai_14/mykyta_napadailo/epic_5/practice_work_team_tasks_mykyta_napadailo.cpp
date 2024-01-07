#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult {Success, Failure};
FileOpResult write_to_file(char* name, char* content);
FileOpResult copy_file(char* file_from, char* file_to);

int main()
{
    // Task 1
    char content[100], name[50];
    cout << "What do you want to write into the file?\n";
    cin.getline(content, sizeof(content));
    cout << "In which file to you want to write it?\n";
    cin.getline(name, sizeof(name));

    if (write_to_file(name, content) == Success)
    {
        cout << "The text was successfully written\n";
    }
    else cout << "Something went wrong\n";

    // Task 2
    char file_from[50], file_to[50];
    cout << "From what file do you want to copy?\n";
    cin.getline(file_from, sizeof(file_from));
    cout << "To what file do you want to copy?\n";
    cin.getline(file_to, sizeof(file_to));

    copy_file(file_from, file_to);

    if (copy_file(file_from, file_to) == Success)
    cout << "Text copied successfully\n";
}

FileOpResult write_to_file(char* name, char* content)
{
    ofstream fout(name);
    if (!fout) return Failure;
    fout << content;
    fout.close();
    return Success;
}

FileOpResult copy_file(char* file_from, char* file_to)
{
    ifstream fin(file_from);
    ofstream fout(file_to);
    if (!fin) 
    {
        cerr << "File " << file_from << " does not exist" << endl;
        fin.close(); 
        return Failure;
    }
    if (!fout)
    {
        cerr << "An error occured while writing into the file " << file_to << endl;
        fout.close();
        return Failure;
    }

    string str;
    while (getline(fin, str))
    {
        fout << str << endl;
    }
    fin.close(), fout.close();
    return Success;
}
