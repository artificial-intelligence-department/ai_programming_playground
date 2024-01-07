#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    if (n == 1) 
        cout << "0";
    else {
        sort(array.begin(), array.end());
        if ( n == 2 )
            cout << array[0];
        else if (array[1] - array[0] > array[n - 1] - array[n - 2]) 
            cout << array[n - 1] - array[1] ;
        else 
            cout << array[n - 2] - array[0] ;
    }
    return 0;
}