#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<long long> legs(4), cuts(4);

    for (int i = 0; i < 4; i++) {
        cin >> legs[i];
    }
    
    bool error = false ;
    bool flip = false ; 
    for (int i = 0; i < 4; i++) {
        cin >> cuts[i]; 
        legs[i] -= cuts[i];

        if (*max_element(legs.begin(), legs.end()) >= 2 * *min_element(legs.begin(), legs.end())) {
            flip = true;
        }
        
        if (legs[i] < 0) {
            error = true;
        }
    }

    if (!flip & !error & *max_element(legs.begin(), legs.end()) == *min_element(legs.begin(), legs.end())) {
        cout << "YES" << endl;
    } 
    else if (error){
        cout << "ERROR" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
