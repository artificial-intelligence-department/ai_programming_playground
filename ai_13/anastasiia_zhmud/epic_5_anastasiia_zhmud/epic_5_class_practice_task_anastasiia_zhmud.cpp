#include<iostream>
#include<fstream>
#include<string>
using namespace std;
enum FileOpResult {Success, Failure};
FileOpResult write_to_file(char *name, char *content){
ofstream file(name);

    if (!file.is_open()) {
        return Failure;
    }
    file << content;

    if (file.fail()) {
        return Failure; 
    }
    file.close();
    if (file.fail()) {
        return Failure;
    }
    return Success;

}
FileOpResult copy_file(char* file_from, char* file_to) {
    ifstream from(file_from);
    if (!from.good()) {
        return Failure;
    }
    if (!from.is_open()) {
        return Failure;}
    ofstream to("file_to.txt");
    if (!to.is_open()) {
        from.close();
        return Failure;
    }
    to<<from.rdbuf();
    if(to.fail()) {
        to.close();
        from.close();
        return Failure;
        }
    else {
        to.close();
        from.close();
        return Success;
}
}

int main(){
    char* name= new char[100];
    char* content = new char[1000];
    name="practice1.txt";
    cout << "Enter a content: ";
    cin.getline(content, 1000);
    FileOpResult result = write_to_file(name, content);
    delete[] name;
    delete[] content;
    if (result == Success) {
        cout << "Y" << endl;
    } else {
        cout << "n" << endl;
    }

    char* file_from = new char [100000];
    file_from = "file_from.txt";
    char* file_to = new char [100000];
    FileOpResult rez2 =copy_file(file_from, file_to);
    delete[] file_from;
    delete[] file_to;
    if (rez2 == Success) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}