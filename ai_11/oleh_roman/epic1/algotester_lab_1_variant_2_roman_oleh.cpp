#include <iostream> 

using namespace std; 
 
long long longestleg(long long h[]) { 
    long long longestleg = h[0]; 
    for(int i=1; i<4; i++) { 
        if(h[i] > longestleg) { 
            longestleg = h[i]; 
        } 
    }
    return longestleg; 
} 
 
int main() 
{ 
    long long h[4], d[4]; 
    bool a = false;
 
    for(int i=0; i<4; i++) 
    { 
        cin >> h[i]; 
    } 
    for(int i=0; i<4; i++) 
    { 
        cin >> d[i]; 
    } 
 
    for(int i=0; i<4; i++){
        if(h[i] - d[i] < 0) 
        { 
            cout << "ERROR"; 
            return 0; 
        } 
        h[i] -= d[i];
        if(h[i]  == 0) 
            a = true; 
        if(longestleg(h) >= 2*h[i]) { 
            a = true; 
            } 
        } 

    if (!a) 
    { 
        cout << "YES"; 
    } else { 
        cout << "NO"; 
    }
    return 0;
}
