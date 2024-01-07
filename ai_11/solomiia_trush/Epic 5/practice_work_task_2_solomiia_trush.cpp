#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char* file_from, const char* file_to) {
    if (!file_from || !file_to) {
        cerr << "Invalid input: file_from or file_to is null." << endl;
        return Failure;
    }

    ifstream source(file_from, ios::binary);

    if (!source.is_open()) {
        cerr << "Error opening source file: " << file_from << endl;
        return Failure;
    }

    ofstream destination(file_to, ios::binary);

    if (!destination.is_open()) {
        cerr << "Error opening destination file: " << file_to << endl;
        source.close(); 
        return Failure;
    }

    destination << source.rdbuf();

    if (destination.fail()) {
        cerr << "Error copying file content." << endl;
        source.close();      
        destination.close(); 
        return Failure;
    }

    
    source.close();
    destination.close();

    return Success;
}

int main() {
    const char* file_from = "source.txt";
    const char* file_to = "destination.txt";

    FileOpResult result = copy_file(file_from, file_to);

    if (result == Success) {
        cout << "File successfully copied." << endl;
    } else {
        cout << "Failed to copy the file." << endl;
    }

    return 0;
}
