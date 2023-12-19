#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
    }

    map<string, int> wordCount;
    set<string> rep;
    set<char> reeesult;

    for (const string& word : words) {
        wordCount[word]++;
        if (wordCount[word] >= k) {
            rep.insert(word);
            for (char c : word) {
                reeesult.insert(c);
            }
        }
    }

    if (rep.empty()) {
        cout << "Empty!";
        return 0;
    }

    vector<char> result(reeesult.begin(), reeesult.end());
    sort(result.rbegin(), result.rend());

    cout << result.size() << endl;
    for (char a : result) {
        cout << a << " ";
    }

    return 0;
}
