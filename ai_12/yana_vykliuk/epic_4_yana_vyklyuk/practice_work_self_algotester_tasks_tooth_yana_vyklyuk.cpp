#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long k;
int n, counter;
vector <long long> a;
vector <int> c;

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        long long ai;
        cin >> ai;
        a.push_back(ai);
    }
    
    for (int j = 0; j < n; j++)
    {
        if (a[j]>=k)
        {
            counter++;
        }
        else
        {
            counter = 0;
        }
        c.push_back(counter);
    }

    sort(c.begin(), c.end());
    
    cout << c[n-1] << endl;

    return 0;
}
