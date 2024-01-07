#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
 srand(time(NULL));

 vector<int> a(100);

 cout << "Original array: " << endl;
 for (int i = 0; i < 10; ++i)
 {
  a[i] = rand() % 16;
  cout << a[i] << " ";
 }
 cout << endl;

 a.erase(remove(a.begin(), a.end(), 0), a.end());

 for (int i = 1; i < a.size(); ++i)
 {
  if (a[i] % 2 == 0)
  {
   a.insert(a.begin() + i + 1, a[i - 1] + 2);
   break;
  }
 }


 cout << "Final array: " << endl;

 for (int k : a)
 {
  cout << k << " ";
 }


 return 0;

}
