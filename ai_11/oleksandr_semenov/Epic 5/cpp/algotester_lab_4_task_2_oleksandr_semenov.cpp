#include <iostream>
#include <vector>

void customSort(std::vector<int>& a) {
    int n = a.size();

    // Реалізація сортування (можна використовувати будь-які алгоритми сортування)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                // Обмін елементів, якщо вони в неправильному порядку
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void customRemoveDuplicates(std::vector<int>& a) {
    int n = a.size();
    int newSize = 0;

    // Реалізація видалення дублікатів
    for (int i = 0; i < n; ++i) {
        bool isDuplicate = false;

        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j]) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            a[newSize++] = a[i];
        }
    }

    a.resize(newSize);
}

void customRotateArray(std::vector<int>& a, int K) {
    int n = a.size();
    K %= n;

    // Реалізація циклічного зсуву
    for (int i = 0; i < K; ++i) {
        int temp = a[0];
        for (int j = 0; j < n - 1; ++j) {
            a[j] = a[j + 1];
        }
        a[n - 1] = temp;
    }
}

void solve(int N, int K, std::vector<int>& a) {
    // Власна реалізація сортування
    customSort(a);

    // Власна реалізація видалення дублікатів
    customRemoveDuplicates(a);

    // Власна реалізація циклічного зсуву
    customRotateArray(a, K);

    // Виведення результату
    std::cout << a.size() << std::endl;
    for (int num : a) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Зчитування вхідних даних
    int N, K;
    std::cin >> N >> K;

    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }

    // Виклик функції та виведення результату
    solve(N, K, a);

    return 0;
}
