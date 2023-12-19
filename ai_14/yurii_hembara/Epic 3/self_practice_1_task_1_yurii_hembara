#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string results;
    std::cin >> results;

    int kolya_score = 0, vasya_score = 0;
    int kolya_games = 0, vasya_games = 0;

    for (char result : results) {
        if (result == 'K') {
            kolya_score++;
        } else {
            vasya_score++;
        }

        if ((kolya_score >= 11 || vasya_score >= 11) && abs(kolya_score - vasya_score) >= 2) {
            if (kolya_score > vasya_score) {
                kolya_games++;
            } else {
                vasya_games++;
            }
            kolya_score = 0;
            vasya_score = 0;
        }
    }

    std::cout << kolya_games << ":" << vasya_games << std::endl;

    if (kolya_score > 0 || vasya_score > 0) {
        std::cout << kolya_score << ":" << vasya_score << std::endl;
    }

    return 0;
}
