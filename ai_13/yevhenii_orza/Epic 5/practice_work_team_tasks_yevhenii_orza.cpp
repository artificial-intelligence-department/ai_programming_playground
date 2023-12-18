#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content) {
    ofstream file(name);

    if (file.is_open()) {
        file << content;
        file.close();
        return FileOpResult::Success;
    } else {
        cout << "Error: Unable to open file " << name << " for writing." << endl;
        return FileOpResult::Failure;
    }
}

FileOpResult copy_file(const char *file_from, const char *file_to) {
    ifstream MyReadFile(file_from);
    ofstream MyCopyFile(file_to);
    string mytext;

    if (MyReadFile.is_open() && MyCopyFile.is_open()) {
        while (getline(MyReadFile, mytext)) {
            MyCopyFile << mytext;
        }

        MyReadFile.close();
        MyCopyFile.close();

        return FileOpResult::Success;
    } else {
        cout << "Error: Unable to open files for copying." << endl;
        return FileOpResult::Failure;
    }
}

int main() {
    const char *filename = "file.txt";
    const char *file_content = "Hello from ai 13, have a good day";

    FileOpResult result = write_to_file(filename, file_content);

    if (result == FileOpResult::Success) {
        cout << "File write successful." << endl;
    } else {
        cout << "File write failed." << endl;
        return 1; // Вихід з програми через помилку запису в файл
    }

    const char *file_from = "copyfile.txt";
    const char *file_to = "copyfile_copy.txt";

    string copytext;
    ofstream copyfile ("copyfile.txt");

    if (!copyfile.is_open() || cin.fail()) {
        cout << "Error: Unable to open copyfile.txt for writing." << endl;
        return 1; // Вихід з програми через помилку відкриття файлу для запису
    }

    cout << "Enter text to copy" << endl;
    cin >> copytext;
    copyfile << copytext;
    copyfile.close(); // Закриття файлу після запису

    FileOpResult copyResult = copy_file(file_from, file_to);

    if (copyResult == FileOpResult::Success) {
        cout << "File copy successful." << endl;
    } else {
        cout << "File copy failed." << endl;
        return 1; // Вихід з програми через помилку копіювання файлу
    }

    return 0;
}
