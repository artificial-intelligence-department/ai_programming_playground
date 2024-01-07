#include<iostream>
#include<fstream>
#include<string>
using namespace std;

enum FileOpResult {  Failure , Success};
FileOpResult copy (string &file_from, string &file_to, string &content){
    string text;
    ofstream t(file_to);
    ifstream f(file_from);

    if(t.bad()||f.bad()){
        return Failure;
    }

    while(getline(f, text)){
       cout << text<<"\n";
       t<<text;
    }

    f.close();
    t.close();

    if(f.bad()){
        cout<< "smth wrong...";
        return Failure;
    }
    if(t.bad()){
        cout<<"Error 2 ";
        return Failure;
    }
    
    return Success;
}
int main(){
    string name_from, name_to;
    string content;
    
    cout<< "Enter the file name\n";
    cin>>name_from;
    
    cout<< "Enter the contents\n";
    cin.ignore();
    getline(cin, content);

    ofstream fl(name_from);
    if(fl.bad()){
        cout<< "smth wrong...1";
        return 0;
    }

    fl<<content;
    fl.close();

    cout<< "Enter the file name to paste to \n";
    cin>>name_to;

    if(copy(name_from, name_to, content)){
        cout<<"Succes";
        return 0;
    }
    cout<<"Failure!";

    return 0;
}