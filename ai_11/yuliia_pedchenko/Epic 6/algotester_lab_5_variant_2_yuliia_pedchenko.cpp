#include <iostream>
#include <vector>

using namespace  std;

int main() {
    
    int H, W;
    vector<string> cave;

    cin >> H >> W;

    if ( H<1 || W<1 || H>1000 || W>1000) return 0;

    
    for(int i = 0; i < H; i++) {  

        string matherial;
        cin >> matherial;
        cave.push_back(matherial);

    }
    
    for(int j = 0; j < W; j++) {
        for(int i = H-1; i > 0; i--) {
            while(i < H && cave[i-1][j] == 'S' && cave[i][j] == 'O') {
                char temp = cave[i][j];
                cave[i][j] = cave[i-1][j];
                cave[i-1][j] = temp;
                i++;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }


return 0;
}
    
