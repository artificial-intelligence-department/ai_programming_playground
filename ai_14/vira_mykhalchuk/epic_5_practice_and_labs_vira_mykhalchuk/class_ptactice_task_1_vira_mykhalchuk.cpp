#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { success, failure };

FileOpResult write_to_file(const char* name, const char* content) { 
    ofstream file(name);

    if (!file.is_open() || file.fail()) {
        return failure; 
    }
    file << content;

    return success;
}

int main() {

    char filename[15];
    char content[250];

    cout << "Enter the name of the file: ";
    cin >> filename;

    cout << "Enter your content: ";
    cin.ignore();  
    cin.getline(content, sizeof(content));

    FileOpResult result = write_to_file(filename, content);

    if (result == success) {
        cout << "Your file is succeddfully created!\n";
    } else {
        cout << "ERROR\n";
    }

    return 0;
}