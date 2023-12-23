#include <iostream>
#include <fstream>


enum FileOpResult {success, failure};

FileOpResult writeToFile(char* fileName,char* content) {
    std::ofstream file(fileName);

    if (!file.is_open() || file.fail()) {
        return failure; 
    }

    file << content;

    return success;
}

int main() {
    using namespace std;

    int fileNameSize = 15;
    int contentSize = 250;

    char fileName[fileNameSize];
    char content[contentSize];

    cout << "Enter the name of the file: ";
    cin.getline(fileName, sizeof(content));

    cout << "Enter your content: ";
    cin.ignore();  
    cin.getline(content, sizeof(content));

    FileOpResult result = writeToFile(fileName, content);

    if (result == success) {
        cout << "Your file is successfully created!" << endl;
    } else {
        cout << "ERROR" << endl;
    }
    
    return 0;
}
