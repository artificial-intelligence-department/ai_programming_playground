#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum FileOpenResult {Success, Fail};

void FileOpening(string title, string text){
    ofstream file(title, ios::app);

    file << text;
    file.close();
}

FileOpenResult FileCopy(string file1, string file2){
    ifstream File_1(file1);
    ofstream File_2(file2, ios::app);

    if(!File_1.is_open()){
        return Fail;
    }
    if(!File_2.is_open()){
        return Fail;
    }

    string text;
    while(getline(File_1, text)) // зчитує текст з File_1
    {
        File_2 << text;
    }

    File_1.close();
    File_2.close();

    return Success;
}

int main(){
    string title1, title2, text;
    cout << "Enter the name of file 1 (with extention):" << endl;
    getline(cin, title1);
    cout << "Enter the name of file 2 (with extention):" << endl;
    getline(cin, title2);
    cout << "Enter the text you want to COPY" << endl;
    getline(cin, text);

    FileOpening(title1, text);
    
    FileOpenResult result = FileCopy(title1, title2);
    if(result == Success) cout << "You successfully copy the text";
    else if(result == Fail) cout << "ERROR";

    return 0;
}