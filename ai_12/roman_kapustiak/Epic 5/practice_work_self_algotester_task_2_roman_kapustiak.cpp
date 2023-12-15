// Вболівальниці
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, z, result = 0;

    cin >> n >> k >> z;
    
    int sectors[n];

    for(int i = 0; i < n; i++)
    {
        cin >> sectors[i];
        sectors[i] *= 2;
    }

    sort(sectors, sectors + n);

    for(int i = 0; i < n; i++)
    {
        if(z < sectors[i])
        {
            break;
        }

        result++;
        z -= sectors[i];
    }

    if(result >= k)
    {
        cout << k;
    }
    else
    {
        cout << result;
    }

    return 0;
}
