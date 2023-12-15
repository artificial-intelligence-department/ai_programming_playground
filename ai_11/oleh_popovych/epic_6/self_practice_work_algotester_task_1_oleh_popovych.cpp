//
// Created by olehio-p on 12/7/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> array1(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> array1[i];
    }

    int M;
    std::cin >> M;
    std::vector<int> array2(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> array2[i];
    }

    std::sort(array1.begin(), array1.end());
    std::sort(array2.begin(), array2.end());

    std::vector<int> differenceNM;
    std::set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), std::back_inserter(differenceNM));

    std::vector<int> differenceMN;
    std::set_difference(array2.begin(), array2.end(), array1.begin(), array1.end(), std::back_inserter(differenceMN));

    std::vector<int> intersection;
    std::set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), std::back_inserter(intersection));

    std::vector<int> unionSet;
    std::set_union(array1.begin(), array1.end(), array2.begin(), array2.end(), std::back_inserter(unionSet));

    std::vector<int> symmetricDifference;
    std::set_symmetric_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), std::back_inserter(symmetricDifference));

    std::cout << differenceNM.size() << std::endl;
    for (const auto& elem : differenceNM) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << differenceMN.size() << std::endl;
    for (const auto& elem : differenceMN) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << intersection.size() << std::endl;
    for (const auto& elem : intersection) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << unionSet.size() << std::endl;
    for (const auto& elem : unionSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << symmetricDifference.size() << std::endl;
    for (const auto& elem : symmetricDifference) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
