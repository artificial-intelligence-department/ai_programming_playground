#include <iostream>
using namespace std;

int main()
{
    int N, M, repeatable = 0, unigue;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    cin >> M;
    int b[M];
    for (int i = 0; i < M; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i] == b[j])
            {
                repeatable++;
                break;
            }
        }
    }
    cout << repeatable << endl << M + N - repeatable;
}