#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult{
    Success,
    Failure
};

FileOpResult copy_file(char file_from[], char file_to[]){
    ifstream sourceFile(file_from);
    ofstream destinationFile(file_to);
    if(sourceFile.is_open() && destinationFile.is_open()){
        cout << "files opened successfully!" << endl;
        string line;
        while(getline(sourceFile, line)){
            destinationFile << line << endl;
        }
        cout << "file copied successfully!" << endl;
        sourceFile.close();
        destinationFile.close();
        if(!sourceFile.is_open() && !destinationFile.is_open()){
            cout << "files closed successfully!" << endl;
            return Success;
        }
        else{
            cout << "problem in closing files!" << endl;
            return Failure;
        }
    }
    else if (!sourceFile) {
        cout << "Failed to open source file." << endl;
        destinationFile.close();
        return Failure;
    }
    else if (!destinationFile) {
        cout << "Failed to open destination file." << endl;
        sourceFile.close();
        return Failure;
    }
    return Failure;
}

int main(){
    char file_from[20];
    char file_to[20];
    char content[200];
    char answer[5];

    do{
    
    cout << "file from: ";
    cin.getline(file_from, sizeof(file_from));
    cout << "file to: ";
    cin.getline(file_to, sizeof(file_to));

    FileOpResult copyResult = copy_file(file_from, file_to);
    if(copyResult == Success){
        ifstream copiedFile(file_to);
        string line;
        while(getline(copiedFile, line)){
            cout << line << endl;
        }
        copiedFile.close();
        cout << "file printed successfully!" << endl;
        cout << "want to try more? " << endl;
        cin >> answer;
    }
    else{
        cout << "want to try more? " << endl;
        cin >> answer;
    }
    cin.ignore();
    }while(strcmp(answer, "yes") == 0);
    
    cout << "bye!" << endl;

    return 0;
}