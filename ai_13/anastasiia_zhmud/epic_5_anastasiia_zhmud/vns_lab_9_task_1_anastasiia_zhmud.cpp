#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
bool twowords(string line){
    vector<string> s;
    int position=0,len=0, k;
    for (char c : line) {
        if (c == ' ') ++len;
    }
    while(true){
        k=line.find(' ', position);
        s.push_back(line.substr(position, k-position));
        position = k + 1;
        if(k == string::npos){
            break;
        }
    }
    k=0;
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s.size(); j++){
            if(s[i]==s[j] && i!=j) return 1;
        }
    }
    return 0;
}
int number(vector<string> s){
    int a=0, count=0, rez=0;
     for (int i = 0; i < s.size(); i++) {
        for (char c : s[i]) 
        if (c == 'A' || c == 'a') a++;
        if(a>count){
            count = a;
            rez = i+1;
        }
        a=0;
}
return rez;
}
int main(){
    int n;
    int position=0,k=0;
    vector<int> A;
    vector<string> s;
    string line;
    ifstream inFile("F1.txt");
    ofstream outFile("F2.txt");
    if (!inFile.is_open() || !outFile.is_open()) {
        cout<< "Error!" << endl;
        return 1;
    }
    while(getline(inFile, line)){
    if(twowords(line)) outFile << line << endl;
    while(true){
        k=line.find(' ', position);
        s.push_back(line.substr(position, k-position));
        position = k + 1;
        if(k == string::npos){
            break;
        }
    }
    }
    cout<<"the word with the largest number of letters a has a number:  "<<number(s);
    inFile.close();
    outFile.close();
}