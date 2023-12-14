#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult {
    Success,
    Failure
};

FileOpResult copy_file(const char *file_from, const char *file_to) {

    ifstream f3(file_from);
    ofstream f4(file_to);

    if (!f3.is_open()) {
        ofstream f3(file_from);
        cout << "Введіть текст в перший файл:";
        string line;
        while (getline(cin, line)) {
            f3 << line << endl;
        }
        f3.close();
        exit(0);
    }

    if (!f4.is_open()) {
        f4.close();
        return FileOpResult::Failure;
    }

    f4 << f3.rdbuf();
    // копіювання файлу

    if (f4.fail()) {
        f3.close();
        f4.close();
        return FileOpResult::Failure;
    }

    f3.close();
    f4.close();

    return FileOpResult::Success;
}

int main() {

    FileOpResult result = copy_file("file_from.txt", "file_to.txt");
    if (result == FileOpResult::Success) {
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }

    return 0;
}
