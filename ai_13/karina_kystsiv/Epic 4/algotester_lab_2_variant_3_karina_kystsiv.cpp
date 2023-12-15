#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> mass(N);
    for(int i=0; i<N; i++){
        cin >> mass[i];
    }
    int left = 0, right = N-1;
    while(true) {
        if(left == right) {
            cout << left+1 << " " << right+1 << endl;
            cout << "Collision" << endl;
            break;
        }
        else if(left > right) {
            cout << left+1 << " " << right+1 << endl;
            cout << "Miss" << endl;
            break;
        }
        else if( left == right - 1) {
            cout << left+1 << " " << right+1 << endl;
            cout << "Stopped" << endl;
            break;
        }
            left += mass[left];
        right -= mass[right];}

    return 0;
}