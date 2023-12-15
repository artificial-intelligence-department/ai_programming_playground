//Програма, що сортує задані значення відповідно до умови ділення на 3
#include <iostream>
#include <vector>
#include <algorithm> // До цієї бібліотеки належить команда sort, яка є ключовою у даній задачі

using namespace std;

int main() {
    int size;
    cin >> size;

    if (size > 10e3 && size < 0) {
        return 0;
    }

    vector<int> numbers(size);
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];
        if (numbers[i] > 10e3 && numbers[i] < 0) {
            return 0;
        }
    }

    sort(numbers.begin(), numbers.end());
    auto duplicate = unique(numbers.begin(), numbers.end()); // Команда unique потрібна для відсіювання дублікатів
    numbers.erase(duplicate, numbers.end());

    sort(numbers.begin(), numbers.end(), [](int a, int b) { // Для коректного сортування використовуємо лямбда-функцію
        if (a % 3 == 0 && b % 3 == 0) {
            return a < b;
        }
         else if (a % 3 == 1 && b % 3 == 1) {
            return a > b;
        }
         else if (a % 3 == 2 && b % 3 == 2) {
            return a < b;
        }
         else {
            return a % 3 < b % 3;
        }
    });
    cout << numbers.size() << endl;

    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }

    return 0;
}
