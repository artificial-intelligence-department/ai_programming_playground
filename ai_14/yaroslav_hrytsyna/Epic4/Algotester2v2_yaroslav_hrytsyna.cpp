#include <iostream>

using namespace std;

int N;
int d1,d2,d3;
int main(){
    cin >> N;
    int a[N];
    int an[N-3];
    
    for (int i=0; i<N; i++){
        cin>> a[i];
    }
    cin >>d1;
    cin >>d2;
    cin >>d3;
    int j=0;
    int c=0;
    for (int i=0; i<N; i++){
        if( a[i]!=d1 && a[i]!=d2 && a[i]!=d3 ){
            an[j]=a[i];
            j++;
        }
        else{
            c++;
        }
    }
    int s[N-c-1];
    if ((N-c)>0){
        cout << N-c-1 <<endl;
        for (int i=1; i<N-c; i++){
            s[i-1]=an[i]+an[i-1];
            cout << s[i-1] <<" ";
        }
    }
    else{
        cout << 0;
    }
}

