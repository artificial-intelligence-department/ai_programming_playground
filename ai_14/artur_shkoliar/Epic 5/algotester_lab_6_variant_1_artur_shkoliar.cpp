#include <iostream>
#include <map>
#include <set>
#include <algorithm>

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

    for (const auto& pair : wordCount) {
        if (pair.second >= K) {
            repeatedWords.insert(pair.first);
        }
    }

    char sorted[26];  
    int sortedSize = 0;

    if (!repeatedWords.empty()) 
    {
        for (const auto& word : repeatedWords) 
        {
            for (const auto& x : word) 
            {
                if (find(sorted, sorted + sortedSize, x) == sorted + sortedSize) 
                {
                    sorted[sortedSize++] = x;
                }
            }
        }

        sort(sorted, sorted + sortedSize, greater<char>());
        cout << sortedSize << endl;

        for (int i = 0; i < sortedSize; ++i) 
        {
            cout << sorted[i] << " ";
        }
        cout << endl;
    } 
    else 
    {
        cout << "Empty!" << endl;
    }

    return 0;
}
