#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    int array[100]; 
    for (int i=0; i<N; ++i) {
        cin >> array[i];
    }

    int drone1=1, drone2=N;

    while (drone1<=N && drone2>=1) {
        if (drone1==drone2) {
            cout << drone1 << " " << drone2 << endl;
            cout << "Collision";
            break;
        } else if (drone1>drone2) {
            cout << drone1 << " " << drone2 << endl;
            cout << "Miss";
            break;
        } else if ((abs(drone1-drone2)==1)) {
            cout << drone1 << " " << drone2 << endl;
            cout << "Stopped";
            break;
        }

        drone1 += array[drone1-1];
        drone2 -= array[drone2-1];
    }
    return 0;
}

