#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int N, K;
    cin >> N;
    cin >> K;

    vector<string> words(N);
    unordered_map<string, int> wordCount;
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
        wordCount[words[i]]++;
    }

    unordered_set<string> validWords;
    for (const auto& entry : wordCount) {
        if (entry.second >= K) {
            validWords.insert(entry.first);
        }
    }
    vector<char> uniqueChars;
    for (const string& word : validWords) {
        uniqueChars.insert(uniqueChars.end(), word.begin(), word.end());
    }
    sort(uniqueChars.begin(), uniqueChars.end(), greater<char>());
    uniqueChars.erase(unique(uniqueChars.begin(), uniqueChars.end()), uniqueChars.end());
    if (uniqueChars.empty()) {
        cout << "Empty!";
    } else {
        cout << uniqueChars.size() << '\n';
        for (char ch : uniqueChars) {
            cout << ch << " ";
        }
    }

    return 0;
}