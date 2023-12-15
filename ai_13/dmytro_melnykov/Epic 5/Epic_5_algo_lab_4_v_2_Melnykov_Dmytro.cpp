#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  // видалити з масиву a всі дублікати за допомогою set`.
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  set<int> uniqueSet(a.begin(), a.end());
  a.assign(uniqueSet.begin(), uniqueSet.end());

 

  sort(a.begin(), a.end());  // Сортувати масив



  // Обернути масив на кількість K
  swap_ranges(a.begin(),a.begin(),a.end());
  rotate(a.begin(), a.begin() + K % a.size(), a.end());


  // Вивести результат

  cout << a.size() << endl;
  for (int i : a) { //вивід кожного елементу а
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
