#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    map<string, int> wordCount;
    set<string> repeatedWords;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordCount[word]++;
    }

    for (const auto& pair : wordCount) {
        if (pair.second >= K) {
            repeatedWords.insert(pair.first);
        }
    }

    char ordered[26];  
    int orderedSize = 0;

    if (!repeatedWords.empty()) {
        for (const auto& word : repeatedWords) {
            for (const auto& x : word) {
                if (find(ordered, ordered + orderedSize, x) == ordered + orderedSize) {
                    ordered[orderedSize++] = x;
                }
            }
        }

        sort(ordered, ordered + orderedSize, greater<char>());
        cout << orderedSize << endl;

        for (int i = 0; i < orderedSize; ++i) {
            cout << ordered[i] << " ";
        }
    } else {
        cout << "Empty!" << endl;
    }

    return 0;
}