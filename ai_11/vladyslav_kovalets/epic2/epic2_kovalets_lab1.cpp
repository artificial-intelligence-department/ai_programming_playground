#include <iostream>
using namespace std;

int main()
{
    int size_masiv = 6;
    long long a[size_masiv];
    bool win = 1;
    for (int i = 1; i < size_masiv; i++)
    {
        cin >> a[i];
        if(a[i-1] < a[i] && i != 1)
        {
            cout << "LOSS";
            win = false;
            break;
        }
        if(a[i] <= 0)
        {
            cout << "ERROR";
            win = false;
            break;
        }

    }
    if(  win == true)
    cout << "WIN";
    return 0;
}