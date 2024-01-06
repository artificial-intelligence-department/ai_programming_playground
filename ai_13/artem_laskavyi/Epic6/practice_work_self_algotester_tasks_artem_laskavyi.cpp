#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n, m, candle; // m - pumpkins, n - candles
    cin >> m >> n;
    vector<int> a;
    
    for(int i = 0; i < n; i++){
        cin >> candle;
        a.push_back(candle);
    }

    long double low = 0, high = *max_element(a.begin(), a.end()), mid = 0, mid_prev = 0;
    int count = 0;
    long double epsilon = 0.00000001;
    mid = (high + low) / 2;
    
    do{   
        mid_prev = mid;
        count = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > mid) {
                count += floor(a[i]/mid);
            }
        }

        if (count < m) {
            high = mid;
        }else{
            low = mid;
        }
        
        mid = (high + low) / 2;

    }while (abs(mid_prev - mid) > epsilon);

    printf("%.10Lf", mid);

    return 0;
}
