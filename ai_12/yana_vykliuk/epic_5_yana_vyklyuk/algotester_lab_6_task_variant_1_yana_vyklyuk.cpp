#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    
    cin >> N >> K;

    vector<string> s;
    set <char> letters;
    unordered_map<string, int> count;

    for (int i = 0; i < N; ++i) 
    {
        string si;
        cin >> si;

        if (si.size() < 1 || si.size() > 10) 
        {
            return 0;
        }

        transform(si.begin(), si.end(), si.begin(), ::tolower);
        s.push_back(si);
        count[si]++;
    }

    for (unordered_map<string, int> :: iterator it = count.begin(); it != count.end(); ++it) 
    {
        if (it -> second >= K) 
        {
            const string& word = it -> first;
            
            for (string::const_iterator charIt = word.begin(); charIt != word.end(); ++charIt) 
            {
                letters.insert(*charIt);
            }
        }
    }

    if (letters.empty()) 
    {
        cout << "Empty!\n";
        return 0;
    }

    cout << letters.size() << "\n";

    for (set <char> :: reverse_iterator it = letters.rbegin(); it != letters.rend(); ++it) 
    {
        cout << *it << ' ';
    }

    cout << '\n';

    return 0;
}
