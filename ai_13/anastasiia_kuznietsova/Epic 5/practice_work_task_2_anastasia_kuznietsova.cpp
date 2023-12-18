#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpResult {Success, Failure};

FileOpResult copy_file(string file_from, string file_to)
{
    ifstream from(file_from);
    if (!from)
    {
        cerr<<"File can't be opened";

        return FileOpResult::Failure;
    }
    ofstream to(file_to);
    if (!to) 
    {
        cerr<<"File can't be opened";

        return FileOpResult::Failure;
    }
    string line;

    while (getline(from, line))
    {
        to<<line<<"\n"; 
    } 
    from.close();
    to.close();
    
    return FileOpResult::Success;
}

int main()
{
    string file_from = "D:/paradigms/Epic 5/F1.txt";
    string file_to = "D:/paradigms/Epic 5/F2.txt";

    ofstream data (file_from);
    if (!data)
    {
        cerr<<"File can't be opened";

        return FileOpResult::Failure;
    }
    data<<"MEOW MEOW MEOW MEOW MEOW MEOW MEOW MEOW MEOW MEOW MEOW MEOW MEOW";
    data.close();

    FileOpResult result = copy_file(file_from, file_to);
    if (result == FileOpResult::Success) 
    {
        cout<<"Success";
    } 
    else 
    {
        cerr<<"Failure";
    }
    
    return 0;
}