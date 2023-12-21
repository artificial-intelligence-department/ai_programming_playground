#include <iostream>

using namespace std;
int main()
{
  long long int h,m,hi,mi;
  bool flag = true;
  cin >> h >> m;
  for(int i = 0; i<3;i++)  {
    cin >> h >> m ;
    if( h>0 & m>0)
        flag = false;
    h -= hi; 
    m -= mi;
  }
  if (n>0 & m>0 & flag)
    cout << "YES";
  else 
    cout << "NO";
  return 0;
}