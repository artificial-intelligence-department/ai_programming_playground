#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
 int N = 0;
 int K = 0;
 cin >> N >> K;

 vector<int> a(N);

 for (int i = 0; i < N; ++i)
 {
  cin >> a[i];
 }

 sort(a.begin(), a.end());
 a.erase(unique(a.begin(), a.end()), a.end());

 K %= a.size();

 rotate(a.begin(), a.begin() + K, a.end());

 cout << a.size() << endl;

 for (int i : a)
 {
  cout << i << " ";
 }

 return 0;

}
