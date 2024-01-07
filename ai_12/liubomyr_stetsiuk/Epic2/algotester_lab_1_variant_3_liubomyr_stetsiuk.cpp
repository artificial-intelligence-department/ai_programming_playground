#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  long long int a[5];
  for (int i = 0; i < 5; i++)
  {
    cin >> a[i];
    if (a[i] <= 0)
    {
      cout << "ERROR" << endl;
      return 0;
    }
  }

  long long int top = a[0];
  for (int i = 1; i < 5; i++)
  {
    if (a[i] >= pow(10, 12))
    {
      cout << "Number is too large! \n";
      return 0;
    }
    if (a[i] > top)
    {
      cout << "LOSS" << endl;
      return 0;
    }
    top = a[i];
  }

  cout << "WIN" << endl;
  return 0;
}
