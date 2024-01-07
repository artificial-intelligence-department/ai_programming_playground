#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    unordered_map<string, int> word_count;
    unordered_map<char, int> letter_count;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word_count[word]++;
    }
    for (const auto& entry : word_count) {
        if (entry.second >= K) {
            const string& word = entry.first;
            set<char> unique_letters(word.begin(), word.end());
            for (char letter : unique_letters) {
                letter_count[letter] += entry.second;
            }
        }
    }
    vector<char> valid_letters;
    for (const auto& entry : letter_count) {
        if (entry.second >= K) {
            valid_letters.push_back(entry.first);
        }
    }
    sort(valid_letters.rbegin(), valid_letters.rend());
    if (valid_letters.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << valid_letters.size() << endl;
        for (char letter : valid_letters) {
            cout << letter << " ";
        }
        cout << endl;
    }
    return 0;
}
