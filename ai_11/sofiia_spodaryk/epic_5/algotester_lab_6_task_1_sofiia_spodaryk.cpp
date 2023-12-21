#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

vector<string> getFrequentWords(int N, int K) {
    unordered_map<string, int> wordCount;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;

        transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordCount[word]++;
    }

    vector<string> frequentWords;

    for (const auto &entry : wordCount) {
        if (entry.second >= K) {
            frequentWords.push_back(entry.first);
        }
    }

    return frequentWords;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<string> frequentWords = getFrequentWords(N, K);

    if (frequentWords.empty()) {
        cout << "Empty!";
        return 0;
    }

    set<char> uniqueCharacters;

    for (const string &word : frequentWords) {
        for (char ch : word) {
            uniqueCharacters.insert(ch);
        }
    }

    cout << uniqueCharacters.size() << endl;

    for (char ch : uniqueCharacters) {
        cout << ch << " ";
    }

    return 0;
}