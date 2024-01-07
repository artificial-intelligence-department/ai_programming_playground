#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, a, b, c, N2 = 0, M;
    cin >> N;
    vector<int> r(N);
    vector<int> r2;
    vector<int> r3;
    for (int i = 0; i < N; ++i)
    {
        cin >> r[i];
    }
    cin >> a >> b >> c;
    for (int i = 0; i < N; ++i)
    {
        if (r[i] != a && r[i] != b && r[i] != c)
        {
            r2.push_back(r[i]);
            ++N2;
        }
    }
    for (int i = 0; i < N2 - 1; ++i)
    {
        r3.push_back(r2[i] + r2[i + 1]);
    }
    M = r3.size();
    cout << M << endl;
    for (int i = 0; i < M; ++i)
    {
        cout << r3[i] << " ";
    }

    return 0;
}