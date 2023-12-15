#include <iostream>

using namespace std;

int main(){
    int N,M,max=0;
    cin>>N>>M;
    int a[N][M];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>a[j][i];
        }
    }
    int b[N-1];
    for (int i = 1; i <= N-1; i++)
    {
        b[i-1]=0;
        for (int j = 0; j < M-i; j++)
        {
            b[i-1] += a[i-1][j];
        }
    }

    for (int i = 0; i < N-1; i++)
    {
        if (max<b[i])
        {
            max=b[i];
        }
    }
    cout<<max;
    
    return 0;
}