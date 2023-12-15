#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

string to_lower(string str) {
    for (char& c : str)
        c = tolower(c);
    return str;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> words(n);

    // first value in pair is a word
    // second value in pair is the count of word occurrences
    map<string, int> words_count;

    set<char> charset;

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        // normalize word (to upper case would be fine too)
        words[i] = to_lower(words[i]);
        words_count[words[i]]++;
    }

    for (const auto& pair : words_count)
        if (pair.second >= k)
            for (char c : pair.first)
                charset.insert(c);

    if (charset.empty()) {
        cout << "Empty!";
        return 0;
    }

    cout << charset.size() << endl;
    for(auto it = charset.rbegin(); it != charset.rend(); ++it)
        cout << *it << " ";

    return 0;
}
