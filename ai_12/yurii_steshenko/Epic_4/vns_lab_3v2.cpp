#include <iostream>
#include <set>

using namespace std;

int main()
{
  int n, m;
  cin >> n;
  set<int> a;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.insert(x);
  }

  cin >> m;
  set<int> b;
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    b.insert(x);
  }

  // Кількість елементів, які наявні в обох масивах одночасно.

  size_t count = 0;
  for (int x : a)
  {
    count += b.count(x);
  }

  // Кількість унікальних елементів в обох масивах.

  size_t unique_count = a.size() + b.size() - count;

  cout << count << endl;
  cout << unique_count << endl;

  return 0;
}