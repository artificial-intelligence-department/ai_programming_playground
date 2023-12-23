/*
Вам дано масив, який складається з  N додатніх цілих чисел.
Ваше завдання - розділити його на три частини, по остачі від ділення на 3, по зростанню остачі (тобто спочатку йдуть числа, у яких остача 0, далі числа з остачею 1 і тоді нарешті числа з остачею 2).
Далі необхідно ті елементи, остача від ділення на 3 яких парна посортувати по зростанню, а ті, у яких остача 1 - по спаданню.
Після цього видаліть усі дублікати з масиву.
Виведіть результуючий масив.
Вхідні дані
У першому рядку N - кількість чисел.У другому рядку N чисел ai - елементи масиву.
Вихідні дані
У першому рядку M - кількість чисел у масиву
У другому рядку M посоротованих за умовою чисел.
Обмеження
1 ≤ N ≤ 10^3
0 ≤ ai ≤ 10^3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Компаратор для сортування за умовою
bool customComparator(int a, int b) {
    if (a % 3 == 0 && b % 3 == 0) {
        return a < b;
    } else if (a % 3 == 1 && b % 3 == 1) {
        return a > b;
    } else {
        return a < b;
    }
}

int main() {
    // Введення кількості елементів масиву
    int N;
    cin >> N;

    // Введення елементів масиву
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Розділення масиву за остачею від ділення на 3
    auto isMultipleOf3 = [](int x) { return x % 3 == 0; };
    auto isOneMoreThanMultipleOf3 = [](int x) { return x % 3 == 1; };

    auto it1 = partition(arr.begin(), arr.end(), isMultipleOf3);
    auto it2 = partition(it1, arr.end(), isOneMoreThanMultipleOf3);

    // Сортування та видалення дублікатів
    sort(arr.begin(), it1);
    sort(it2, arr.end(), greater<int>());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    // Виведення результату
    cout << arr.size() << endl;
    for (int i : arr) {
        cout << i << " ";
    }

    return 0;
}
