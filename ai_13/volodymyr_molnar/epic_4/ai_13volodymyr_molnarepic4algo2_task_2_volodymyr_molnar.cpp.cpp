#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; ++i)
        cin >> r[i];

    int a, b, c;
    cin >> a >> b >> c;

    r.erase(remove(r.begin(), r.end(), a), r.end());
    r.erase(remove(r.begin(), r.end(), b), r.end());
    r.erase(remove(r.begin(), r.end(), c), r.end());
    if (r.empty()) {
        cout << "0\n";
        return 0;
    }
    vector<int> sumArray;
    for (int i = 0; i < r.size() - 1; ++i)
        sumArray.push_back(r[i] + r[i + 1]);

    cout << sumArray.size() << "\n";
    for (int i = 0; i < sumArray.size(); ++i)
        cout << sumArray[i] << " ";

    return 0;
}
