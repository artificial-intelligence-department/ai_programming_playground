#include<iostream>
#include<fstream>
#include<string>

using namespace std;

enum FileOpResult {  Failure , Succes};
FileOpResult write_to_file(char *name, string &content){
    ofstream f(name);

    if(!(f.good())){
        cout<<"Error!";
        return Failure;
    }

    f<<content;

    if(!(f.good())){
        cout<<"Error!";
        return Failure;
    }

    return Succes;
}

int main(){
    char name[20];
    string content;
    
    cout<< "Enter the file name\n";
    cin>>name;
    
    cout<< "Enter the contents\n";
    cin.ignore();
    getline(cin, content);


    if(write_to_file(name, content)){
        cout<<"Succes!";
        return 0;
    }
    cout<<"Failure!";
    return 0;

}