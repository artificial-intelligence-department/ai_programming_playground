#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum FileOpResult { 
    Success, 
    Failure
};

FileOpResult write_to_file(char *name, char *content) {
    ofstream out(name, ios::binary);
    if (!out) {out.close(); return Failure;}
    out << content;
    if (out.ios::good()) {out.close(); return Success;}
    else {out.close(); return Failure;}
}

FileOpResult copy_file(char *file_from, char *file_to) {
    ifstream in(file_from, ios::binary);
    ofstream out(file_to, ios::binary);
    if ((!out) || (!in)) {return Failure;}
    string tmp;
    while (getline(in, tmp)) {out << tmp << '\n';}
    if (out.ios::good() && in.ios::eof()) {return Success;}
    else {return Failure;}
}

int main() {
    char name[9] = "test.txt", c[] = "copied.cpp";
    vector<char> content;
    char temp;
    temp = cin.get();
    content.push_back(temp);
    int i=1;
    while(1) {
        temp = cin.get();
        content.push_back(temp);
        if ((content[i] == '\n')&&(content[i-1] == '\n')) {break;}
        ++i;
    }
    char *to_write = new char[content.size() + 1];
    for (i=0; i<content.size(); i++) {to_write[i] = content[i]; }
    to_write[i] = '\0';
    if (write_to_file(name, to_write)) { std::cout << "Failure"; }
    else {std::cout << "Success"; }
    if (copy_file(name, c)) { std::cout << "Failure"; }
    else {std::cout << "Success"; }
    return 0;
}