#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    short n,k,mx,m_index;
    std::cin >> n >> k;
    std::vector<short> a(n);
    for (short i = 0; i<n; i++) { std::cin >> a[i]; }
    std::sort(a.begin(), a.end());
    mx = a[n-1];
    std::unique(a.begin(), a.end());
    for (short i=0; i<n; i++) {if(a[i] == mx) {m_index = i+1; break;}}
    a.resize(m_index);
    for (short i = 0; i<k; i++) {
        std::rotate(a.begin(), a.begin() + 1, a.end());
    }
    std::cout << a.size() << std::endl;
    for (short i = 0; i<a.size(); i++) {std::cout << a[i] << ' ';}
    return 0;
}