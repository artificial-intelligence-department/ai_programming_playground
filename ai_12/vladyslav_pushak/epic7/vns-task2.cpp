#include <iostream>
#include <vector>

int main() {
    std::vector<std::pair<double, double>> points = {
        // приклад 10 точок
        {1, 2}, {3, 4}, {-1, 2}, {-3, -4}, {1, -2},
        {3, -4}, {-1, -2}, {-3, 4}, {1, 2}, {3, 4}
    };

    int quadrant_counts[4] = {0, 0, 0, 0};

    for (const auto& point : points) {
        if (point.first > 0 && point.second > 0) {
            quadrant_counts[0]++;
        } else if (point.first < 0 && point.second > 0) {
            quadrant_counts[1]++;
        } else if (point.first < 0 && point.second < 0) {
            quadrant_counts[2]++;
        } else if (point.first > 0 && point.second < 0) {
            quadrant_counts[3]++;
        }
    }

    int max_quadrant = 0;
    for (int i = 1; i < 4; i++) {
        if (quadrant_counts[i] > quadrant_counts[max_quadrant]) {
            max_quadrant = i;
        }
    }

    std::cout << "Answer " << max_quadrant + 1 << std::endl;

    return 0;
}
