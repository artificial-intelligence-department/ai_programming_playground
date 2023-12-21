#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure,};

FileOpResult copy_file(const string file_from, const string file_to)
{
    ifstream inFile(file_from,ios::in);
    ofstream outFile(file_to,ios::out);
    if(!inFile||!outFile)
    {
        return Failure;
    }

    string line;
    while(getline(inFile,line))
    {
        outFile<<line;
    }
    inFile.close();
    outFile.close();
    return Success;
}
int main()
{
    string file_from;
    string file_to;
    cout<<"Enter the file_from :\n";
    cin>>file_from;
    cout<<"Enter the file_to :\n";
    cin>>file_to;
    if(copy_file(file_from,file_to)==1)
    {
        cout<<"Failure";
    }
    else
    {
        cout<<"Success";
    }
    
}