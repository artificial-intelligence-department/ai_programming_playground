#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string remove(string str) {
    int length = str.length();
    if (length <= 1) {
        return str; 
    }

    int index = 0; 
    for (int i = 1; i < length; ++i) {
        if (str[index] != str[i]) {
            str[++index] = str[i]; 
        }
    }
    return str.substr(0, index + 1); 
}

int main() {
    int N, K;
    cin >> N >> K;

    unordered_map<string, int> count; 

    string list;
    for (int i = 0; i < N; i++) {
        cin >> list;
        transform(list.begin(), list.end(), list.begin(), ::tolower);
        count[list]++;
    }

    vector<string> count_Words; 

    for (const auto &pair : count) {
        if (pair.second >= K) {
            count_Words.push_back(pair.first);
        }
    }

    if (count_Words.empty()) {
        cout << "Empty!";
        return 0;
    }

    sort(count_Words.begin(), count_Words.end());

    string list_String;
    for (const string &word : count_Words) {
        list_String += word;
    }

    sort(list_String.rbegin(), list_String.rend());

    string result = remove(list_String); 

    cout << result.size() << endl;
    for (char ch : result) {
        cout << ch << " ";
    }
    
    return 0;
}