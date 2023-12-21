// 0891
// Хелловін

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> zeniksCandies(n);
    vector<int> marichkasCandies(m);

    for (int i = 0; i < n; ++i) {
        cin >> zeniksCandies[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> marichkasCandies[i];
    }

    sort(zeniksCandies.begin(), zeniksCandies.end());
    sort(marichkasCandies.begin(), marichkasCandies.end());

    int giftCost = zeniksCandies[0] + marichkasCandies[0];

    cout << giftCost << endl;

    return 0;
}
