#include <stdio.h>
#include <iostream> 

using namespace std;

int main() {
    int a;
    int b;
    int c;
    cin >> a >> b >> c;

    int sum;
    sum = a+b;

    if (sum > c) {
        cout << "YES";
    }

    else {
        cout << "NO";
    }
return 0;
}