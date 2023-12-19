#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

int eyuoia(string& s) {
    int b = 0;
    for (char a : s) {
        if (a == 'e' || a == 'u' || a == 'i' || a == 'o' || a == 'a' || a == 'y' || a == 'E' || a == 'U' || a == 'I' || a == 'O' || a == 'A' || a == 'Y') {
            b++;
        }
    }
    return b;
}

bool isStrGood(string s) {
    istringstream iss(s);
    unordered_set<string> words;
    string word;
    while (iss >> word) {
        if (words.find(word) != words.end()) {
            return false;
        }
        words.insert(word);
    }
    return true;
}

int main() {
    int n, num = 0;
    cout << "Enter number of strings you want to input:" << endl;
    cin >> n;
    cin.ignore();

    vector<bool> arr;
    vector<string> vec;

    fstream f;
    f.open("file1.txt", fstream::in | fstream::out | fstream::trunc);
    if (!f.is_open()) {
        cout << "Error opening the file." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        string msg;
        cout << "Enter row #" << i + 1 << endl;
        getline(cin, msg);
        f << msg << "\n";
        arr.push_back(isStrGood(msg));
        vec.push_back(msg);
    }
    f.close();

    fstream f2;
    f2.open("file2.txt", fstream::in | fstream::out | fstream::trunc);
    if (!f2.is_open()) {
        cout << "Error opening the file." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            f2 << vec[i] << "\n";
        }
    }

    f2.close();

    f2.open("file2.txt", fstream::in);
    if (!f2.is_open()) {
        cout << "Error opening the file." << endl;
        return 1;
    }

    string buffer;
    getline(f2, buffer);
    f2.close();

    int res = eyuoia(buffer);

    cout << "First line from file2.txt: " << buffer << endl;
    cout << "Number of vowels: " << res << endl;

    return 0;
}
