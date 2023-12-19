#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void del(vector <int>& a, int& n){
    int j = 0;
    vector <int> b;
    for(int i = 0; i < n; i++){
        if(a[i] != a[i+1]){
            b.push_back(a[i]);
            j++;
        }
    }
    
    n=j;
    a.clear();
    for(int i=0; i<n; i++){
        a.push_back(b[i]);
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    del(arr, n);

    cout << n << endl;

    if(k>arr.size()){
        k=k % arr.size();
    }

    rotate(arr.begin(), arr.begin()+k, arr.end());

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
