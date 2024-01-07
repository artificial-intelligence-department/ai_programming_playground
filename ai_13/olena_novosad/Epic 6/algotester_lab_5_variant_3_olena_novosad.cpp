#include <iostream>

using namespace std;

int N, M, x , y;
int m[1000000] = {0};


int main() {
    cin >> N >> M;
    cin >> y >> x;
    
    int katet_x1 = M - x + 1;
    int katet_x2 = x;
    int katet_y1 = N - y + 1;
    int katet_y2 = y;
    int maxValue = max(katet_x1, katet_x2) + max(katet_y1, katet_y2) - 2;
    
    x--;
    y--;

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            m[j * M + i] = maxValue - abs(x - i) - abs(y - j);
        }
    }
    
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            cout << m[j * M + i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}