#include <iostream>  
using namespace std; 

int main() { 
    long long h[4], max_h, min_h; 
    for(int i = 0; i < 4; i++) 
        cin >> h[i]; 
 
    long long d[4];  
    for(int i = 0; i < 4; i++) 
        cin >> d[i]; 
 
 
    for(int i = 0; i < 4; i++) { 
        if(d[i] > h[i]) { 
            cout << "ERROR" << endl; 
            return 0; 
        } 
    } 
 
    for(int i = 0; i < 4; i++) { 
        h[i] -= d[i]; 
        max_h = h[0], min_h = h[0]; 
        for(int j = 0; j < 4; j++) { 
            if(h[j] > max_h) 
                 max_h = h[j]; 
 
            if(h[j] < min_h) 
                min_h = h[j]; 
        } 
 
        if(max_h >= 2 * min_h) { 
            cout << "NO" << endl; 
            return 0; 
        } 
    } 
 
    if(h[0] == h[1] && h[1] == h[2] && h[2] == h[3] && h[0] != 0) { 
        cout << "YES" << endl; 
    } else{ 
        cout << "NO" << endl; 
    } 
    return 0; 
}
