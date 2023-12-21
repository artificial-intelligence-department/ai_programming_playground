#include <iostream>
using namespace std;
int main ()
{

long long int h1=0, h2=0, h3=0, h4=0;
long long int d1=0, d2=0, d3=0, d4=0; 
cin >> h1;
cin >> h2;
cin >> h3;
cin >> h4;

cin >> d1;
cin >> d2;
cin >> d3;
cin >> d4;

long long int t1 = h1 - d1;
long long int t2 = h2 - d2;
long long int t3 = h3 - d3;
long long int t4 = h4 - d4;

if (t1 < 0 || t2 < 0 || t3 < 0 || t4 < 0) 
{
cout << "ERROR";
} else if (t1 <= h2 / 2 || t2 <= h3 / 2 || t3 <= h4 / 2 ) 
{
cout << "NO";
}

else if (t1 == t2 && t2 == t3 && t3 == t4 && t1 > 0 && t2 > 0 && t3 > 0 && t4 > 0) 
{
cout << "YES";
}
else 
{
   cout << "NO"<<endl;
}

return 0;
}