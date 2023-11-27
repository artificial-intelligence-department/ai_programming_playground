#include <iostream>

using namespace std;

int main(){
long long sum = 0, n, x;

cin >> n;

for(int i = 0; i < n; i++){
    cin >> x;
    sum += x - 1;
}
cout << sum;

    return 0;
}