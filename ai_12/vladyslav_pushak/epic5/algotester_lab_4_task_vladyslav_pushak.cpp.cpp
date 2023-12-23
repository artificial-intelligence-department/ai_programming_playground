#include <iostream>
#include <algorithm>
#include <vector>

void printVector(const std::vector<int>& vec) {
    std::cout << vec.size() << std::endl;
    for (const auto& el : vec) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main() {
    using namespace std;

    int N, M;

    cin >> N;
    vector<int> arrayN(N);
    for (auto& el : arrayN) {
        cin >> el;
    }

    cin >> M;
    vector<int> arrayM(M);
    for (auto& el : arrayM) {
        cin >> el;
    }

    sort(arrayN.begin(), arrayN.end());
    sort(arrayM.begin(), arrayM.end());

    vector<int> differenceNM;
    set_difference(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), back_inserter(differenceNM));
    printVector(differenceNM);

    vector<int> differenceMN;
    set_difference(arrayM.begin(), arrayM.end(), arrayN.begin(), arrayN.end(), back_inserter(differenceMN));
    printVector(differenceMN);

    vector<int> intersection;
    set_intersection(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), back_inserter(intersection));
    printVector(intersection);

    vector<int> Union;
    set_union(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), back_inserter(Union));
    printVector(Union);

    vector<int> symmetricDifference;
    set_symmetric_difference(arrayN.begin(), arrayN.end(), arrayM.begin(), arrayM.end(), back_inserter(symmetricDifference));
    printVector(symmetricDifference);
}
