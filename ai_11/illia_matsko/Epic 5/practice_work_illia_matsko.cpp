#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult {Success, Failure};

FileOpResult write_to_file(string name, string content) {
    if (name.empty() || content.empty()) {
        return Failure;
    }

    ofstream file(name, ios::trunc);
    if (!file.is_open()) {
        return Failure;
    }

    file << content;

    if (file.fail()) {
        return Failure;
    }

    file.close();

    if (file.fail()) {
        return Failure;
    }

    return Success;
}

FileOpResult copy_file(string file_from, string file_to) {
    if (file_from.empty() || file_to.empty()) {
        return Failure;
    }

    ifstream source(file_from, ios::binary);
    if (!source.is_open()) {
        return Failure;
    }

    ofstream destination(file_to, ios::binary | ios::trunc);
    if (!destination.is_open()) {
        return Failure;
    }

    destination << source.rdbuf();

    if (destination.fail()) {
        return Failure;
    }

    source.close();
    destination.close();

    if (source.fail() || destination.fail()) {
        return Failure;
    }

    return Success;
}

FileOpResult print_file_content(string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return FileOpResult::Failure;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return FileOpResult::Success;
}

int main() {
    string fileFrom = "source.txt";
    string fileTo = "destination.txt";

    cout << "Enter strings(to stop type 'exit'):" << endl;

    string content;
    string line;
    while (getline(cin, line) && line != "exit") {
        content += line + "\n";
    }

    FileOpResult result = write_to_file(fileFrom, content);

    if (result == Success) {
        cout << "Successfully written content to " << fileFrom << "'." << endl;

        result = copy_file(fileFrom, fileTo);

        if (result == Success) {
            cout << "Successfully copied to " << fileTo << "'." << endl;
        } else {
            cerr << "Error" << endl;
        }
    } else {
        cerr << "Error" << endl;
    }

    cout << "Second file content:" << endl;
    print_file_content("destination.txt");

    return 0;
}