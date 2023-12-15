#include <iostream>
using namespace std;

int main()
{
    int n, m;

    cin >> n;
    int firstArr[n];
    for(int i=0; i<n; i++)
    {
        cin >> firstArr[i];
    }

    cin >> m;
    int secondArr[m];
    for(int i=0; i<m; i++)
    {
        cin >> secondArr[i];
    }

    int counter1 = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(firstArr[i] == secondArr[j])
            {
                counter1++;
            }
        }
    }

    int counter2 = n+m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(firstArr[i] == secondArr[j])
            {
                counter2--;
            }
        }
    }

    cout << counter1 << endl << counter2;
    return 0;
}