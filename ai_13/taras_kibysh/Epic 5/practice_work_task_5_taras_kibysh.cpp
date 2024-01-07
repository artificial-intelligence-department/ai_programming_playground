#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

enum FileOpResult {
    Success,
    Failure,
    // Add more result codes as needed
};

FileOpResult copy_file(const std::string& file_from, const std::string& file_to);
FileOpResult create_file(const std::string& file, const std::string& content);

int main() {
    using namespace std;

    string contest;
    cout << "Enter content for the file: ";
    getline(cin, contest);

    FileOpResult createResult = create_file("from.txt", contest);

    if (createResult == Success) {
        cout << "File created successfully." << endl;

        FileOpResult copyResult = copy_file("from.txt", "file_to.txt");
        if (copyResult == Success) {
            cout << "File contents copied successfully." << endl;
        } else {
            cerr << "File contents copy failed." << endl;
        }
    } else {
        cerr << "File creation failed." << endl;
    }

    return 0;
}

FileOpResult create_file(const std::string& file, const std::string& content) {
    std::ofstream outputFile(file, std::ios::trunc);

    if (outputFile.is_open()) {
        outputFile << content;
        outputFile.close();
        return Success;
    } else {
        std::cerr << "Could not open file '" << file << "' for writing." << std::endl;
        return Failure;
    }
}

FileOpResult copy_file(const std::string& file_from, const std::string& file_to) {
    using namespace std;
    std::ifstream from(file_from);

    if (!from.is_open()) {
        cerr << "Could not open source file." << endl;
        return Failure;
    }

    std::ofstream to(file_to);
    using namespace std;
    if (!to.is_open()) {
        cerr << "Could not open target file." << endl;
        return Failure;
    }

    char c;
    while (from.get(c)) {
        to.put(c);
    }

    from.close();
    to.close();

    return Success;
}
