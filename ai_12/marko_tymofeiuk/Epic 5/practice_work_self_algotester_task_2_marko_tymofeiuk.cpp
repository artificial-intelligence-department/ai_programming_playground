#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<long long> cats;
    size_t n;
    std::cin >> n;

    for (int i = 0; i < n; i++){
        long long temp;
        std::cin >> temp;
        cats.push_back(temp);
    }

    auto mincat = std::min_element(cats.begin(), cats.end());
    auto maxcat = std::max_element(cats.begin(), cats.end());
    auto catmin = *mincat;
    auto catmax = *maxcat;
    auto result = catmax - catmin;

    std::cout << result;
}