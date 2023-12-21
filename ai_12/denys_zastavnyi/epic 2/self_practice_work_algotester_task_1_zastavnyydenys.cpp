#include<iostream>
using namespace std;

int main() {
   long long int n, a;
   long long int totalCookies = 0;


    cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a;
            totalCookies += (a - 1);
        }
        cout << totalCookies << endl;
    return 0;
}