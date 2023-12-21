#include <iostream>
#include <string.h>
#include <cstdarg>
using namespace std;

void Max(char* num, ...);

int main()
{
  Max("56", 4, 99, 1042, 36, 0);
  Max("5.9", 74.4, 14.3, 2.8, 48.4, 561.0, 67.7, 2684.3, 4.2, 61.5, 0 );
  Max("5555.4", 74.4, 14.3, 2.8, 48.4, 561.0, 67.7, 2684.3, 4.2, 61.5, 680.2, 66.1, 0);
  return 0;
}

void Max(char* num, ...)
{
  va_list ap;
  va_start(ap, num);
  if (strchr(num, '.') != NULL)
  {
    double arg;
    double max;
    sscanf(num, "%lf", &max);
    while ((arg = va_arg(ap, double)) != 0)
    {
      if (max < arg)
      {
        max = arg;
      }
  
    }
    cout << "Max number (type double) = " << max << endl;
  }
  else if (strchr(num, '.') == NULL)
  {
    int arg;
    int max;
    sscanf(num, "%d", &max);
    while ((arg = va_arg(ap, int)) != 0)
    {
      if (max < arg)
      {
        max = arg;
      }
    }
    cout << "Max number (type int) = " << max << endl;
  }
  va_end(ap);
}