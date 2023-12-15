#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cookies(n);

    for (int i = 0; i < n; i++) {
        cin >> cookies[i];
    }

    sort(cookies.begin(), cookies.end());

    int max_cookies = 0;

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            max_cookies += cookies[i];
        } else {
            max_cookies += min(cookies[i], cookies[i + 1]);
            i++; // Пропускаємо наступну пачку печива, бо Марічка не може взяти з неї
        }
    }

    cout << max_cookies << endl;

    return 0;
}
