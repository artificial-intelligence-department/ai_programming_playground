#include<iostream>
using namespace std;

int main(){
    int N, M, i, j;
    int scoreSimultaneously = 0;
        cin>>N;
    int arrayN[N];
    for(i=0;i<N;i++)
        cin>>arrayN[i];

        cin>>M;
    int arrayM[M];
    for(i=0;i<M;i++)
        cin>>arrayM[i];

    for(j=0;j<N;j++){
        for (i=0;i<M;i++){
            if(arrayN[j]==arrayM[i])
                scoreSimultaneously++;
        }
    }

    int scoreTogether = N+M - scoreSimultaneously;
        cout<<scoreSimultaneously<<"\n";
        cout<<scoreTogether;
return 0;
}