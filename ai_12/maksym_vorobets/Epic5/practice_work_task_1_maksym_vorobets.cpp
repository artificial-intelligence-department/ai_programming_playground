#include<iostream>
#include<fstream>
#include<string>

using namespace std;

enum FileOpResult {Success, Failure};

FileOpResult write_to_file(string name, string content)
{
    ofstream file;
    file.open(name);
    if(!file.is_open()){
        return Failure;
    }else{
        file<<content<<endl;
        }
    file.close();
    return  Success;
}

int main()
{
    string content;
    string name="file.txt";
    cout<<"Введіть текст: "<<endl;
    getline(cin, content);

    FileOpResult res=write_to_file(name, content);

    if (res==Success){
        cout<<"Файл успішно заповнений"<<endl;
    }
    else if(res==Failure){
        cout<<"Помилка"<<endl;
    }

    return 0;
}