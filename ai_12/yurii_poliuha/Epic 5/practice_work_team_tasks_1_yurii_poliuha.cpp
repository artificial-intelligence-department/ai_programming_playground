#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpenResult {Success, Fail};

FileOpenResult WriteToFile(string title, string text){
    ofstream file(title, ios::app);

    if(!file.is_open()){
        return Fail;
    }

    file << text << endl;
    file.close();
    return Success;
}

int main(){
    string title;
    string text;
    
    cout << "Enter the text you want to add to the file:" << endl; 
    getline(cin, text);
    cout << "Enter the title of your file with extention:" << endl;
    cin >> title;

    FileOpenResult result = WriteToFile(title, text);
    
    if(result == Success) cout << "Your file was opened and filled successfully" << endl;
    else if (result == Fail) cout << "ERROR" << endl;

    return 0;
}