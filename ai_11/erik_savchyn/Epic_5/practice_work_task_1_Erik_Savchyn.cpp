#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const string& file_from, const string& file_to) {

    ifstream source(file_from, ios_base::binary | ios_base::app);
    
    if (!source.is_open()) {
        cerr << "Error opening source file." << endl;
        return Failure;
    }

    ofstream destination(file_to, ios_base::binary);

    if (!destination.is_open()) {
        cerr << "Error opening destination file." << endl;
        source.close();
        return Failure;
    }

    destination << source.rdbuf();

    if (destination.fail()) {
        cerr << "Error copying data from source to destination." << endl;
        source.close();
        destination.close();
        return Failure;
    }

    source.close();
    destination.close();

    return Success;
}

int main() {
    string source_file, destination_file;

    cout << "Enter the source file name: ";
    getline(cin, source_file);

    cout << "Enter the destination file name: ";
    getline(cin, destination_file);

    FileOpResult result = copy_file(source_file, destination_file);

    if (result == Success) {
        cout << "File copied successfully." << endl;
    } else {
        cerr << "File copying failed." << endl;
    }

    return 0;
}
