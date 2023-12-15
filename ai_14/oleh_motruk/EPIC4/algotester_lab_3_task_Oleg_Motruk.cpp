#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n , m , common , unique ,  result;
    common = 0;
    unique = 0;
    cin >> n;
    vector<int> array1(n);
        for (int i = 0; i < n; i++){
            cin >> array1[i];
        }
    cin >> m;
    vector<int> array2(m);
    for (int i = 0; i < m; i++){
            cin >> array2[i];
        }
    sort(array1.begin() , array1.end());
    sort(array2.begin() , array2.end());

    int i = 0 , j = 0;

    while(i < n && j < m){
        if (array1[i] == array2[j]){
            common++;
            i++;
            j++;
        }
        else if (array1[i] < array2[j]){
            i++;
        }
        else
            j++;
    }
    cout << common << endl;
    cout << n + m - common;

    return 0;
}