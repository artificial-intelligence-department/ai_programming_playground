#include<iostream>

using namespace std;

int main(){
    short N, M;
    cin>>N>>M;
    char row[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>row[i][j];
        }
    }

     for (int j=0; j<M; j++){
        int mx=N-1;
        for(int i=N-1; i>=0; i--){
         if(row[i][j]=='S'){
            if(mx>i){
                row[mx][j]='S';
                row[i][j]='O';
                mx--;
            }else{
                mx=i-1;
            }
         }else if(row[i][j]=='X'){
            mx=i-1;
         }
        }
    }
  for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<row[i][j];}
            cout<<endl;}
    return 0;
}
