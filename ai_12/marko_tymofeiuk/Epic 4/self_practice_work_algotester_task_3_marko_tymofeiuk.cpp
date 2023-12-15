#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<long long> zuby, skr;
    long long n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++){
        long long temp;
        std::cin >> temp;
        zuby.push_back(temp);
    }

    for (int i = 0; i < n; i++){
        long long final = 0;
        while (zuby[i] >= k){
            final++;
            i++;
        }
        skr.push_back(final);
        }
    auto result = std::max_element(skr.begin(), skr.end());
    long long maxel = *result;
    std::cout << maxel;

    return 0;
}