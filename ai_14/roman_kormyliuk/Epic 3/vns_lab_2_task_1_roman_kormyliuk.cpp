#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double fn = 1, f2n = 1, sum = 0, e = 0.0001;
    int n, k;
    cin >> n;
    //cin >> e;
    for (int i = 1; i <= n; i++){
        fn = 1;
        f2n = 1;
        k = i;

    for (int i = 1; i <= k; i++){
        fn *= i; 
    }
    for (int i = 1; i <= k*2; i++){
        f2n *= i;
    }
    double formule = (fn / f2n);
    cout << formule << " ";
    if (formule < e){
        sum += formule;
    }
    }
cout << "\nСума ряду з точністю e: " << sum << endl;

return 0;
}