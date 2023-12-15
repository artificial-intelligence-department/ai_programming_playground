#include <iostream>

using namespace std;

int n;
long sum;
long a;

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if (a > 1)
        {
            sum += (a - 1);
        }
        else
        {
            sum += 0;
        }

    }

    cout << sum << endl;
    
    return 0;
}
