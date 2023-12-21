#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    int counter1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                counter1++;
                break;
            }
        }
    }
    cout << counter1 << endl;
    
    int counter2 = n + m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                counter2--;
                break;
            }
        }
    }
    cout << counter2 << endl;

    return 0;
}
