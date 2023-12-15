#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult {Success, Failure};

FileOpResult write_to_file(const char *name, const char *content) 
{
    if (!name||!content) 
    {
        cerr<<"Something's gone wrong";
        
        return FileOpResult::Failure;
    }
    ofstream file(name);
    if (!file) 
    {
        cerr<<"File can't be opened";
        
        return FileOpResult::Failure;
    }
    file << content;
    if (!file) 
    {
        cerr<<"File can't be opened";
        
        return FileOpResult::Failure;
    }
    file.close();

    return FileOpResult::Success;
}

int main() 
{
    const char *name = "File.txt";
    const char *content= "I want to sleep";

    FileOpResult result = write_to_file(name, content);

    if (result == FileOpResult::Success)
    {
        cout<<"Success";
    }
    else
    {
        cout<<"Failure";
    }

    return 0;
}
