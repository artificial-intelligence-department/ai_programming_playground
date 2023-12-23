#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to){
    string text = "This is an example text.";

    ofstream file1(file_from, ios::binary);
    if (!file1.is_open()){
        cerr << "An error has occurred, please try again." << endl;
        return Failure;
    }
    file1 << text;
    if(file1.fail()){
        cerr << "An error while creating a text for file1 has occurred, please try again." << endl; 
        file1.close();
        return Failure;
    }
    file1.close();

    ifstream input_file(file_from, ios::binary);
    if (!input_file.is_open()){
        cerr << "An error has occurred, please try again." << endl;
        return Failure;
    }

    ofstream file2(file_to, ios::binary);
    if (!file2.is_open()){
        cerr << "An error has occurred, please try again." << endl;
        return Failure;
    }
    file2 << input_file.rdbuf();
    if (file2.fail()) {
        cerr << "An error while writing has occurred, please try again." << endl;
        return Failure;
    }

    input_file.close();
    file2.close();

    return Success;
}

int main(){
    const char* file_from = "from";
    const char* file_to = "to";
    FileOpResult res = copy_file(file_from, file_to);

    if (res == Success){
        cout << "Operation proceeded successfully!";
    }
    else{
        cout << "Something went wrong, please try again.";
    }

    return 0;
}
