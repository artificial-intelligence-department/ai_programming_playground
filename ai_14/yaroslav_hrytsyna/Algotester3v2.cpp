#include <iostream>
#include <algorithm>

using namespace std;

int N,M;

int main(){
    cin >> N;
    int a[N];
    for (int i=0; i<N; i++){
        cin>> a[i];
    }
    cin >> M;
    int b[M];
    for (int i=0; i<M; i++){
        cin>> b[i];
    }
    int u=0;
    int c=0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if(a[i] == b[j]){
                c++;
            }
        }
    }
    u=N+M-c;
    cout << c << endl;
    cout << u;
}