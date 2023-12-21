#include <iostream>
#include <fstream>
#include <string>


using namespace std;

string createAndWriteToFile(string name, string content) {
    ofstream file(name);
    if (file.is_open()) {
        file << content;
        file.close();
        return "Success";
    } else {
        return "Failure";
    }
}

int main() {
    string name;
    string content;
    cout << "Enter file name: ";
    getline(cin, name);
    cout << "Enter content: ";
    getline(cin, content);
    string status = createAndWriteToFile(name, content);
    cout << "Operation status: " << status << endl;
    return 0;
}