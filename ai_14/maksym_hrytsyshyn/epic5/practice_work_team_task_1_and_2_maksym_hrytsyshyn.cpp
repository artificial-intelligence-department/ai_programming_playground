#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult {Success, Failure};

FileOpResult write_to_file(char *name, char *content) {
    ofstream fout(name, ios::out);
    if (!fout.is_open()) {
        return Failure;
    }

    fout << content;
    fout.close();
    return Success;
}

FileOpResult copy_file(char *file_from, char *file_to) {
    ifstream fin(file_from, ios::in);
    if (!fin.is_open()) {
        return Failure;
    }

    ofstream fout(file_to, ios::out);
    if (!fout.is_open()) {
        return Failure;
    }

    char ch;
    while (fin.get(ch)) {
        fout << ch;
    }

    fin.close();
    fout.close();

    return Success;
}

int main() {
    char name[50];
    cout << "Enter a file name: ";
    cin >> name;

    char content[250];
    cin.ignore();
    cout << "Enter a file content: ";
    cin.getline(content, 250);

    FileOpResult writingOutcome = write_to_file(name, content);
    if (writingOutcome == Success) {
        cout << "The file was successfully written to" << endl;
    } else {
        cout << "An error occurred while attempting to write to the file" << endl;
    }

    char file_to[50];
    cout << "Enter a file name to copy to: ";
    cin >> file_to;

    FileOpResult copyingOutcome = copy_file(name, file_to);
    if (copyingOutcome == Success) {
        cout << "The file was successfully copied" << endl;
    } else {
        cout << "An error occurred while attempting to copy the file" << endl;
    }

    return 0;
}
