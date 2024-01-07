#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void AddToFile(string path, string word){
    ofstream file;
    file.open(path, ios_base::app);
    file << "the shortest word in this file is: " << word;
    file.close();
}

void ReadTheFile(string path, vector<string>& words){
    ifstream file;
    file.open(path);
    string word;
    while (file >> word){
        words.push_back(word);
    }
    file.close();
}

void FillTheFile(string path, vector <string> vec){
    ofstream file;
    file.open(path, ios_base::app);
    for (int i = 0; i < vec.size(); i++){
        file << vec[i] << " ";
    }
    file << endl;
    file.close();
}

int main(){
    string path = "C:/Users/marko/Desktop/Study/Programming/Epic5/lab9.txt";
    string path1 = "C:/Users/marko/Desktop/Study/Programming/Epic5/lab9.1.txt";
    vector<string> wordsFromFile;
    vector<string> cutWords;
    char letter = 'm';

    ReadTheFile(path, wordsFromFile);

    for (int i = 0; i < wordsFromFile.size(); i++){
        if (wordsFromFile[i][0] != letter){
            cutWords.push_back(wordsFromFile[i]);
        }
    }

    string shortestword = cutWords[0];
    for (int i = 1; i < cutWords.size(); i++){
        if (shortestword.size() > cutWords[i].size()){
            shortestword = cutWords[i];
        }
    }
    FillTheFile(path1, cutWords);
    AddToFile(path1, shortestword);
    return 0;
}