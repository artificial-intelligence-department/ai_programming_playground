#include <iostream>
#include <vector>

int main() {
    long N;
    std::cin >> N;
    std::vector<long> r(N);

    for (long i = 0; i<N; i++) { std::cin >> r[i]; } 

    long del[3];
    std::cin >> del[0] >> del[1] >> del[2];

    for (auto currentCheck : del) {
        for (long currentDelete = 0; currentDelete < r.size(); currentDelete++) {
            if (currentCheck == r[currentDelete]) { r.erase(r.begin() + currentDelete); break;}
        }
    }

    for (long sum = 0; sum < ((long)(r.size()) - 1); sum++) {
        r[sum] += r[sum+1];
    }

    if (r.size()) r.pop_back();
    std::cout << r.size() << std::endl; 
    for (auto print : r) { std::cout << print << ' '; }
    return 0;
}