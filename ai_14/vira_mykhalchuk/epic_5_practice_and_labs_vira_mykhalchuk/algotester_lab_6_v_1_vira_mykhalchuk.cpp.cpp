#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<string, int> wordCount;
    set<char> repeatedLetters;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;

        for (char& c : word) {
            c = tolower(c);
        }

        if (++wordCount[word] == K) {
            for (char c : word) {
                repeatedLetters.insert(c);
            }
        }
    }

    if (repeatedLetters.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << repeatedLetters.size() << endl;

        for (auto it = repeatedLetters.rbegin(); it != repeatedLetters.rend(); ++it) {
            cout << *it << ' ';
        }
        cout << endl;
    }

    return 0;
}