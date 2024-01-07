#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct office {
    int index;
    int length;
};
bool compOffices(const office& a, const office& b) {
    return a.length < b.length;
}
int main() {
    int n;
    cin >> n;
    vector<office> offices(n);
    for (int i = 0; i < n; ++i) {
        cin >> offices[i].length;
        offices[i].index = i + 1;
    }
    sort(offices.begin(), offices.end(), compOffices);
    for (int i = 0; i < n; ++i) {
        cout << offices[i].index << " ";
    }
    return 0;
}
