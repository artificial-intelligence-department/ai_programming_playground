#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult {Success, Failure};

FileOpResult write_to_file(const string& filename, const string& content){

    ofstream file(filename);

    if (!file.is_open()) {
        return Failure;
    }

    file << content;
    file.close();

    if (file.fail()) {
        return Failure;
    }
    return Success;
}

int main(){
    string filename, content;

    cout << "Enter the name of file: ";
    cin >> filename;

    cin.ignore(); 

    cout << "Enter the content to write to the file: ";
    getline(cin, content);

    if (write_to_file(filename, content) == Success) {
        cout << "Success\n";
    } else {
        cout << "Failure\n";
    }

    return 0;
}
