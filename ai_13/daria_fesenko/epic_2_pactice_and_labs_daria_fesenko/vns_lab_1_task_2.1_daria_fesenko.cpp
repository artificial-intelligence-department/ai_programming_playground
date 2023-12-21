#include <iostream>
#include <math.h>
using namespace std;

int main() {

float n, m;
cout << "Enter n=";
cin >> n;

cout << "Enter m=";
cin >> m;

float result = ++n * ++m;
cout << "result is " << result << endl;

return 0;

}
