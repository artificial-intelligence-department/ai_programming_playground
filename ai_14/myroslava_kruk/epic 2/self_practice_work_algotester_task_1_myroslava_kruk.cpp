#include <iostream>
using namespace std;

int main() {
    int N, C = 0;
    cout << "Введіть вартість подарунку :";
    cin >> N;
    int V[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 9 && N > 0; ++i) {
        C += N / V[i];
        N %= V[i];
    }

    if (C > 0) {
        cout << "Мінімальна кількість купюр: " << C << endl;
    }

    return 0;
}
