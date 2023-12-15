#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult {Success, Failure};

FileOpResult write_to_file(char *name, char *content){

    ofstream file(name);
    if(!file.is_open()){
        return Failure;
    }

    file << content;
    file.close();
    return Success;
}

FileOpResult copy_file(char *file_from, char *file_to){
    ifstream ff(file_from, ios::in | ios::binary);  // файл-джерело (читання)
    //ios::in (read file)
    if(!ff.is_open()){
        cout << "Cannot open source file!" << endl;
        return Failure;
    }
    // ios::out(write file)
    // створення файлу для запису
    ofstream ft(file_to, ios::out | ios::binary); //файл-призначення (запис)
    if(!ft.is_open()){
        cout << "Cannot open this file";
        return Failure;
    }

    char tmp;
    // цикл посимвольного читання
    while (ff){
    ff.get(tmp); // зчитати з ff => tmp
    if (ff){
      ft << tmp; // запис tmp => ft
      } 
    }
    ff.close(); // закрити обидва файли
    ft.close();
    return Success;
}

int main(){
    char name[100];
    char content[255];

    cout << "Enter a file name: ";
    cin.getline(name, 100);

    cout << "Enter the content: ";
    cin.getline(content, 255);

    FileOpResult result = write_to_file(name, content);

    if(result == Success){
        cout << "File succcsfully created and content saved!" << endl;
    }else{
        cout << "Failed to create file and write content :(";
    }

    char file_to[100];
    cout << "Enter the destination file for copy: ";
    cin.getline(file_to, 100);

    FileOpResult copy_result = copy_file(name, file_to);
    if(result == Success){
        cout << "File succcsfully copy" << endl;
    }else{
        cout << "Failed to copy file :(";
    }
}