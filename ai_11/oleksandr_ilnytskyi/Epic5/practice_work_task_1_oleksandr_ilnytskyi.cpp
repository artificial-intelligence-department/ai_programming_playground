#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult {Success, Failure};

FileOpResult write_to_file(const char *name, const char *content, int mode = 0) {
    ofstream file;
    if (mode == 0) {
        file.open(name);
    }
    else {
        file.open(name, ios::app);
    }

    if (file.is_open()) {
        file << content << '\n';
        file.close();
    }
    else {
        return Failure;
    }

    return Success;
}

FileOpResult copy_file(const char *file_from, const char *file_to) {
    ifstream ffile(file_from);
    ofstream tfile(file_to);

    if (ffile.is_open() && tfile.is_open()) {
        string content;
        while (getline(ffile, content)) {
            tfile << content << '\n';
        }
    }
    else {
        return Failure;
    }

    return Success;
}

int main() {
    string name;
    string content;

    cout << "Enter file name, you want to write to:";
    cin >> name;
    cin.ignore();

    cout << "Enter content you want to write:";
    getline(cin, content);
    int result = write_to_file(name.c_str(), content.c_str());
    if (result == 0) {
        cout << "Write operation was successfully completed" << endl;
        while (true) {
            getline(cin, content);
            if (content == "quit") {
                break;
            }
            else {
                int resultIn = write_to_file(name.c_str(), content.c_str(), 1);
                if (resultIn == 0) {
                    cout << "Write operation was successfully completed" << endl;
                }
                else {
                    cout << "An error occurred while performing write operation" << endl;
                }
            }
        }
    }
    else {
        cout << "An error occurred while performing write operation" << endl;
    }

    string file_from;
    cout << "Enter name of file you want to copy:";
    cin >> file_from;
    string file_to;
    cout << "Enter name of file you want to paste the content:";
    cin >> file_to;
    result = copy_file(file_from.c_str(), file_to.c_str());
    if (result == 0) {
        cout << "Copy operation was successfully completed" << endl;
    }
    else {
        cout << "An error occurred while performing copying operation" << endl;
    }
    return 0;
}
