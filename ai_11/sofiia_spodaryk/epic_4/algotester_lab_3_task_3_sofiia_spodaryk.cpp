#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int count = 1;
    char letter = s[0];

    for (int i = 1; i <= s.length(); i++)
    {
        if (s[i] == letter)
            count++;
        else
        {
            cout << letter;
            if (count > 1)
                cout << count;

            count = 1;
            letter = s[i];
        }
    }

    return 0;
}
