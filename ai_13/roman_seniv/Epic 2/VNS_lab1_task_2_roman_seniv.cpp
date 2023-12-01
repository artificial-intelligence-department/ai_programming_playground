#include <iostream>
#include <cmath>
using namespace std;

int main(){
double n, m;
cout << "Enter n:";
cin >> n;
cout << "Enter m:";
cin >> m;
cout << (++n-m) <<endl; 
cout << (--m > n) <<endl;
cout << (--n > m) <<endl;


    return 0;
}
