#include <iostream>

using namespace std;

int main () {
    
    unsigned long long h [4];
    unsigned long long d [4];
    unsigned long long hmin = 0;
    unsigned long long hmax = 0;


    for (int i=0; i<4; i++) { 
        cin >> h[i]; 
    }
    
    for (int j=0; j<4; j++) {
        cin >> d[j];
    }
        
    for (int i = 0; i < 4; i++) {
        if (d[i]>h[i]) {
            cout << "ERROR";
            return 0;
        }   
    }

    hmin = h[0];
    
    for (int l=0; l<4; l++) {
            
        h[l]=h[l]-d[l];

        if (hmin>h[l]) {
            hmin=h[l];
        }

        hmax = h[0];

        for(int k = 0; k < 4; k++) {
            if (hmax < h[k]) {
                hmax = h[k];
            }
        }

        if (hmin<=hmax/2) {
            cout << "NO";
            return 0;
        }
    }

    if (h[0]==h[1] && h[1]==h[2] && h[2]==h[3] && h[0]!=0 && hmin>hmax/2) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    
} 