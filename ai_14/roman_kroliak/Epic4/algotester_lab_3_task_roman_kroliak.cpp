#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count = 1;
    vector<int> counts;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == s[i+1])
            count++;
        else {
            counts.push_back(count);
            count = 1;
        }
    }
    string a;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != s[i+1]) a.push_back(s[i]);
    string compressed;
    for (int i = 0; i < a.length(); i++)
    {
        if (counts[i] != 1 && i < counts.size()){
            compressed.push_back(a[i]);
            compressed.append(to_string(counts[i]));
        }
        else compressed.push_back(a[i]);
    }
    cout << compressed;
    return 0;
}