#include<iostream>
#include<fstream>
#include<string>
using namespace std;

enum FileOpResult { Success, Failure};

FileOpResult copy_file(string file_from, string file_to)
{
    ifstream File1 (file_from);

    ofstream File2 (file_to);

    if(!File1.is_open())
    {
        return Failure;
    }
    else
    {
        if (!File2.is_open())
        {
            return Failure;
        }
    }
        string content;

        while(getline(File1, content))
        {
            File2<<content<<endl;
        }
        
        File1.close() , File2.close();
         return Success;
}

int main()
{
    string file_from ="start.txt";
    string file_to = "final.txt";
    string text;

    cout<<"Enter the text which you want to copy!"<<endl;
    getline(cin , text);

    ofstream outputFile(file_from);
    
    if (outputFile.is_open()) {
        outputFile << text;
        outputFile.close();
    } 

    FileOpResult result = copy_file(file_from, file_to);

    if(result == Success)
    {
        cout<<"Your file content is successfully copy!"<<endl;
    }
    else if (result == Failure)
    {
        cout<<"ERROR"<<endl;
    }
    return 0;
}