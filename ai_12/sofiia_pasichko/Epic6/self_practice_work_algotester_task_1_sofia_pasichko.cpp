#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int k, n;
    cin >> k >> n;
    int *prices = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    sort(prices, prices+n);
    int numberOfAttractions=0;
    for (int i = 0; i < n; ++i) {
        k=k-prices[i];
        if (k>=0) {
            numberOfAttractions++;
        }
        else { 
            k=k+prices[i];
        }
    }
    cout << numberOfAttractions;
    delete[] prices;
    return 0;
}