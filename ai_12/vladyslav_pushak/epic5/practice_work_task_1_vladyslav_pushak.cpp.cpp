#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Status { Ok, Error };

Status saveToFile(string filename, string data) {
    ofstream outFile(filename);

    if (!outFile) {
        return Status::Error;
    }

    outFile << data;
    outFile.close();

    if (!outFile) {
        return Status::Error;
    }

    return Status::Ok;
}

Status duplicateFile(string original, string copy) {
    ifstream inFile(original);

    if (!inFile) {
        return Status::Error;
    }

    ofstream outFile(copy);

    if (!outFile) {
        inFile.close();
        return Status::Error;
    }

    outFile << inFile.rdbuf();

    inFile.close();
    outFile.close();

    if (!inFile || !outFile) {
        return Status::Error;
    }

    return Status::Ok;
}

int main() {
    string file, text, orig, dup;

    cin >> file;
    cin.ignore(); 
    getline(cin, text);
    
    if (saveToFile(file, text) == Status::Ok) {
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }
    
    cin >> orig;
    cin >> dup;

    if (duplicateFile(orig, dup) == Status::Ok) {
         cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }

    return 0;
}
