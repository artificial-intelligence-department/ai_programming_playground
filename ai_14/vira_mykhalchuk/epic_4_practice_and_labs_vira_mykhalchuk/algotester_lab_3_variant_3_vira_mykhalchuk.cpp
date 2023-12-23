#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string s;
    cin >> s;

    char current = s[0];
    int count = 1;

    for (int i = 1; i < s.size(); ++i) 
    {
        if (s[i] == current) 
        {
            count++;
        } 
        else 
        {
            cout << current;
            
            if (count > 1) 
            {
                cout << count;
            }
            
            current = s[i];
            count = 1;
        }
    }

    cout << current;
    if (count > 1) 
    {
        cout << count;
    }

    return 0;
}