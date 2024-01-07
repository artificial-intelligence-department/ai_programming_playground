#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, x;

void BubbleSort (int n, unsigned int rr[]) {
    for (int j=0; j<n; j++) {
        for (int w=0; w<n-1; w++) {
            if (rr[w] > rr[w+1]) {
                x = rr[w];
                rr[w] = rr[w+1];
                rr[w+1] = x;
            }
        }
    }
}

int main () {
    cin >> n;

    unsigned int r[n];
    unsigned int rr[n];

    for (int i=0; i<n; i++) {
        cin >> r[i];
    }

    for (int k=0; k<n; k++) {
        rr[k]=r[k];
    }

    if (n==1) {
        cout << 0;
        return 0;
    }

    BubbleSort(n, rr);

    int min_f = rr[n-2] - rr[0];
    int min_l = rr[n-1] - rr[1];
    int position = -1;

    if (min_f<min_l) {
        cout << min_f;
    } else {
        cout << min_l;
    }

}