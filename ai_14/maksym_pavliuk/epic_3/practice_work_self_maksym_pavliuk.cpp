#include <iostream>
using namespace std;

int main() {
    int teeth_count;
    int K;

    cin >> teeth_count >> K;
    int teeth_coefs[teeth_count];

    for (int i = 0; i < teeth_count; i++) {
        cin >> teeth_coefs[i];
    }

    int cool_teeth = 0;
    int max_cool_teeth = 0;

    for (int i = 0; i < teeth_count; i++) {
        if (teeth_coefs[i] >= K) {
            cool_teeth++;
        } else {
            max_cool_teeth = max(max_cool_teeth, cool_teeth);
            cool_teeth = 0;
        }
    }

    max_cool_teeth = max(max_cool_teeth, cool_teeth);

    cout << max_cool_teeth << endl;

    return 0;
}
