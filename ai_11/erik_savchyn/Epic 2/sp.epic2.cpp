#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    // 0 - rock, 1 - scissors, 2 - paper
    uniform_int_distribution<> dis(0, 2);
    int computerChoice = dis(gen);

    int userChoice;

    cout << "Choose: 0 - rock, 1 - scissors, 2 - paper" << endl;
    cin >> userChoice;

    cout << "Computer chose: " << computerChoice << endl;
    cout << "You chose: " << userChoice << endl;

    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == 0 && computerChoice == 1) ||
               (userChoice == 1 && computerChoice == 2) ||
               (userChoice == 2 && computerChoice == 0)) {
        cout << "You win!" << endl;
    } else {
        cout << "You loss" << endl;
    }

    return 0;
}
