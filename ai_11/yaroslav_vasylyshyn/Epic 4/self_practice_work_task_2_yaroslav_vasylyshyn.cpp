#include <iostream>

using namespace std;

int main(){
    int N,M;
    cin>>N;
    M=N;
    cout<<"Введіть елементи матриці:"<<'\n';
    int a[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Трикутна матриця має вигляд:"<<'\n';
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M-i; j++)
        {
            a[i-1][j]=0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<'\n';
    }
    
    return 0;
}