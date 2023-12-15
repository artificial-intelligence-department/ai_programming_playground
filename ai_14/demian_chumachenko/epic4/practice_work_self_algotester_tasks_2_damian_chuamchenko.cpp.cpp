#include <iostream>

using namespace std;

int main(){
    int n, k, max_el = 0, el = 0;
    cin >> n >> k;

    int *a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= k){
            el += 1;
            if(el > max_el){
                max_el = el;
            }
        }
        else{
            el = 0;
        }
    }

    cout << max_el;
    delete[] a;
    return 0;
}