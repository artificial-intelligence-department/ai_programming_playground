#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, s_compressed;
    cin >> s;

    int count = 1;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
        
        else
        {
            s_compressed += s[i];
            
            if (count > 1)
            {
                s_compressed += to_string(count);
            }
            
            count = 1;
        }
    } 

    cout << s_compressed << endl;

    return 0;
}
