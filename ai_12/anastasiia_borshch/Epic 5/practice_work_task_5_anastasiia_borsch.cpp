#include <iostream>
#include <fstream>
#include <string>

enum File {
    Success,
    Failure,
};

File write_to_file(const std::string& name, const std::string& content);
File copy_file(const std::string& file_from, const std::string& file_to);

int main() {
    using namespace std;

    string contest;
    cout << "Enter content for the file: ";
    getline(cin, contest);

    File writeResult = write_to_file("from.txt", contest);

    if (writeResult == Success) {
        cout << "File created and written successfully." << endl;

        File copyResult = copy_file("from.txt", "file_to.txt");
        if (copyResult == Success) {
            cout << "File contents copy successfully." << endl;
        } else {
            cerr << "File contents copy failed." << endl;
        }
    } else {
        cerr << "File creation or writing failed." << endl;
    }
    return 0;
}
File write_to_file(const std::string& name, const std::string& content) {
    std::ofstream outputFile(name, std::ios::trunc);

    if (outputFile.is_open()) {
        outputFile << content;
        outputFile.close();
        return Success;
    } else {
        std::cerr << "Could not open file '" << name << "' for writing." << std::endl;
        return Failure;
    }
}
File copy_file(const std::string& file_from, const std::string& file_to) {
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
        from.close();  
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

