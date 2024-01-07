#include<iostream>
#include<fstream>
#include<string>
using namespace std;

enum FileOpResult { Success, Failure};

FileOpResult write_to_file(string name, string content)
{
    ofstream File(name);

    if(!File.is_open()){
        return Failure;
    }

    File << content<<endl;
    
    File.close();
    
    return  Success;
}

int main()
{
    string content;
    string name = "testing_file.txt";

    cout<<"Enter a text which you want add to file: "<<endl;
    getline(cin, content);

    FileOpResult result = write_to_file(name, content);

    if (result == Success)
    {
        cout<<"Your file successfully filled"<<endl;
    }
    else if(result == Failure)
    {
        cout<<"ERROR"<<endl;
    }

    return 0;
}