#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool sort(char a, char b) {
    return a > b;
}

int main() {
    int N, K, m = 0;
    std::cin >> N >> K;
    std::string t, res;
    std::vector<std::string> s;
    std::unordered_map<std::string, int> map;

    for (int i = 0; i < N; i++) {
        std::cin >> t;
        std::transform(t.begin(), t.end(), t.begin(), ::tolower);
        s.push_back(t);
        map[t]++;
    }

    for (int i = 0; i < N; i++) {
        int count = map[s[i]];
        if (count >= K) {
            m += count;
            res += s[i];
        }
    }

    std::sort(res.begin(), res.end());
    auto last = std::unique(res.begin(), res.end());
    res.erase(last, res.end());

    std::sort(res.begin(), res.end(), sort);

    if (m >= K) {
        std::cout << res.size() << std::endl;
        for (auto ch : res) {
            std::cout << ch << " ";
        }
    } else {
        std::cout << "Empty!";
    }

    return 0;
}
