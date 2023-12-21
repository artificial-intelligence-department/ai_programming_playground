#include <iostream>
#include <vector>
int main()
{
    std::vector<long long int> packs;
    int packNum;
    std::cin >> packNum;
    for (int i = 0; i < packNum; i++)
    {
        int elem;
        std::cin >> elem;
        packs.push_back(elem);
    }
    long long int sum = packs[0];
    for (int i = 1; i < packNum; i++)
    {
        sum += packs[i];
    }
    long long int final = sum - packNum;
    std::cout << final;
}