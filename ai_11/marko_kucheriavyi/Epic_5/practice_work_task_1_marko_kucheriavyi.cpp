#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void write(string path, vector <string> sentences){
    ofstream file;
    file.open(path, ios_base::app);
    if (!file){
        cout << "File writing fail" << endl;
        return;
    }
    cout << "File writing success" << endl;
    for (int i = 0; i < sentences.size(); i++){
        file << sentences[i] << endl;
    }
    file.close();
}

void read(string path, vector <string>& vec){
    ifstream file;
    file.open(path);
    if (!file){
        cout << "File reading fail" << endl;
        return;
    }
    cout << "File reading success" << endl;
    string line;
    while (getline(file, line)){
        vec.push_back(line);
    }
    file.close();
}

int main(){
    vector <string> sentences = {"I love pizza", "It is very tasty"};
    vector <string> ReadFromFile;
    string path1 = "C:/Users/marko/Desktop/Study/Programming/Epic5/practice_from.txt";
    string path2 = "C:/Users/marko/Desktop/Study/Programming/Epic5/practice_to.txt";

    write(path1, sentences);
    read(path1, ReadFromFile);
    write(path2, ReadFromFile);

    return 0;
}