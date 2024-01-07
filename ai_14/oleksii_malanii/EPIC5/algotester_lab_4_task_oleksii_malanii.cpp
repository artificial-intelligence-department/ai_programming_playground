#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a;
    cin >> a;
    int n[a];
    for (int i = 0; i < a; i++) {
        cin >> n[i];
}
auto two = partition(n, n + a, [](int num) { return num % 3 == 0; });
auto two_num = partition(two, n + a, [](int num) { return num % 3 == 1; });
sort(n, two);
    sort(two, two_num, greater<int>());
        sort(two_num, n + a);
auto lastl = unique(n, n + a);
auto sizenew = distance(n, lastl);
cout << sizenew << endl;
for (auto i = n; i != lastl; i++)
{
    cout << *i << " ";
}
return 0;
}   
