#include<iostream>

using namespace std;

int main(){
    unsigned N, M;
    cin>>N;
    int a[N];
    for (int i=0 ; i < N; i++)
    {
        cin>>a[i];
    }
    cin>>M;
    int b[M];
     for (int i=0 ; i < M; i++)
    {
        cin>>b[i];
    }
    int v=0;
    for(int i=0 ; i < N; i++){
       
    int k=a[i];
    for(int j=0 ; j < M; j++){
        if(k==b[j]){
            v++;
        }
    }}
    int h=0;
    h=(M+N)-v;
      
    cout<<v<<endl;
    cout<<h<<endl;
    return 0;
    
}