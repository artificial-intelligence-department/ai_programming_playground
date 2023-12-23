#include <iostream>
#include <unordered_set>

int main() {
    int N;
    std::cin >> N;
    std::unordered_set<int> setA;
    for (int i = 0; i < N; ++i) {
        int element;
        std::cin >> element;
        setA.insert(element);
    }

    int M;
    std::cin >> M;
    std::unordered_set<int> setB;
    for (int i = 0; i < M; ++i) {
        int element;
        std::cin >> element;
        setB.insert(element);
    }

    int commonElements = 0;
    for (int element : setA) {
        if (setB.find(element) != setB.end()) {
            commonElements++;
        }
    }

    std::unordered_set<int> unionSet(setA);
    unionSet.insert(setB.begin(), setB.end());
    int uniqueElements = unionSet.size();

    std::cout << commonElements << std::endl;
    std::cout << uniqueElements << std::endl;

    return 0;
}
