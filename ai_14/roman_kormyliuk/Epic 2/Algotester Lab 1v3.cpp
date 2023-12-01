#include <iostream>

using namespace std;

int main() {
    const int a = 5;
    long long cubes[a]; // обмеження − −10^12≤ai≤10^12
    for (int b = 0; b < a; b++) {
        int c = b + 1;
        cin >> cubes[b];
        if (cubes[b] <= 0) {
            cout << "Error ";
            exit(0); 
        }
        int d = b - 1;
        if ( cubes[d] < cubes[b]) {
            cout << "loss ";
            exit(0); 
        }
    }
    cout << "win ";
    return 0;
}