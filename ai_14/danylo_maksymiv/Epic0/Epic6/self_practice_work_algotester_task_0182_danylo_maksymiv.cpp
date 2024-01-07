#include <iostream>
using namespace std;

int main()
{
    int teeths,i = 0;
    long long k, currentStreak = 0 , maxStreak = 0;;

    cin>>teeths;
    cin>>k;

    long long a[teeths];

    for(i = 0; i<teeths; i++)
    {
        cin>>a[i];
        if (a[i] >= k) 
        {
            ++currentStreak;
            if (currentStreak > maxStreak) {
                maxStreak = currentStreak;
            }
        } 
        else {
            currentStreak = 0;
        }
    }
    
    cout<<maxStreak;
}