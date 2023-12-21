#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult { Success, Failure};

FileOpResult write_to_file(char *name, char *content){
    if (name == nullptr) return Failure;
    string name_s;
    while(*name != '\0'){
        name_s.push_back(*name);
        ++name;
    }
    ofstream file(name_s, ios::trunc);
    if (file.is_open()) {
        if (content == nullptr) return Failure;
        while (*content != '\0') {
            file << *content;
            ++content;
        }
        file.close();
        return Success;
    }
    else return Failure;
}

FileOpResult copy_file(char *file_from, char *file_to){
    if (file_from == nullptr || file_to == nullptr) return Failure;
    string file_from_s;
    while(*file_from != '\0'){
        file_from_s.push_back(*file_from);
        ++file_from;
    }
    string file_to_s;
    while(*file_to != '\0'){
        file_to_s.push_back(*file_to);
        ++file_to;
    }
    ifstream file_from_f(file_from_s);
    ofstream file_to_f(file_to_s, ios::trunc);
    if (file_from_f.is_open() && file_to_f.is_open()) {
        string text;
        while (getline(file_from_f, text)) {
            file_to_f << text << endl;
        }
        file_from_f.close();
        file_to_f.close();
        return Success;
    }
    else return Failure;
}

int main(){
    char name[50], content[50];
    gets_s(name, 50);
    gets_s(content, 50);
    (write_to_file(name, content)) ? cout << "Failure\n" : cout << "Success\n";
    char file_from[50], file_to[50];
    gets_s(file_from, 50);
    gets_s(file_to, 50);
    (copy_file(file_from, file_to)) ? cout << "Failure" : cout << "Success";
    return 0;
}