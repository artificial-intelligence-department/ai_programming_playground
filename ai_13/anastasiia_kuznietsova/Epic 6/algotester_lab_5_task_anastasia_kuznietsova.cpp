#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, x, y;
    cin>>N>>M;
    cin>>x>>y;
    int A[N][M];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            A[i][j]=0;
        }
    }

    int a=x-1;
    int b=y-1;

    int maxA = max(a, N-x)+max(b, M-y);

    for(int i=x-1; i<N; i++)
    {
        for(int j=y - 1; j<M; j++)
        {
            A[i][j]=maxA-abs(i-a)-abs(j-b);
        }
        for (int j=y-1; j>=0; j--)
        {
            A[i][j]=maxA-abs(a-i)-abs(b-j);
        }
    }

    for (int i=x-1; i>=0; i--)
    {
        for (int j=y-1; j<M; j++)
        {
            A[i][j]=maxA-abs(i-a)-abs(j-b);
        }
        for (int j=y-1; j>=0; j--)
        {
            A[i][j]=maxA-abs(a-i)-abs(b-j);
        }
    }

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cout<<A[i][j]<<' ';
        }
        cout<<"\n";
    }

    return 0;
}
