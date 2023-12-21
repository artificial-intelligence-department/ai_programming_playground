#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult write_to_file(string name, string content)
{
    ofstream outf(name);

    if(!outf)
    {
        cerr << "Error" << endl;
        return Failure;
    }

    outf << content << endl;

    outf.close();

    return Success;

};

FileOpResult copy_file(string file_from, string file_to)
{
    ifstream inf(file_from);
    ofstream outf(file_to);

    if(!outf || !inf)
    {
        cerr << "Error" << endl;
        return Failure;
    }

    string line;
    while(getline(inf, line))
    {
        outf << line << endl;
    }

    inf.close();
    outf.close();

    return Success;
};

int main()
{
    cout << "Write the name of the file, you want to create" << endl;
    string name, content;
    cin >> name;

    cout << "What do you want to add there?" << endl;

    cin.ignore();
    getline(cin, content);

    FileOpResult result_write = write_to_file(name, content);

    if(result_write == Success)
    {
        cout << "First task is successfully done" << endl;
    }
    else
    {
        cout << "It was a fatal failure" << endl;
    }

    cout << "Write the name of the file, you want to copy from" << endl;
    string file_from, file_to;
    
    cin >> file_from;

    cout << "Write the name of the file, you want to copy to" << endl;

    cin >> file_to;

    FileOpResult result_copy = copy_file(file_from, file_to);

    if(result_copy == Success)
    {
        cout << "Second task is successfully done" << endl;
    }
    else
    {
        cout << "It was a fatal failure 2x" << endl;
    }
    
    return 0;
}
