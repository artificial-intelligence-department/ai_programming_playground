#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int N;
    std::cin >> N;


    std::vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> r[i];
    }

    std::sort(r.begin(), r.end());

   
    int min;

    if (N == 1 || r[0] == r[N - 2] || r[1] == r[N - 1]) {
        min = 0;
    } else {
    
        min = std::min(r[N - 2] - r[0], r[N - 1] - r[1]);
    }   

    std::cout << min << std::endl;

    return 0;
}
