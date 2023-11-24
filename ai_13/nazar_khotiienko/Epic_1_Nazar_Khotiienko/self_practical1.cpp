#include <iostream>
#include <cstdlib>
#include <cmath>

int main()
{
  using namespace std;

  double a = 0, b = 0;
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;

  cout.precision(2); // кількість знаків після коми
  cout << "a to b power  = " << pow(a, b) << endl;
  return 0;
}