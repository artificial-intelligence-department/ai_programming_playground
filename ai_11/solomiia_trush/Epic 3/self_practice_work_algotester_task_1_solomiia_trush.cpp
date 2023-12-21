#include <iostream>
using namespace std;

int main() {
    long pachky=0, shavaty=0;

    cin >> pachky;
    long pechenky[pachky];

    for (long i=0; i<pachky; i++) {
        cin >> pechenky [i];
    }
    
    for (long j=0; j<pachky; j++) {
        shavaty += pechenky[j];
    } 

    shavaty -= pachky;
    cout << shavaty;
     

}