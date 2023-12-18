#include<iostream>
using namespace std;

int main() {
    int n, n1=0;
    cin >> n;  
    
    int money[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    while (n > 0) {
        for (int i = 0; i < 9; i++) {
            if (n >= money[i]) {
                n -= money[i];
                n1++;
                break;
            }
        }
    }

    cout << n1 << endl;

    return 0;
}  
