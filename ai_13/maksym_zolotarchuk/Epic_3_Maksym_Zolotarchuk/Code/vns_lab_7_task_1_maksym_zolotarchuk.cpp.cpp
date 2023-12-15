#include <iostream>
#include <cmath>
#include <cstdarg>
using namespace std;

int sum(int count, ...)
{
 va_list args;
 va_start(args, count);

 int x = 0;
 for (int i = 0; i < count; ++i)
 {
  x += va_arg(args, int);
   
 }
 va_end(args);

 return x;
}

int main()
{
 cout << sum(3, 1, 2, 3) << endl;
 cout << sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
    cout << sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;
 return 0;
}