#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long packs;

    cin >> packs;
    std::vector<long long> cookies(packs);
    for (long long i = 0; i < packs; i++) {
        std::cin >> cookies[i];
    }

    long long can_eat = 0;
    for (long long i = 0; i < packs; i++)
    {
        long long max = cookies[i] - 1;
        can_eat += max;
    }
    
    cout << can_eat;

    return 0;
}
