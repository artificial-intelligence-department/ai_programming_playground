#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
enum FileOpResult {Success,Failure};
FileOpResult write_to_file(const string& fileName,const string& content){
    ofstream file(fileName);
    if(!file.is_open()){
        cerr<<"Trouble with opening";
        return Failure;
    }
    file<<content;
    return Success;
}


int main()
{
    string fileName;
    string content;
    cout<<"Enter the name of file: ";
    cin>>fileName;
    cin.ignore();
    cout<<"write something to file: ";
    getline(cin, content);
    if(write_to_file(fileName,content)==Success)
        cout<<"Success"<<endl;
    else
        cout<<"Failure";
    
    return 0;
}