// algotester 0031
// Коля, Вася і Теніс

#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;

    string results;
    cin >> results;

    int kolya_score = 0;
    int vasya_score = 0;

    int kolya_game = 0;
    int vasya_game = 0;

    for (int i = 0; i < n; ++i) {
        if (results[i] == 'K') {
            kolya_score++;
        } else {
            vasya_score++;
        }

        if ((kolya_score >= 11 || vasya_score >= 11) && abs(kolya_score - vasya_score) >= 2) {
            if (kolya_score > vasya_score) {
                kolya_game++;
            } else {
                vasya_game++;
            }

            kolya_score = 0;
            vasya_score = 0;
        }
    }

    cout << kolya_game << ":" << vasya_game << endl;
    if (kolya_score > 0 || vasya_score > 0) {
        cout << kolya_score << ":" << vasya_score << endl;
    }

    return 0;
}

