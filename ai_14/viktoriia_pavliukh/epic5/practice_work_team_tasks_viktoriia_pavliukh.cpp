#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult {Success, Failure};


FileOpResult write_to_file(char* name, char* content){
    ofstream file1(name);
    if (!file1) return Failure;
        file1 << content;
        file1.close();
        return Success;
}

FileOpResult copy_file(char* file_from, char* file_to){
    ifstream file1(file_from);
    ofstream file2(file_to);
    if (!file1)
    {
        cerr << "File " << file_from << " does not exist" << endl;
        file1.close();
        return Failure;
    }
    if (!file2)
    {
        cerr << "An error occured while writing into the file " << file_to << endl;
        file2.close();
        return Failure;
    }

    string str;
    while (getline(file1, str))
    {
        file2 << str << endl;
    }
    file1.close(), file2.close();
    return Success;
}

int main() {
    char name[] = "F1.txt";
    char content[100];
    cout << "enter the content, which you want to write to file" << endl;
    cin.getline(content, sizeof(content));
    FileOpResult res = write_to_file(name, content);
    if(res == Success){
        cout << "successful!" << endl;
    } else{
        cout << "failed!" << endl;
    }
    return 0;
}


