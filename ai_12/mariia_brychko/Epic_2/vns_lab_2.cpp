#include <iostream>
using namespace std;
int main () {
int n = 1;
double E = 0.0001;                                                               
double a1 = 10.0;                                                                  //перший член ряду
double an = 10.0;
double sum = 10.0;                                                                 //сума ряду
int fact = 1;
for (n = 1; an >= E ; n++)
{
  fact *= n;
  an = 10.0/fact;
  sum += an;                                                              //an1 = 10/(n+1)*an;
}
cout << "The sum of elements = " << sum << endl;
    return 0;
}





