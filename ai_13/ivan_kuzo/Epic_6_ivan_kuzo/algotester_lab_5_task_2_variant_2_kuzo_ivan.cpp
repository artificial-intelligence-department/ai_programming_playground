#include <iostream>
using namespace std;

int main() {
    char cave[1000][1000];
    int rows, cols;
    cin >> rows >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> cave[i][j];
        }
    }
    cout<<endl;

    for (int i = rows - 2; i >= 0; i--) {
        for (int j = 0; j < cols; j++) {
            if (cave[i][j] == 'S') {
                int k = i + 1;
                while (k < rows && cave[k][j]=='O') {
                    k++;
                }
                k--;

                if (k != i) {
                    swap(cave[i][j], cave[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << cave[i][j];
        cout << endl;
    }

    return 0;
}

