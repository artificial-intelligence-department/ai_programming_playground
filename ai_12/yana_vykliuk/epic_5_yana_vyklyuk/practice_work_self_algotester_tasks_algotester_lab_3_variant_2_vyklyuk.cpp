#include <iostream>

using namespace std;

int main()
{
    int N, M;
    int count = 0;
    int unique;
    
    cin >> N;
    int a[N];
    
    for(int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    cin >> M;
    int b[M];
    
    for(int i = 0; i < M; ++i)
    {
        cin >> b[i];
    }

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(a[i] == b[j])
            {
                ++count;
            }
        }
    }

    unique = N + M - count;

    cout << count << endl;
    cout << unique << endl;
    
    return 0;
}
