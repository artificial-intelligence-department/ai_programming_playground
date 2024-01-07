#include <iostream>
#include <cmath>
#include <vector>

bool IsInCircle(double x, double y, double R) {
    double distance = sqrt(x * x + y * y);
    return distance <= R;
}

int n(double R, const std::vector<std::pair<double, double>>& points) {
    int count = 0;
    for (const auto& point : points) {
        if (IsInCircle(point.first, point.second, R)) {
            count++;
        }
    }
    return count;
}

int main() {
    double radius = 5.0;

    std::vector<std::pair<double, double>> points1 = { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} };
    int count1 = n(radius, points1);
    std::cout << "Кількість точок з координатами (х,у), що належать кругу: " << count1 << std::endl;

    std::vector<std::pair<double, double>> points2 = { {0.5, 1}, {3.5, 4.2}, {5.6, 15}, {1.8, 7}, {4.9, 2.1} };
    int count2 = n(radius, points2);
    std::cout << "Кількість точок з координатами (х,у), що належать кругу: " << count2 << std::endl;

    std::vector<std::pair<double, double>> points3 = { {0.2, 1.5}, {3.7, 4.9}, {1, 1}, {1.3, 0.9}, {4.2, 2.8}, {1.1, 5.5} };
    int count3 = n(radius, points3);
    std::cout << "Кількість точок з координатами (х,у), що належать кругу: " << count3 << std::endl;

    return 0;
}
