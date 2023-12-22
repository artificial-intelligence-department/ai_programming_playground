#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    map<string, int> wordCount;
    set<char> uniqueLetters;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;

        transform(word.begin(), word.end(), word.begin(),
                  [](unsigned char c) { return tolower(c); });

        wordCount[word] += 1;
    }

    for (auto& word : wordCount) {
        if (word.second >= K) {
            for (char letter : word.first) {
                uniqueLetters.insert(letter);
            }
        }
    }

    if (uniqueLetters.empty()) {
        cout << "Empty!";
        return 0;
    }

    cout << uniqueLetters.size() << endl;

    for (auto it = uniqueLetters.rbegin(); it != uniqueLetters.rend(); ++it) {
        cout << *it << " ";
    }

    return 0;
}