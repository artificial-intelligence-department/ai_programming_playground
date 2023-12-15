#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string copyFileContent(string file_from, string file_to) {
    ifstream from(file_from, ios::binary);
    ofstream to(file_to, ios::binary);
    if (from.is_open() && to.is_open()) {
        to << from.rdbuf();
        return "Success";
    } else {
        return "Error";
    }
}

int main() {
    string fileFrom;
    string fileTo;
    cout << "Enter source file name: ";
    getline(cin, fileFrom);
    cout << "Enter destination file name: ";
    getline(cin, fileTo);
   
    cout << "Operation status: " << copyFileContent(fileFrom, fileTo) << endl;
    return 0;
}
