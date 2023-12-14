#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

int main()
{
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251); // для виводу українською
 double money;
 cout << "Введіть дробове число: " << endl;
  cin >> money;
  double fraction;
  double integer;
  fraction = modf(money, &integer); // для розбиття на цілу та дробову частини

  cout << integer << " грн." << " " << (fraction * 100) << " коп." << endl;

  return 0;

}
