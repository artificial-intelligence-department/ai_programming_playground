#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(){
    std::vector<int> nvector;
    int n, k;
    std::cin >> n >> k;

    for (int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        nvector.push_back(temp);
    }

    std::sort(nvector.begin(), nvector.end());
    auto iter = std::unique(nvector.begin(), nvector.end());
    nvector.resize(std::distance(nvector.begin(), iter));

    std::rotate(nvector.begin(), nvector.begin() + (k % nvector.size()), nvector.end());

    std::cout << nvector.size() << std::endl;

    for (int elem : nvector){
        std::cout << elem << " ";
    }

    return 0;
}