#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int k, n, s;
//money = k ; ride = n ; price = cj ; s = rides Marichka can ride on
    cin>>k>>n; //number of hryvnias and number of amusement rides
    if (k<1||n<1||k>100||n>100)
    {
        return 0;
    }
    vector<int> cj(n);
    for (int j=0; j<n; j++)
    {
        cin>>cj[j]; //the price of the amusement ride
        if (1>cj[j] || cj[j]>100)
        {
            return 0;
        }
    }
    sort(cj.begin(), cj.end());
    for(int j=0; j<n; j++)
    {
        if (k>=cj[j])
        {
            k-=cj[j];
            s++;
        }
        else
        {
            break;
        }
    }
    cout<<s; //the total number of rides Marichka can ride on
return 0;
}