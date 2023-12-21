#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(const char *file_from, const char *file_to) {
    ifstream source(file_from, ios::binary);
    ofstream destination(file_to, ios::binary);

    if (!source.is_open() || !destination.is_open()) {
        return Failure;
    }

    destination << source.rdbuf();

    if (destination.fail()) {
        source.close();
        destination.close();
        return Failure;
    }

    source.close();
    destination.close();

    return Success;
}

int main() {
    const char *source_file = "source.txt";
    const char *destination_file = "destination.txt";

    FileOpResult result = copy_file(source_file, destination_file);

    if (result == Success) {
        cout << "Success." << endl;
    } else {
        cout << "Failure." << endl;
    }

    return 0;
}
