#include <iostream>

using namespace std;

int main(){
    const int u = 5;
    long long cubes[u];
    int i, o, g;
    for (i=0; i<u; i++) {
        // o = i + 1;
        // cout << "Enter the side of the cube " << o << ": " << endl;
        cin >> cubes[i]; 
        if (cubes[i] <= 0){
            cout << "ERROR ";
            exit(0);
        }
        if (cubes[i-1] < cubes[i]){
            cout << "LOSS ";
            exit(0);
        } 
        
    }

    cout << "WIN ";
    return 0;
}