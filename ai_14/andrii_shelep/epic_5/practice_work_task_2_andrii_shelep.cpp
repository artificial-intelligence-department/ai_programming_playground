#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult{Success, Failure, Notexist};

FileOpResult copy_file(char *file_from, char *file_to);

int main(){
    char file_from[20];
    char file_to[20];
    cout << "enter the name of file from which you want to copy content:" << endl;
    cin.getline(file_from, sizeof(file_from));
    cout << "enter the name of file in which you want to copy content:" << endl;
    cin.getline(file_to, sizeof(file_to));
    FileOpResult res = copy_file(file_from, file_to);
    if(res == Success){
        cout << "the operation was successful" << endl;
        int choice;
        cout << "Do you want to see a new file?\n1 - yes\nother - no" << endl;
        cin >> choice;
        if(choice == 1){
            fstream inFile(file_to, fstream::in);
            if(inFile.is_open()){
                string line;
                while(getline(inFile, line)){
                    cout << line << endl;
                }
            } else{
                cout << "error" << endl;
            }
        }
    } else if(res == Notexist){
        cout << file_from << " does not exist" << endl;
    } else{
        cout << "the operation failed" << endl;
    }
    return 0;
}

FileOpResult copy_file(char *file_from, char *file_to){
    fstream inFile(file_from, fstream::in);
    if(inFile.fail()){
        return Notexist;
    }
    if(inFile.is_open()){
        fstream outFile(file_to, fstream::out | fstream::app);
        if(outFile.is_open()){
            string line;
            while(getline(inFile, line)){
                outFile << line << endl;
            }
            return Success;
        } else {
            return Failure;
        }
    } else{
        return Failure;
    }
}