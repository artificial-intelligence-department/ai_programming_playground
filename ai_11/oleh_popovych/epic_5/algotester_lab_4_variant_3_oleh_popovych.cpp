//
// Created by olehio-p on 12/7/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

bool comparator(int, int);

int main(int argc, char const *argv[])
{
    int N;
    std::cin >> N;

    std::vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }

    const std::vector<int>::iterator &partitionIt =
                                        std::partition(numbers.begin(), numbers.end(),
                                        [](int num) {
                                            return num % 3 == 0;
                                        });


    std::sort(numbers.begin(), partitionIt, comparator);
    std::sort(partitionIt, numbers.end(), comparator);


    const std::vector<int>::iterator &uniqueIt =
                                        std::unique(numbers.begin(), numbers.end());
    numbers.erase(uniqueIt, numbers.end());

    std::cout << numbers.size() << std::endl;
    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
bool comparator(int a, int b) {
    if (a % 3 != b % 3) {
        return a % 3 < b % 3;
    }

    if (a % 3 == 0) {
        return a < b;
    } else if (a % 3 == 1) {
        return a > b;
    }

    return a < b;
}
