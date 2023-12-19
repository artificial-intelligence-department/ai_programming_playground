#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;


enum FileOpResult { Success, Failure };


FileOpResult write_to_file(const char* name, const char* content) {
    ofstream file(name);  


    if (!file.is_open()) {
        return Failure; 
    }


    file << content;  
    file.close();    


    return Success;  
}


FileOpResult copy_file(const char* file_from, const char* file_to) {
    ifstream source(file_from, ios::binary);  
    ofstream destination(file_to, ios::binary);  


    if (!source.is_open() || !destination.is_open()) {
        return Failure; 
    }


    destination << source.rdbuf();  


    source.close();       
    destination.close();  


    return Success;  
}


int main() {
    string content;
    cout << "Enter content to write to file: ";
    getline(cin, content);


    const char* filename = "example.txt";
    FileOpResult result = write_to_file(filename, content.c_str());


    if (result == Success) {
        cout << "Content copied" << endl;
    } else {
        cout << "Failed to write to file." << endl;
        return 1;  
    }
    string file_to_copy;
    cout << "Enter the name of the file to copy to: ";
    getline(cin, file_to_copy);


    result = copy_file(filename, file_to_copy.c_str());


    if (result == Success) {
        cout << "Content is pasted." << endl;
    } else {
        cout << "Failed to copy file." << endl;
        return 1;
    }


    return 0;
}
