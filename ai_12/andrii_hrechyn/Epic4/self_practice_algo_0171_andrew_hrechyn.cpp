#include<iostream>
#include<cmath>
using namespace std;

int main(){
int n, x1, x2, y1, y2, x1_2, y1_2, sum = 0 ;

cin >> n;
for (int i=0; i < n; i++){
    cin >> x1 >> y1 >> x2 >> y2;
    sum+=sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
cout << sum;
    return 0;
}