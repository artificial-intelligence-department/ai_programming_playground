#include <iostream>
#include <fstream>
using namespace std;

void write_to_file(const string& filetowritename, const string& text) {
    ofstream fileStream(filetowritename, ios::out);

    if (!fileStream.is_open()) {
        cerr << "Could not open the file! \n";
        return;
    }

    fileStream << text;
}

void copy_file(const string& filetowritename, const string& filetocopyname) {
    ifstream sourcefile(filetowritename, ios::in);
    ofstream copyfile(filetocopyname, ios::out);

    if (!sourcefile.is_open() || !copyfile.is_open()){
        cerr << "Could not open the files! \n";
        return;
    }

    char character;
    while (sourcefile.get(character)){
        copyfile.put(character);
    }
}

int main() {
    string filetowrite = "file_to_write.txt";
    string filetocopy = "file_to_copy.txt";

    cout << "Enter some text: ";
    string text;
    getline(cin, text);

    write_to_file(filetowrite, text);
    copy_file(filetowrite, filetocopy);

    return 0;
}
