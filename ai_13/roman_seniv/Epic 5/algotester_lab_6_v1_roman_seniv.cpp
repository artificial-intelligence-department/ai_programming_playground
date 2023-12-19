#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<string, int> c;
    vector<char> a;

    string combinedText;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;

        for (int j = 0; j < word.length(); j++) {
            word[j] = tolower(word[j]);
        }

        combinedText += word + " ";
        c[word]++;
    }
    unordered_map<char, int> charCount;

    for (char c : combinedText) {
        if (c != ' ') {
            charCount[c]++;
        }
    }

    for (const auto& entry : charCount) {
        cout << "Character: " << entry.first << ", Count: " << entry.second << endl;
    }

    return 0;
}
    
