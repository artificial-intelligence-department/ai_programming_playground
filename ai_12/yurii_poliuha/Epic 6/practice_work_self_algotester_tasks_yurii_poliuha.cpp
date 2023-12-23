#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int limit(){
    int a;
    cin >> a;
    while(true){
        if(a >= 1 && a <= pow(10, 5)) break;
        else cin >> a;
    }
    return a;
}

int LimitOfArray(){
    int a;
    cin >> a;
    while(true){
        if(a >= 0 && a <= pow(10, 5)) break;
        else cin >> a;
    }
    return a;
}

int main(){
    int N, result;
    N = limit();
    vector<int> r(N);

    for(int i = 0; i < N; i++){
        r[i] = LimitOfArray();
    }
    sort(r.begin(), r.end());

    int Max, Min, index_max, index_min;
    Max = r[0];
    Min = r[0];
    for(int i = 0; i < N; i++){
        if(Max < r[i]){
            Max = r[i];
            index_max = i;
        }
        if(Min > r[i]){ 
            Min = r[i];
            index_min = i;
        }
    }

    if(N == 1) result = 0;
    else result = min(Max - r[1], r[N - 2] - Min);
    cout << result;
    
    return 0;
}