#include <iostream>
#include <fstream>
#include <string>

#define BUFSIZE 512

using namespace std;

enum FileOpResult {Success, Failure};
FileOpResult write_to_file(const char *name, char *content);
FileOpResult copy_file(const char *file_from, const char *file_to);

int main()
{   
    cout << "TASK 1\n\n";

    char content[BUFSIZE];

    cin.getline(content, sizeof(content));

    FileOpResult result = write_to_file("content.txt", content);

    if(result == Success)
    {
        cout << "Success\n" << endl;
    }
    else
    {
        cout << "Failure\n" << endl;
    }

    cout << "TASK 2\n\n";


    result = copy_file("old_content.txt", "new_content.txt");

    if(result == Success)
    {
        cout << "Success\n" << endl;
    }
    else
    {
        cout << "Failure\n" << endl;
    }

    return 0;
}
FileOpResult write_to_file(const char *name, char *content)
{
    if(name == NULL || content == NULL)
    {
        cerr << "Wrong parameters!\n" << endl;
        return Failure;
    }

    fstream file;

    file.open(name, ios::out);
    if((file.rdstate() & fstream::failbit) != 0)
    {
        cerr << "Failed to open file!\n" << endl;
        return Failure;
    }

    file << content;    
    if((file.rdstate() & fstream::badbit) != 0)
    {
        cerr << "Failed to insert to the file!\n" << endl;
        return Failure;
    }

    file.close();
    if((file.rdstate() & fstream::failbit) != 0)
    {
        cerr << "Failed to close the file!\n" << endl;
        return Failure;
    }

    return Success;
}
FileOpResult copy_file(const char *file_from, const char *file_to)
{
    string line;
    if(file_from == NULL || file_to == NULL)
    {
        cerr << "Wrong parameters!\n" << endl;
        return Failure;
    }

    fstream from;
    fstream to;

    from.open(file_from, ios::in);
    to.open(file_to, ios::out);

    if(((from.rdstate() & fstream::failbit) != 0) || (to.rdstate() & fstream::failbit))
    {
        cerr << "Failed to open file!\n" << endl;
        return Failure;
    }

    while(getline(from, line))
    {
        to << line << endl;
    }


    from.close();
    to.close();
    if(((to.rdstate() & fstream::failbit) != 0) || (to.rdstate() & fstream::failbit)) 
    {
        cerr << "Failed to close the file!\n";
        return Failure;
    }

    return Success;
}
