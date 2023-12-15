#include <iostream>
#include <math.h>
using namespace std;

int main() {

double n, m;
cout << "Enter n=";
cin >> n;

cout << "Enter m=";
cin >> m;

double result = n++>m;
cout << "result is " << result << endl;

return 0;

}
