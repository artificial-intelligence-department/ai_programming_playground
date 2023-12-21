#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<string, int> c;
    vector<char> k;
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        for (int j=0; j<word.length(); j++) {
            word[j]= tolower(word[j]);
        }
        c[word]++;
    }
    for (auto n = c.begin(); n != c.end(); n++) {
    const auto& entry = *n;
    if (entry.second >= K) {
        string word = entry.first;
        for (auto it = word.begin(); it != word.end(); ++it) {
            char f = *it; 
            if (find(k.begin(), k.end(), f) == k.end()){
                k.push_back(f);
            }
        }
    }
}
    if (k.empty()) {
        cout << "Empty!";
    } else {
        cout<<k.size()<<endl;
        sort(k.begin(), k.end(), greater<char>());
        for (int i=0; i<k.size(); i++) {
            cout << k[i]<< " ";
        }
    }
    return 0;
}
