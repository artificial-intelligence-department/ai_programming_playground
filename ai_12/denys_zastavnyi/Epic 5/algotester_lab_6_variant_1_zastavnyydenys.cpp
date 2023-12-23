#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool sortZA(char a, char b) {
    return a > b;
}

int main() {
    int wordCount, minWordCount, totalOccurrence = 0;
    cin >> wordCount >> minWordCount;

    string currentWord, result;
    vector<string> words;
    unordered_map<string, int> wordOccurrences;

    for (int i = 0; i < wordCount; i++) {
        cin >> currentWord;
        transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);
        words.push_back(currentWord);
        wordOccurrences[currentWord]++;
    }

    for (int i = 0; i < wordCount; i++) {
        int count = wordOccurrences[words[i]];
        if (count >= minWordCount) {
            totalOccurrence += count;
            result += words[i];
        }
    }

    sort(result.begin(), result.end());
    auto last = unique(result.begin(), result.end());
    result.erase(last, result.end());

    sort(result.begin(), result.end(), sortZA);

    if (totalOccurrence >= minWordCount) {
        cout << result.size() << endl;
        for (auto character : result) {
            cout << character << " ";
        }
    } else {
        cout << "Empty!";
    }

    return 0;
}
