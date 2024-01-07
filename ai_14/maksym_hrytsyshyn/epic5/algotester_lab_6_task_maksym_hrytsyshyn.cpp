#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<string> s(N);
    unordered_map<string, int> amount;
    for (int a=0; a<N; ++a) {
        cin >> s[a];
        transform(s[a].begin(), s[a].end(), s[a].begin(), [](unsigned char letter) { return tolower(letter); });
        ++amount[s[a]];
    }

    set<char, greater<char>> uniques;
    for(const pair<const string, int>&eachmeet : amount) {
        if(eachmeet.second >= K) {
            for (char letter : eachmeet.first) {
                uniques.insert(letter);
        }
    }
    }

    int M = uniques.size();

    if (!uniques.empty()) {
        cout << M << endl;
        for (auto letters : uniques) {
            cout << letters << " ";
        }
    } else {
        cout << "Empty!" << endl;
    }

    return 0;
}