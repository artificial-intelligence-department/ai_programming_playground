#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult{Success, Failure};

FileOpResult write_to_file(char *name, char *content);

int main(){
    char name[] = "file1.txt";
    char content[100];
    cout << "enter the content, which you want to write to file" << endl;
    cin.getline(content, sizeof(content));
    FileOpResult res = write_to_file(name, content);
    if(res == Success){
        cout << "The operation was successful!" << endl;
        int choice;
        cout << "Do you want print the file?\n1 - yes\nother - no" << endl;
        cin >> choice;
        if(choice == 1){
            fstream file(name, fstream::in);
            if(file.is_open()){
                string line;
                while(getline(file, line)){
                    cout << line << endl;
                }
            } else{
                cout << "error" << endl;
            }
        }
    } else{
        cout << "The operation was failed!" << endl;
    }
    return 0;
}

FileOpResult write_to_file(char *name, char *content){
    fstream file(name, fstream::out);
    if(file.is_open()){
        file << content;
        file.close();
        return Success;
    } else{
        cout <<  "error" << endl;
        return Failure;
    }
}