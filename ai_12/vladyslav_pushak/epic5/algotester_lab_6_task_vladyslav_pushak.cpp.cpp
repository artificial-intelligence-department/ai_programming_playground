#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

void printVector(const vector<char>& vec) {
    cout << vec.size() << endl;
    for (const auto& el : vec) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {
    int numWords, threshold;
    cin >> numWords >> threshold;

    map<string, int> wordFrequency;
    set<string> frequentWords;

    for (int i = 0; i < numWords; ++i) {
        string word;
        cin >> word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordFrequency[word]++;
    }

    for (const auto& pair : wordFrequency) {
        if (pair.second >= threshold) {
            frequentWords.insert(pair.first);
        }
    }

    vector<char> uniqueChars;
    if (!frequentWords.empty()) {
        for (const auto& word : frequentWords) {
            for (const auto& ch : word) {
                uniqueChars.push_back(ch);
            }
        }
        
        sort(uniqueChars.begin(), uniqueChars.end());
        uniqueChars.erase(unique(uniqueChars.begin(), uniqueChars.end()), uniqueChars.end());
        reverse(uniqueChars.begin(), uniqueChars.end());
        printVector(uniqueChars);
    } else {
        cout << "Empty!" << endl;
    }

    return 0;
}
