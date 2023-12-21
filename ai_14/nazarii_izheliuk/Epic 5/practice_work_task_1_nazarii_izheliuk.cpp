#include<iostream>
#include<fstream>
#include<string>

using namespace std;

enum FileOpResult {
    Success,
    Failure
};

FileOpResult file_create() {
    ofstream file("C:/Users/Lenovo Gaming/Desktop/file_from.txt");
    string input;

    if (!file.is_open()) {
        return Failure;
    }

    for (int i = 0; i < 10; i++) {
        getline(cin, input);
        file << input << endl;
    }

    file.close();
    return Success;
}

FileOpResult file_copy() {
    ifstream file_from("C:/Users/Lenovo Gaming/Desktop/file_from.txt");
    ofstream file_to("C:/Users/Lenovo Gaming/Desktop/file_to.txt");

    if (!file_from.is_open()) {
        return Failure;
    }

    char text;
    while (file_from.get(text)) {
        file_to.put(text);
    }

    file_from.close();
    file_to.close();
    return Success;
}

int main() {
    FileOpResult result1 = file_create();
    FileOpResult result2 = file_copy();

    if (result1 == Success && result2 == Success) {
        cout << "Success ";
    }
    else {
        cout << "Failure ";
    }
    return 0;
}
