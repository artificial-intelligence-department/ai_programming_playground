#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long int h[4], d[4];

int main() {
     for(int i = 0; i < 4; ++i){
        cin >> h[i];
    }

    for (int i = 0; i < 4; ++i) {
        cin >> d[i];
    }

    long int n = sizeof(h) / sizeof(h[0]);

    bool fell = false;
    for (int i = 0; i < 4; ++i) {
        h[i] -= d[i];
        if (*max_element(h, h+n) >= 2 * *min_element(h, h+n)){
            fell = true;
        }
    }

    if (*min_element(h, h+n) < 0){
        cout << "ERROR" << endl;
    }
    else if(!fell && *min_element(h, h+n) > 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}