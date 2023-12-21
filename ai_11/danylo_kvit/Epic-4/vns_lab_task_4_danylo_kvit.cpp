#include <iostream>
using namespace std;
void show(int a[], int n,int k){
    for(int i=0;i<n;i++){
        cout << a[(i+k)%n] << ' ';
    }
    cout << '\n';
}
int main(){
    int n;
    cout << "array size";
    cin >> n;
    int* a = new int[n];
    for(int i=0;i<n;i++) cin >> a[i];
    cout << "k : ";
    int k;
    cin >> k;
    k--;
    show(a, n, k);
    a[n] = a[0];
    int* b = new int[(n+2)/2];
    a[n+1] = a[n-1];
    for(int i=0;i<(n+2)/2;i++){
        b[i] = a[2*i];
    }
    delete[] a;
    a =  b;
    n = (n+2)/2;
    show(b,n,k);
    return 0;
}