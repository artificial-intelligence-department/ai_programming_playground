#include <iostream>
using namespace std;
#include <string>

int main()
{
    int n;
    cin>>n;
    string s ;
    cin>>s;
    
    int signal=15;
    for(auto i = s.begin(); i != s.end(); i++) 
    {
   
 
        if (*i=='k')
        {
            signal--;
        }
        else if(*i=='p')
        {
            if(signal>=1)
            {
                signal=15;
            }
            else if(signal==0) 
            {
                signal=0;
            }
        else if(*i=='z')
        {
            if(signal>=1)
            {
                signal=0;
            }
            else if(signal==0) 
            {
                signal=15;
            }
        }
    }

}
    cout<<signal;
}