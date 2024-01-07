#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    map<string, int> words;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
            return tolower(c);
        });

        words[input]++;
    }

    map<char, int> output;
    for (auto& word : words) {
        if (word.second >= k) {
            for (char c : word.first) {
                output[c]++;
            }
        }
    }

    if (output.empty()) {
        cout << "Empty!";
        return 0;
    }


    vector<char> chars;
    cout << output.size() << endl;
    for(auto& c : output) {
        chars.push_back(c.first);
    }

    for(int i = chars.size()-1; i >= 0; i--)
    {
        cout << chars[i] << ' ';
    }

    return 0;
}