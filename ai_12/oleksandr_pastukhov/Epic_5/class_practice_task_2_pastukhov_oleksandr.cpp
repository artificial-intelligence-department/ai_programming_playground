#include <iostream>
#include <fstream>
#include <string>

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const std::string& file_from, const std::string& file_to);

int main() {
    using namespace std;

    string name_to;
    string name_from;

    cout << "Enter file to copy: ";
    cin >> name_from;

    cout << "Enter destination: ";
    cin >> name_to;

    FileOpResult result = copy_file(name_from, name_to);

    if (result == FileOpResult::Success) {
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }

    return 0;
}

FileOpResult copy_file(const std::string& file_from, const std::string& file_to) {
    std::ifstream file1(file_from);

    if (!file1.is_open()) {
        return FileOpResult::Failure;
    }

    std::ofstream file2(file_to);

    if (!file2.is_open()) {
        file1.close();
        return FileOpResult::Failure;
    }

    file2 << file1.rdbuf();

    if (file2.fail()) {
        file1.close();
        file2.close();
        return FileOpResult::Failure;
    }

    return FileOpResult::Success;
}
