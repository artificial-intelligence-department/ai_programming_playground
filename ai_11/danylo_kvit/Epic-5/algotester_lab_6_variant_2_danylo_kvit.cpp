#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    char board[8][8];
    for(auto & i : board){
        for(char & j : i){
            scanf("%c",&j);
        }
        char x;
        scanf("%c", &x);
    }
//    for(auto& i:board){for(auto& j:i) cout << j << ' '; cout << '\n';}
    int q;
    cin >> q;
    for(int _=0;_<q;_++){
        string ans;
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        if(board[x][y]!='O') cout << 'X' << '\n';
        else {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (i == x && j == y)continue;
                    if (abs(i - x) == abs(j - y) && (board[i][j] == 'B')) {
                        ans += 'B';
                    }
                    if (abs(i - x) <= 1 && abs(j - y) <= 1 && board[i][j] == 'K') {
                        ans += 'K';
                    }
                    if (board[i][j] == 'R' && (i == x || j == y)) {
                        ans += 'R';
                    }
                    if (board[i][j] == 'P' &&(i==x-1&&abs(j-y)==1)){
                        ans += 'P';
                    }
                    if (board[i][j] == 'Q'&&(abs(i - x) == abs(j - y)||(i == x || j == y))){
                        ans += 'Q';
                    }
                    if (board[i][j] == 'N'&&x!=i&&y!=j&&abs(x-i)+abs(y-j)==3){
                        ans += 'N';
                    }
                }
            }
            if(ans.empty()) cout << 'O' << '\n';
            else{
                sort(ans.begin(),ans.end());
                cout << ans[0];
                for(int i=0rp;i<ans.size();i++) if(ans[i]!=ans[i-1]) cout << ans[i];
                cout << '\n';
            }
        }
    }
}