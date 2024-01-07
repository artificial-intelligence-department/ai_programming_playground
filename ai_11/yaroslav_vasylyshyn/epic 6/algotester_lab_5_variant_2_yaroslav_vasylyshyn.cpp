#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;

int main(){
    int N,M,buf = 1;
    cin>>N>>M;
    char cave[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>cave[i][j]; 
        }
    }
    for (int i = N-2; i >= 0; i--)
    {
        for (int j = 0; j < M; j++)
        {
            if(cave[i][j] == 'S')
            {
                while(true)
                {
                    if(cave[i + buf][j] == 'X')
                    {
                        swap(cave[i][j], cave[i+buf-1][j]);
                        goto checkpoint;
                    }
                    if(cave[i + buf][j] == 'S')
                    {
                        swap(cave[i][j], cave[i+buf-1][j]);
                        goto checkpoint;
                    }
                    if(i + buf == N)
                    {
                        swap(cave[i][j], cave[i+buf-1][j]);
                        goto checkpoint;
                    }
                    buf++;
                }
                swap(cave[i][j], cave[i+buf-1][j]);
                checkpoint:
                buf=1;
            } 
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout<<cave[i][j];
        }
        cout<<'\n'; 
    }
    return 0;
}