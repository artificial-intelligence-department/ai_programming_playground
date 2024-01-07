#include <iostream>
#include <cmath>
using namespace std;

int main(){
int m, n;
cout <<"Type number for n: \n";
cin >> n;
cout <<"Type number for m: \n";
cin >> m;
cout << "Answer 1: " << m-(++n) << "\n"; 
cout << "Answer 2: " << boolalpha << ((++m)>(--n)) << "\n";
cout << "Answer 3: " << boolalpha << ((--n)<(++m)) << "\n";
return 0;
}