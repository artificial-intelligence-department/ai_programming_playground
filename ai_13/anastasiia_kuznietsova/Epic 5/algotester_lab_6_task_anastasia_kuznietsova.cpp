#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
    int N, K;
    string s;
    cin>>N>>K;
    
    unordered_map<string, int> times;
    for (int i=0; i<N; i++)
    {
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        times[s]++;
    }
    set <char, greater<char>> M;
    for (const auto &entry : times)
    {
        if (entry.second>=K)
        {
            for (char letter : entry.first)
            {
                M.insert(letter);
            }
        }
    }
    if (M.empty())
    {
        cout<<"Empty!";
        return 0;
    }
    else
    {    
        cout<<M.size()<<"\n";
        for (char letter:M) 
        {
        cout<<letter<<" ";
        }
    }

return 0;
}