#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int r[N];
    for (int i=0; i<N; ++i){
    cin>>r[i];
    }
    sort(r, r+N);
    int min = r[N-1] - r[1];
    int f = r[N-2] - r[0];
        if(f < min){
            min = f;
        }
    if(N == 1){
        min = 0;
    }
    if(N == 2){
       min = r[0];
    }
    cout<<min;
}
