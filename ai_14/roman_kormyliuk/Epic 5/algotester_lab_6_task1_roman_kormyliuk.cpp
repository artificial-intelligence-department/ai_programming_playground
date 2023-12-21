#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
string removeDuplicates(const string &str) {
    string result;
    for (char ch : str) {
        if (result.find(ch) == string::npos) {
            result += ch;
        }
    }
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

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

    if (frequentWords.empty()) {
        cout << "Empty!";
        return 0;
    }

    sort(frequentWords.begin(), frequentWords.end());

    string resultString;
    for (const string &word : frequentWords) {
        resultString += word;
    }

    sort(resultString.rbegin(), resultString.rend());

    string result = removeDuplicates(resultString);

    cout << result.size() << endl;
    for (char ch : result) {
        cout << ch << " ";
    }

    return 0;
}
