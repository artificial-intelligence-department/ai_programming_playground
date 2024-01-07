#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    char c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int kolya_score = 0, vasya_score = 0;
    int kolya_wins = 0, vasya_wins = 0;

    for (int i = 0; i < n; i++) {
        if (c[i] == 'K') {
            kolya_score++;
        } else {
            vasya_score++;
        }

        int score_difference = vasya_score - kolya_score;

        if ((vasya_score >= 11 ||  kolya_score >= 11) && abs(score_difference) >= 2) {
            if (vasya_score > kolya_score) {
                vasya_wins++;
            } else {
                kolya_wins++;
            }
            kolya_score = 0;
            vasya_score = 0;
        }
    }

    if (kolya_score > 0 || vasya_score > 0) {
        cout << kolya_wins << ":" << vasya_wins << endl;
        cout << kolya_score << ":" << vasya_score << endl;
    } else {
        cout << kolya_wins << ":" << vasya_wins << endl;
    }

    return 0;
}
