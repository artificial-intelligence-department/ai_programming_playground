#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    std::vector<std::vector<int>> masive(3);

    for (int i = 0; i < N; ++i) {
        int remainder = arr[i] % 3;
        masive[remainder].push_back(arr[i]);
    }

    std::sort(masive[0].begin(), masive[0].end());
    std::sort(masive[1].begin(), masive[1].end(), std::greater<int>());
    std::sort(masive[2].begin(), masive[2].end());

    std::vector<int> fin_array;

    for (const auto& m : masive) {
        for (int num : m) {
            if (std::find(fin_array.begin(), fin_array.end(), num) == fin_array.end()) {
                fin_array.push_back(num);
            }
        }
    }

    std::cout << fin_array.size() << std::endl;

    for (int num : fin_array) {
        std::cout << num << " ";
    }

    return 0;
}
/*9
0 6 33 7 4 1 2 5 8
*/

