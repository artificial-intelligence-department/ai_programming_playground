#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Result { Success, Failure };
Result write(string name, string content) {
        ofstream file(name);

        if (!file.is_open()) {
            return Result::Failure;
        }

        file << content;
        file.close();

        if (!file) {
            return Result::Failure;
        }
        return Result::Success;
}

Result copy(string from, string to) {
    ifstream source_file(from);

    if (!source_file.is_open()) {
        return Result::Failure;
    }

    ofstream destination_file(to);

    if (!destination_file.is_open()) {
        source_file.close();
        return Result::Failure;
    }

    destination_file << source_file.rdbuf();

    source_file.close();
    destination_file.close();

    if (!source_file || !destination_file) {
        return Result::Failure;
    }

    return Result::Success;
}

int main() {
    string filename, content, source, destination;

    cin >> filename;
    cin.ignore(); 
    getline(cin, content);
    
    if (write(filename, content)==0) {
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }
    
    cin >> source;
    cin >> destination;

    if (copy(source, destination)==0) {
         cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
    }

    return 0;
}