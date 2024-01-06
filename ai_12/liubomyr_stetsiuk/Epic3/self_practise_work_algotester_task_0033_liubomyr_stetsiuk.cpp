#include <iostream>
#include <vector>

int main()
{
    unsigned long sum = 0;
    unsigned long n, k;
    std::cin >> n >> k;

    std::vector<unsigned long> kk(n), nn(k);
    for (unsigned long i = 0; i < n; ++i)
    {
        std::cin >> kk[i];
    }
    for (unsigned long i = 0; i < k; ++i)
    {
        std::cin >> nn[i];
    }
    for (unsigned long i = 0; i < n; i++)
    {
        std::sort(nn.begin(), nn.end(), std::greater<unsigned long>());
        std::sort(kk.begin(), kk.end(), std::greater<unsigned long>());
        std::cout << std::endl;
        sum += kk[0] * nn[0];
        nn[0] -= 1;
        kk.erase(kk.begin());
    }
    std::cout << sum << std::endl;
    return 0;
}
