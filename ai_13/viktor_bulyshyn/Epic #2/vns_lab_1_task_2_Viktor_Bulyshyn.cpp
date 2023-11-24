#include <cmath>
#include <iostream>

using namespace std;

int main(){

float n;
float m;

cout << " Enter num1 " << endl;
cin >> n;
cout << " Enter num2 " << endl;
cin >> m;

float a = --m-++n;
float b = m*n<n++;
float c = n-->m++;

cout <<"Result is:"<< endl << a << endl << b << endl << c << endl;

return 0;





}