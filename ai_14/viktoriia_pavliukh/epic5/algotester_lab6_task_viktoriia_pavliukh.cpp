#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int q, i, j;
    char row[8][8];
    vector <vector<string> > result(8,vector<string>(8, ""));

    for ( i = 0; i < 8 ; ++i) {
        for ( j = 0; j < 8; ++j) {
            cin>>row[i][j];
        }
    }

    cin>>q;
    int *k = new int [q];
    int *t = new int [q];
    for (int m = 0; m < q ; m++) {
        cin >> k[m] >> t[m];
        k[m]--;
        t[m]--;

        if (row[k[m]][t[m]] != 'O') {
            result[k[m]][t[m]] += "X";
        }
    }
            for(i=0; i<8; i++){
                for(j=0; j<8; j++) {
                    if (row[i][j] == 'K') {
                        for (int m = -1; m <= 1; ++m) {
                            for (int n = -1; n <= 1; ++n) {
                                int newK = i + m;
                                int newT = j + n;
                                if (m != 0 || n != 0) {
                                    if (newK >= 0 && newK < 8 && newT >= 0 && newT < 8 && result[newK][newT] != "X" && result[newK][newT] != "K")  {
                                        result[newK][newT] += "K";
                                    }
                                }
                            }
                        }
                    } else if (row[i][j] == 'R') {
                        for (int m = 0; m < 8; m++) {
                            if (m != i && result[m][j] != "X" && result[m][j] != "R") {
                                result[m][j] += "R";
                            }
                        }
                        for (int m = 0; m < 8; m++) {
                            if (m != j && result[i][m] != "X" && result[i][m] != "R") {
                                 result[i][m] += "R";
                            }
                        }
                    } else if (row[i][j] == 'B') {
                        for ( int m = i-1, n = j+1; m >= 0 && n < 8; m--, n++) {
                            if (result[m][n] != "X" && result[m][n] != "B") {
                                result[m][n] += "B";
                            }
                        }
                        for ( int m = i+1, n = j-1; m < 8 && n >= 0 ; m++, n--) {
                            if (result[m][n] != "X" && result[m][n] != "B") {
                                result[m][n] += "B";
                            }
                        }
                        for ( int m = i-1, n = j-1; m >= 0 && n >= 0; m--, n--) {
                            if (result[m][n] != "X" && result[m][n] != "B") {
                                result[m][n] += "B";
                            }
                        }
                        for ( int m = i+1, n = j+1; m < 8 && n < 8; m++, n++) {
                            if (result[m][n] != "X" && result[m][n] != "B") {
                                result[m][n] += "B";
                            }
                        }

                    } else if (row[i][j] == 'N') {
                        int x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
                        int y[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
                        for (int m = 0; m < 8; m++) {
                            int newX = i + x[m];
                            int newY = j + y[m];
                            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && result[newX][newY] != "X" && result[newX][newY] != "N") {
                                  result[newX][newY] += "N";
                            }
                        }
                    } else if (row[i][j] == 'Q') {
                        for ( int m = i-1, n = j+1; m >= 0 && n < 8; m--, n++) {
                            if (result[m][n] != "X" && result[m][n] != "Q") {
                                result[m][n] += "Q";
                            }
                        }
                        for ( int m = i+1, n = j-1; m < 8 && n >= 0 ; m++, n--) {
                            if (result[m][n] != "X" && result[m][n] != "Q") {
                                result[m][n] += "Q";
                            }
                        }
                        for ( int m = i-1, n = j-1; m >= 0 && n >= 0; m--, n--) {
                            if (result[m][n] != "X" && result[m][n] != "Q") {
                                result[m][n] += "Q";
                            }
                        }
                        for ( int m = i+1, n = j+1; m < 8 && n < 8; m++, n++) {
                            if (result[m][n] != "X" && result[m][n] != "Q") {
                                result[m][n] += "Q";
                            }
                        }
                        for (int m = 0; m < 8; m++) {
                            if (m != i && result[m][j] != "X" && result[m][j] != "Q") {
                                result[m][j] += "Q";
                            }
                        }
                        for (int m = 0; m < 8; m++) {
                            if (m != j && result[i][m] != "X" && result[i][m] != "Q") {
                                result[i][m] += "Q";
                            }
                        }
                    } else if (row[i][j] == 'P') {
                        if (i + 1 < 8 && j - 1 >= 0 && result[i+1][j-1] != "X" && result[i+1][j-1] != "P") {
                            result[i+1][j-1] += "P";
                        }
                        if (i + 1 < 8 && j + 1 < 8 && result[i+1][j+1] != "X" && result[i+1][j+1] != "P") {
                            result[i+1][j+1] += "P";
                        }
                    }
                }
            }
            for(int m=0; m<8; m++) {
                for(int n=0; n<8; n++) {
                    if (result[m][n]==""){
                        result[m][n]="O";
                    }
                    sort(result[m][n].begin(), result[m][n].end());
                }
            }
            for(int m=0; m<q; m++){
                cout<<result[k[m]][t[m]]<<endl;
            }
    return 0;
}