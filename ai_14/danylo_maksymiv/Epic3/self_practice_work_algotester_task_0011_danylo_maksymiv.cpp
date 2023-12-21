#include<iostream>

using namespace std;

int main()
{
    long amount_of_packs ,res=0;
    

    cin>>amount_of_packs;
    long amount_of_cookies_in_each_pack[amount_of_packs];
    
    for(int i = 0  ; i<amount_of_packs; i++)
    {
        cin>>amount_of_cookies_in_each_pack[i];
        res += (amount_of_cookies_in_each_pack[i]-1);        
        
    }

    cout<<res;
}