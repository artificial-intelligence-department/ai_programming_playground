#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N, M;
    cin >> N >> M;

    
    vector<string> cave(N);
    for (int i = 0; i < N; ++i) {
        cin >> cave[i];
    }
    
    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            
            if (cave[i][j] == 'S') {
                
                while (i + 1 < N && cave[i + 1][j] == 'O') {
                    cave[i + 1][j] = 'S';
                    cave[i][j] = 'O';
                    ++i; 
                }
            }
        }
    }

    
    cout << endl;
                
    cout<<endl;
    for (const string& row : cave) {
        cout << row << endl;
    }

    return 0;
}
