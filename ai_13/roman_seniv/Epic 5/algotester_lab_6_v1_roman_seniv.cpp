#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<string, int> wordCount;
    vector<string> words;
    
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;

        transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordCount[word]++;
        words.push_back(word);
    }

    sort(words.begin(), words.end());

    string repChars;

    for (vector<string>::iterator i = words.begin(); i != words.end(); i++) {
        int counter = 1;

        if (*i == "") {
            continue;
        }

        for (vector<string>::iterator j = i + 1; j != words.end(); j++) {
            if (i != j && *i == *j) {
                counter++;
                *j = "";
            } else if (i != j && *j != *(j - 1)) {
                break;
            }
        }

        if (counter >= K) {
            repChars.append(*i);
        }
    }

    sort(repChars.begin(), repChars.end(), greater<char>());
    vector<char> uniqueChars;

    for (size_t i = 0; i < repChars.length(); i++) {
        if (repChars[i] != repChars[i + 1]) {
            uniqueChars.push_back(repChars[i]);
        }
    }

    if (uniqueChars.empty()) {
        cout << "Empty!";
    } else {
        cout << uniqueChars.size() << endl;
        for (char &ch : uniqueChars) {
            cout << ch << " ";
        }
    }

    return 0;
}
