#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void fileWrite(const string& filename, const string& content) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << content << '\n';
        file.close();
    }
}

void fileClear(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "";
        file.close();
    }
}

int fileCopyIf() {
    ifstream ffile("f1.txt");
    ofstream tfile("f2.txt");
    int length = 0;
    string line;
    while (getline(ffile, line)) {
        if (line[line.length()] != 0) {
            cout << line << endl;
            if (line[0] == line[line.length()]) {
                tfile << line << '\n';
                length += line.length();
            }
        }
        else {
            if (line[0] == line[line.length()-2]) {
                tfile << line << '\n';
                length += line.length();
            }
        }
    }
    ffile.close();
    tfile.close();

    return length;
}

int main() {
    fileClear("f1.txt");
    fileClear("f2.txt");
    fileWrite("f1.txt", "Hello world "
                        "\nI am Andy "
                        "\nAnd I'm Here "
                        "\nTo say hello "
                        "\nInt sad gnI "
                        "\nso here "
                        "\nstart with sames "
                        "\nTo say hello "
                        "\nTo say hello "
                        "\nso here");
    int f2length = fileCopyIf();
    cout << f2length << endl;
    return 0;
}
