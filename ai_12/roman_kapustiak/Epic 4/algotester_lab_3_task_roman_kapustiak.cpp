#include <iostream>

using namespace std;

int main()
{
    string s;
    char oldLetter;
    int n = 1;

    cin >> s;
    oldLetter = s[0];

    for(int  i = 1; i < s.size(); i++)
    {
        if(oldLetter == s[i])
        {
            n++;
        }
        else
        {
            cout << oldLetter;

            if(n > 1)
            {
                cout << n;
            }

            n = 1;
        }
        
        oldLetter = s[i];
    }

    cout << oldLetter;

    if(n > 1)
    {
        cout << n;
    }

    return 0;
}