#include <iostream>
#include <algorithm>
using namespace std;

int main() {
int n,m;
cin >> n >> m;
int a[n]; // мішок Зеника
int b[m]; // мішок Марійчки

for(int i=0; i<n; ++i) {
cin >> a[i];
}
for(int i=0; i<m; ++i) {
  cin >> b[i];
}

int min_cost_zen = *min_element(a, a+n);
int min_cost_mari = *min_element(b, b+m);

int sum = min_cost_zen + min_cost_mari;

cout << sum << endl;

return 0;
}
