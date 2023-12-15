#include <iostream>

using namespace std;

int main(){
    //Блок ініціалізації змінних та масивів
    int N,M,c=0;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
   
    cin>>M;
    int b[M];
    for (int i = 0; i < M; i++)
    {
        cin>>b[i];
    }
    int buf[N];
    for (int i = 0; i < N; i++)
    {
        buf[i]=0;
    }
    //Блок розрахунків
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(a[i]==b[j])
            buf[i]++; 
        }
            
    }
    for (int i = 0; i < N; i++)
    {
        c+=buf[i];
    }
    cout<<"\n";
    cout<<c;
    cout<<"\n";
    cout<<(N+M-c);
      
    return 0;
}