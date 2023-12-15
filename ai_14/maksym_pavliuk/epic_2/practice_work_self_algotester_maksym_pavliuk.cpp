#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    long a[n];
    long result=0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cin.ignore(1, ' ');
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i] > 1){
            result += a[i] - 1;
        }
    }

    cout << result;
    return 0;
}
