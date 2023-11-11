#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int main(){
    int N,i,min;
    cout << "Write the numbers in the array\"r\":";
    cin >> N;
     while(N<1 || N>pow(10,5)) {
        cout << "It's the wrong numbers in the array\"r\":";
        cout << "Write the numbers in the array\"r\":";
        cin >> N;
    }
    int r[N-1];
    for (int i = 0; i < N; i++)
    {
        cout << "Write element " << i+1 << " in the array\"r\":";
        cin >> r[i];
        
        while(r[i]<0 || r[1]>pow(10,5)){
        cout << "It's the wrong numbers in the array\"r\":";
        cout << "Write element " << i+1 << " in the array\"r\":";
        cin >> r[i];
    }
    }
    sort(r, r + N);
    if(r[N-2] - r[0] < r[N-1] - r[1]){
        min=r[N-2] - r[0];
    }else{
        min=r[N-1] - r[1];
    }

    cout << min;
    return 0;
    
}