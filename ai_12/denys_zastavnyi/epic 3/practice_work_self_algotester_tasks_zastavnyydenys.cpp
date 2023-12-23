#include <iostream>
using namespace std;

int main() {
    int price;
    cin >> price;
    int count = 0;
    int denominations[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};


    for (int i = 0; i < 9; ++i) {
        int currentCount = price / denominations[i];
        
        count += currentCount;
        price -= currentCount * denominations[i];
    }

    cout << count << endl;

    return 0;
}