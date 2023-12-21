#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, m;

int main()
{
    cin >> N;

    if (N < 1)
    {
        return 0;
    }
    else if (N==1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    vector <int> r;

    for (int i=0; i<N; ++i)
    {
        int number;
        cin >> number;
        r.push_back(number);
    }
    
    sort(r.begin(), r.end());
    
    if (r[N-1] - r[1] > r[N-2] - r[0])
    {
        m = r [N-2] - r[0];
    }
    else
    {
        m = r[N-1] - r[1];
    }

    cout << m << endl;

    return 0;
}
