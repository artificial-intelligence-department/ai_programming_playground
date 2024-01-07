#include <iostream>
#include <string>
using namespace std;


void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}


int main() {
    int n, m;
    cin >> n >> m;
    char arr[1000][1000];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }


    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i][j] == 'S' && i + 1 < n && arr[i + 1][j] == 'O') {
                swap(arr[i][j], arr[i + 1][j]);


                while (i + 2 < n && arr[i + 2][j] == 'O') {
                    swap(arr[i + 1][j], arr[i + 2][j]);
                    swap(arr[i][j], arr[i + 1][j]);
                    i++;
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }


    return 0;
}
