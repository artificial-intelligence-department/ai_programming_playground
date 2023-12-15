// Варіант 16

#include <iostream>
using namespace std;
int main(){
    int n, m, sum;
    printf("Enter n: ");
    cin  >> n;
    printf("Enter m: ");
    cin  >> m;
    sum = ++n * ++m;
    --n, --m;
    cout << "++n*++m = " << sum << endl;
    if (m++ < n){
        cout << "m++ < n" << endl;
    }
    else{
        cout << "m++ >= n" << endl;
    }
    --m;
    if (n++ > m){
        cout << "n++ > m";
    }
    else{
        cout << "n++ <= m";
    }
    --n;
    return 0;
}
