#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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

    for (auto pair : wordCount) {
        if (pair.second >= K) {
            repeatedWords.insert(pair.first);
        }
    }
    vector<char> sorted;
    if (!repeatedWords.empty()) {
        for (auto word : repeatedWords) {
            for (auto x : word) {
                sorted.push_back(x);
            }
        }
        
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        reverse(sorted.begin(), sorted.end());
        cout << sorted.size() << endl;

        for (auto c : sorted) {
            cout << c << " ";
        }
        cout << endl;
    } else {
        cout << "Empty!" << endl;
    }

    return 0;
}
