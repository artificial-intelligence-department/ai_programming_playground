#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, M, x, y;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter M: ";
    cin >> M;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    if (x < 1 || x > N || y < 1 || y > M) {
        cout << "Invalid input for x or y";
        return 1;
    }

    int** result = new int* [N];
    for (int i = 0; i < N; ++i) {
        result[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result[i][j] = abs(i - (x - 1)) + abs(j - (y - 1));
        }
    }
    int max=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (max < result[i][j])
                max = result[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
                cout<< abs(result[i][j]-max)<<" ";
        }
        cout << endl;
    }

    return 0;
}
