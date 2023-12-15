#include <iostream>
#include <vector>
#include <numeric>
#include <random>

int main() {
    std::vector<int> Numbers;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 10);

    while(Numbers.size() < 10) {
        int num = distr(gen);
        Numbers.push_back(num);

    }

    std::cout << "The numbers are: ";
    for(int n : Numbers) {
        std::cout << n << " ";
    }

    double avg = std::accumulate(Numbers.begin(), Numbers.end(), 0.0) / Numbers.size();
    std::cout << "The arithmetic mean is: " << avg << std::endl;

    return 0;
}