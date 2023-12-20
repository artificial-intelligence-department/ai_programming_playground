//тренер слонів 0114
# include <iostream>
#include <algorithm>
using namespace std;  

int main (){
    int n;
    cin >> n;
    long xy[n];
        for (int i=0; i<n; i++){
        cin >> xy[i];
    }
    sort(xy, xy + n);
    cout << xy[n-1]-xy[0];
return 0;
}