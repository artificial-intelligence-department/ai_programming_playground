#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult{Success, Failure, NotExist,Failure2};

FileOpResult add(char* name,char* content)
{
    ofstream file;
    file.open(name, ios_base::out | ios_base::trunc);

    if (!file.is_open())
    {
        return Failure ;
    }
    file<<content;
    return Success;
}

FileOpResult copy(char* source,char* destination)
{
    const int  maxContentSize = 1000;
    char* buffer= new char[maxContentSize];
    ifstream file1;
    ofstream file2;

    file1.open (source,ios_base::in);
    if (!file1.is_open())
    {
        return Failure ;
    }
    file2.open (destination,ios_base::out);
    if(!file1.good())
    {
        return NotExist;
    }
    if (!file2.is_open())
    {
        return Failure2 ;
    }
    
    while(file1.getline(buffer,maxContentSize,'\0'))
    {
        file2<<buffer;
    }
    file1.close();
    file2.close();
    return Success;
}

int main()
{
    FileOpResult result;
    const int maxNameSize = 50, maxContentSize = 1000;
    char* name = new char[maxNameSize];
    char* content = new char[maxContentSize];
    cout<<"Enter name of file or path:\n";
    cin.getline(name,50);
    cout<<"Enter what you want to write:\n";
    cin.getline(content,1000);
    result = add(name,content);
    if(result == Failure)
    {
        cout << "Error opening the file to add something." << endl;
        exit(-1);
    }
    else
    {
        cout << "File successfully opened to add something." << endl;
    }
    char* source = new char[maxNameSize];
    char* destination = new char[maxNameSize];
    cout<<"Enter source name of file or path:\n";
    cin.getline(source,50);
    cout<<"Enter destination name of file or path:\n";
    cin.getline(destination,50);
    result = copy(source,destination);
    if(result == Failure)
    {
        cout << "Error opening source file." << endl;
        exit(-1);
    }
    else if(result == Failure2)
    {
        cout << "Error opening destination file." << endl;
        exit(-1);
    }
    else if(result == NotExist)
    {
        cout << "Source file doesn't exist." << endl;
        exit(-1);       
    }
    else
    {
        cout << "Copying was successful." << endl;
    }


    delete[]source;
    delete[]destination;
    delete[]name;
    delete[]content;
}