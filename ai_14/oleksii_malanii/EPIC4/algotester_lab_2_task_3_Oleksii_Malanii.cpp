#include <iostream> 
using namespace std; 
int main(){ 
    int a; 
    cin >> a; 
    int* m = new int[a]; 
    for (int i = 0; i < a; i++){ 
        cin >> m[i]; 
    } 
    int l = 1; 
    int r = a; 
    while(true){ 
        if (r == l){ 
            cout << l << " " << r << endl; 
            cout << "Collision"; 
            break; 
        } 
        else if (r == l + 1){ 
            cout << l << " " << r << endl; 
            cout << "Stopped"; 
            break; 
        } 
        else if (r < l){ 
            cout << l << " " << r << endl; 
            cout << "Miss"; 
            break; 
        } 
        l = l + m[l - 1]; 
        r = r - m[r - 1]; 
 
    } 
}