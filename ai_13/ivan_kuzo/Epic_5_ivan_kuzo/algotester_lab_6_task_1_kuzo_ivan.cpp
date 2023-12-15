#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    vector<string> words;
    unordered_map<string, int> wordCount;
    unordered_set<char> uniqueLetters;
    int N, K;
    cin >> N >> K;
    string word;

    for (int i = 0; i < N; ++i) {
        cin >> word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
        wordCount[word]++;
    }

    for (const auto& entry : wordCount) {
        if (entry.second >= K) {
            for (char ch : entry.first) {
                uniqueLetters.insert(ch);
            }
        }
    }

    if (!uniqueLetters.empty()) {
        vector<char> sortedLetters(uniqueLetters.begin(), uniqueLetters.end());
        sort(sortedLetters.begin(), sortedLetters.end(), greater<char>());

        cout << sortedLetters.size() << endl;
        for (char ch : sortedLetters) {
            cout << ch << " ";
        }
    } else {
        cout << "Empty!";
    }

    return 0;
}