#include<iostream>
#include<fstream>
#include<string>

using namespace std;

enum FileOpResult{Success, Failure};

FileOpResult copy_file(string file_from, string file_to){
    ifstream file1;
    ofstream file2;
    file1.open(file_from);
    file2.open(file_to);

    if(!file1.is_open() || !file2.is_open()){
        return Failure;
    }else{
        string content;
        while(getline(file1, content)){
            file2<<content<<endl;
        }}
    file1.close();
    file2.close();
    return Success;
}

int main(){
    string file_from="from.txt";
    string file_to="to.txt";
    string text;
    cout<<"Введіть текст:"<<endl;
    getline(cin, text);

    ofstream file;
    file.open(file_from);
    if(file.is_open()){
        file<<text;
    } 
    file.close();

    FileOpResult res=copy_file(file_from, file_to);

    if(res==Success){
        cout<<"Ваш текст успішно скопійований"<<endl;
    }
    else if (res==Failure) {
        cout<<"Помилка"<<endl;
    }
    return 0;
}