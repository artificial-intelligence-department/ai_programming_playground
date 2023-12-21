#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string s, s_compressed;
    cin>>s;
    int number=1;

    for (int i=1; i<=s.size(); i++)
    {
        
       if (s[i]==s[i-1]) 
        {
            number++;
        }
        else
        {
            s_compressed+=s[i-1];
            if(number>1)
            {
            s_compressed+=to_string(number);
            }

            number=1;
        }
    }

    cout<<s_compressed;

    return 0;
}
