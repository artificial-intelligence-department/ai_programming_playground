#include <iostream>
using namespace std;

int main(){
    long int n, k, quantity = 0, max = 0; //кількість зубів та межа загостреності
    cin >> n >> k;

    long int a[n] = {0};
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        if (a[i]>=k){
            quantity++;
            continue;
        }
        if (quantity > max){
            max = quantity;
        }
        quantity = 0;
    }
    if (quantity > max){
        max = quantity;
    }
    cout << max;
    return 0;
}
