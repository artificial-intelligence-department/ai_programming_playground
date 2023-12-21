#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; 
    cout << "enter size of ring: ";
    cin >> n;

    vector<int> ring(n);
    cout << "enter elements of ring: ";
    for (int i = 0; i < n; ++i) {
        cin >> ring[i];
    }

    int k;
    cout << "enter K: ";
    cin >> k;

    //підмасив від K до K+1
    cout << "subarray from k to k+1 ";
    for (int i = k; i <= k + 1; ++i) {
        cout << ring[i % n] << " ";
    }
    cout << endl;

    // Сортування у спадаючому порядку
    std::sort(ring.rbegin(), ring.rend());

    // Видалення непарних елементів
    ring.erase(std::remove_if(ring.begin(), ring.end(), [](int x) { return x % 2 != 0; }), ring.end());

    // Вивід кільцевого масиву від K до K+1 після видалення непарних елементів
    std::cout << "Після видалення непарних елементів: ";
    for (int i = k; i <= k + 1; ++i) {
        std::cout << ring[i % ring.size()] << " ";
    }
    std::cout << std::endl;

    return 0;
}
