#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main()
{
    int N, K;
    string s;
    map<string,int> words;
    map<string, int>::iterator it;
    set<char> letters;
    set<char>::iterator itr;

    cin >> N >> K;

    while(N--)
    {
        cin >> s;

        transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return tolower(c); });
        words[s] += 1;
    }

    for(it=words.begin(); it!=words.end(); ++it)
    {
        if(it->second >= K)
        {
            s = it->first;
            for(int i = 0; i < s.length(); i++)
            {
                letters.insert(s[i]);   
            }
        }
    }

    if(letters.size() < 1)
    {
        cout << "Empty!";
        return 0;
    }

    cout << letters.size() << endl;

    for (itr = letters.end(), itr--;itr != letters.begin(); itr--) {
        cout << *itr << " ";
    }
    cout << *itr;

    return 0;
}
