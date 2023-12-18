#include <vector>
#include <iostream>

using namespace std;

void earthquake(vector<string>& cave) {
    int N = cave.size();
    int M = cave[0].size();

    for (int j = 0; j < M; ++j) {
        int empty = N - 1;
        for (int i = N - 1; i >= 0; --i) {
            if (cave[i][j] == 'X') {
                empty = i - 1;
            } else if (cave[i][j] == 'S') {
                swap(cave[i][j], cave[empty][j]);
                --empty;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // Перевірка обмежень
    if (N < 1 || N > 1000 || M < 1 || M > 1000) {
        cerr << "Недопустимі вхідні дані: N та M повинні бути від 1 до 1000." << endl;
        return 1;
    }

    vector<string> cave(N);
    for (int i = 0; i < N; ++i) {
        cin >> cave[i];
        if (cave[i].size() != M) {
            cerr << "Недопустимі вхідні дані: кожен рядок повинен мати довжину M." << endl;
            return 1;
        }
    }

    earthquake(cave);

    for (const auto& row : cave) {
        cout << row << endl;
    }

    return 0;
}