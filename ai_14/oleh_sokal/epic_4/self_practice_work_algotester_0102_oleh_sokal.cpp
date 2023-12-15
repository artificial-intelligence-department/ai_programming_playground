#include <iostream>
using namespace std;

int main() {
    int n, m, s, placeOfMid, rightPart;
    cin >> n >> m >> s;
    int arr[1000] = {0};

    placeOfMid = n / 2 + 1;
    rightPart = n - placeOfMid;
    
    for (int i = rightPart; i < n; ++i) {
        s += arr[i];
    }
    arr[placeOfMid] = m;
  if ((s-m) < (rightPart * arr[placeOfMid])) {
        cout << "-1";  
        return 0;
    }
    


    for (int i = placeOfMid; i < n; i++) {
        arr[i-1] = m;
        s -= m;
    }
    
  
    arr[n - 1] = s;  

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " "; 
    }

    return 0;
}