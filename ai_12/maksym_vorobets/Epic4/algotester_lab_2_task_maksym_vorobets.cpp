#include <iostream>
using namespace std;

int main(){
    unsigned N, a, b, c;
    cin>>N;
    unsigned r[N];
    for(int i=0; i<N; i++){
        cin>>r[i];
    }
    cin>>a>>b>>c;
     int N1 = 0;
    for (int i = 0; i < N; i++) {
        if (r[i] != a && r[i] != b && r[i] != c) {
            r[N1] = r[i];
            N1++;
        }}
        if(N1>0){
            N1--;
            }else;
        for(int i=0; i<N1; ++i){
            r[i]=r[i]+r[i+1];
        }
        cout<<N1<<endl;
        for (int i = 0; i < N1; ++i){
            cout<<r[i]<<endl;
        }
    return 0;
}