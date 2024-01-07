#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
using namespace std;

vector<string> splitstring(string& line){
    vector<string> w;
    istringstream iss(line);
    string word;
    while (iss >> word){
        w.push_back(word);
    }
    return w;
}

void Longestword(vector<string>& words){
    sort(words.begin(), words.end());
    string longestword = words.front();
    cout << longestword;
}

int main(){
vector<string> lines;
string line;
string FILE1= "file1.txt";
string FILE2="file2.txt";
fstream fl1;
ofstream fl2;
fl1.open(FILE1, fstream::in | fstream::out);
fl2.open(FILE2);
if(!(fl1.is_open()|| fl2.is_open())){
    cout << "ERROR";
    }

 while (getline(fl1, line)) {
        lines.push_back(line);
    }


   for(auto& line : lines){
    vector<string>words = splitstring(line); 
    set<string> uniqueWords(words.begin(), words.end());
   
       if(uniqueWords.size()<words.size()){
            fl2 << line <<"\n";
       }
        
    Longestword(words);
   }
   
fl1.close();
fl2.close();



}