#include <iostream>
using namespace std;

int main()
{
    long long a[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        if (a[i] <= 0) 
        {
            cout << "ERROR";
            return 1;
        }
        
        if (i > 0) 
        {
            if (a[i] > a[i-1])
            {
                cout << "LOSS";
                return 2;
            }
            
        }
    }
    cout << "WIN";
    
    return 0;
}