#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> r(N);
    for (int i = 0; i < N; i++) {
        std::cin >> r[i];
    }
    
    int a, b, c;
    std::cin >> a >> b >> c;
    
    // Видалення чисел a, b, c з масиву
    for (int i = 0; i < r.size(); i++) {
        if (r[i] == a || r[i] == b || r[i] == c) {
            r.erase(r.begin() + i);
            i--; // Зменшуємо індекс, оскільки ми видалили елемент з масиву
        }
    }
    
    std::vector<int> sumArray;
    for (int i = 1; i < r.size(); i++) {
        int sum = r[i - 1] + r[i];
        sumArray.push_back(sum);
    }
    
    std::cout << sumArray.size() << std::endl;
    
    for (int i = 0; i < sumArray.size(); i++) {
        std::cout << sumArray[i] << " ";
    }
    
    return 0;
}