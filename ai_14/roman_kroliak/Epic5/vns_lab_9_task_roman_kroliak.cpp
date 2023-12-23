#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void createFile (const string& filename, vector<string> s){
    ofstream file(filename, ios:: trunc);
    if (file.is_open()) {
        for (int i = 0; i < s.size(); i++)
        {
            file << s[i] << endl;
        }
        file.close();
    }
    else cout << "Error! File cannot be opened!" << endl;
}

void readFile (const string& filename){
    ifstream file(filename);
    if (file.is_open()) {
        string text;
        while (getline(file, text)) {
            cout << text << endl;
        }
        file.close();
    }
    else cout << "Error! File cannot be opened!" << endl;
}

string copyOnlyA (const string& filename){
    ifstream file(filename);
    ofstream newFile("f2.txt", ios:: trunc);
    if (file.is_open() && newFile.is_open()) {
        string text;
        while (getline(file, text)) {
            if (tolower(text[0]) == 'a') newFile << text << endl;
        }
        file.close();
        newFile.close();
    }
    else cout << "Error! File cannot be opened!" << endl;
    return "f2.txt";
}

int countWords (const string& filename){
    ifstream file(filename);
    int count = 0;
    if (file.is_open()) {
        string text;
        while (getline(file, text)) {
            if (text[0] != *" " && text[0] != *"") count++;
            for (int i = 1; i < text.length(); i++)
                if (text[i] == *" " && text[i+1] != *" " && i+1 < text.length()) count++;
        }
        file.close();
    }
    else cout << "Error! File cannot be opened!" << endl;
    return count;
}

int main(){
    vector<string> s;
    for (int i = 0; i < 10; i++){
        string a;
        getline(cin, a);
        s.push_back(a);
    }
    string filename = "f1.txt";
    createFile(filename, s);
    cout << "\nF2:\n";
    readFile(copyOnlyA(filename));
    cout << "\nWord count F2: " << countWords("f2.txt");
    return 0;
}