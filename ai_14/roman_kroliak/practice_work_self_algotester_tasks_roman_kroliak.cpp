#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int points_K, points_V, games_K, games_V;
    points_K = points_V = games_K = games_V = 0;
    bool IncorrectInput = false;
    for (int i = 0; i < n; ++i) {
        (s[i] == 'K') ? points_K++ : (s[i] == 'V') ? points_V++ : IncorrectInput = true;
        if (IncorrectInput) return -1;
        if (points_K >= 11 && points_K >= points_V+2) {
            games_K++;
            points_K = points_V = 0;
        }
        else if (points_V >= 11 && points_V >= points_K+2) {
            games_V++;
            points_K = points_V = 0;
        }
    }
    cout << games_K << ":" << games_V << endl;
    if (points_K != 0 || points_V != 0) cout << points_K << ":" << points_V;
    return 0;
}
