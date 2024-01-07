#include <bits/stdc++.h>  
#include <cctype>
using namespace std;  
void SplitStr(string str)
{
    string s = "";
    for (auto x : str)
    {
        if (x == ' '|| x=='.')
        {   
            for (auto y : s) {
            if (isdigit(y)) {
            cout << s << endl;
                break;
                
            }
        
        }

            s = "";
        }
        else {
            s = s + x;
        }
    }
    for (auto y : s) {
            if (isdigit(y)) {
            cout << s << endl;
                break;
            }
    }
}
 
int main()
{
    string str ;
    getline(cin,str);
    SplitStr(str);

}