#include <iostream>
using namespace std;

int main() {
    long n;
    cin >> n;

    string results;
    cin >> results;

    long kScores = 0, vScores = 0;
    long kGames = 0, vGames = 0;

    for (long i = 0; i < n; ++i) {
        if (results[i] == 'K') {
            kScores++;
        } else {
            vScores++;
        }

        if ((kScores >= 11 || vScores >= 11) && abs(kScores - vScores) >= 2) {
            if (kScores > vScores) {
                kGames++;
            } else {
                vGames++;
            }
            kScores = 0;
            vScores = 0;
        }
    }

    cout << kGames << ":" << vGames << endl;

    if (kScores > 0 || vScores > 0) 
    {
        cout << kScores << ":" << vScores << endl;
    }
    
    return 0;
}
