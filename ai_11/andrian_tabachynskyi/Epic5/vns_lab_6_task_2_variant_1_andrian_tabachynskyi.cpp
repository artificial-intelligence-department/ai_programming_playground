
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string s;

    
    cout << "Enter the line: ";
    getline(cin,s);

   
    stringstream ss(s);
    vector<string> words;
    unordered_map<string, int> count;  

    string word;
    while (ss >> word) {
        words.push_back(word);
        count[word]++;
    }

    cout << "Words that are not repeated:" << endl;
    for (const auto& w : words) {
        if (count[w] == 1) {
            cout << w << endl;
        }
    }

    return 0;
}