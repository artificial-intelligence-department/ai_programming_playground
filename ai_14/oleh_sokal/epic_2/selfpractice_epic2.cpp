#include <iostream>


int main() {
    using namespace std;


    int n;
    cin >> n;


    string results;
    cin >> results;


    int score_kolya = 0, score_vasya = 0;
    int games_kolya = 0, games_vasya = 0;


    for (int i = 0; i < n; ++i) {
        if (results[i] == 'K') {
            score_kolya++;
        } else {
            score_vasya++;
        }


        if ((score_kolya >= 11 || score_vasya >= 11) && abs(score_kolya - score_vasya) >= 2) {
            if (score_kolya > score_vasya) {
                games_kolya++;
            } else {
                games_vasya++;
            }
            score_kolya = 0;
            score_vasya = 0;
        }
    }


    cout << games_kolya << ":" << games_vasya << endl;


    if (score_kolya > 0 || score_vasya > 0) {
        cout << score_kolya << ":" << score_vasya << endl;
    }


    return 0;
}
