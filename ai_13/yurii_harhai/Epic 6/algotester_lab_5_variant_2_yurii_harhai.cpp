#include <iostream>
#include <vector>

using namespace std;
int main() {
    int M, N;

    cin >> M;
    cin >> N;

    vector<vector<char>> vec(M, vector<char>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> vec[i][j];
        }
    }

    // Моделювання землетрусу
    for (int j = 0; j < N; j++) {  
        int lastEmpty = M - 1;  
        for (int i = M - 1; i >= 0; i--) {  
            if (vec[i][j] == 'S') {  
                swap(vec[i][j], vec[lastEmpty][j]);  
                lastEmpty--;  
            }
            else if (vec[i][j] == 'X') {  
                lastEmpty = i - 1;  
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << vec[i][j];
        }
        cout << endl;
    }

    return 0;
}
