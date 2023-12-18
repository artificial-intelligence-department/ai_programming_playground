#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

struct reverseAlphabeticalOrder {
    bool operator()(char a, char b) const {
        return a > b;
    }
};

int main() {
    int strNum, limit;
    cin >> strNum >> limit;
    cin.ignore();

    unordered_map<string, int> occurred;
    set<char, reverseAlphabeticalOrder> resultChars;

    for (int i = 0; i < strNum; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string word;
        while (ss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            occurred[word]++;
        }
    }

    for (const pair<const string, int>& word : occurred) {
        if (word.second >= limit) {
            for (char c : word.first) {
                resultChars.emplace(c);
            }
        }
    }

    if (resultChars.empty()) {
        cout << "Empty!" << endl;
    } else {
        cout << resultChars.size() << endl;
        for (char c : resultChars) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
