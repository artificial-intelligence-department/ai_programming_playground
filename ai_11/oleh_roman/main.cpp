#include <iostream>
#include <vector>
using namespace std;

const vector<int> cash = {1, 2, 5, 10, 20, 50, 100, 200, 500};

int main() {
    int input;
    cout << "Enter amount of money:";
    cin >> input;
    int count_of_banknotes = 0;

    // size_t is platform-dependent integer
    for (int i = cash.size(); i >= 0; i--) {
        if (input < cash[i]) continue;

        // if ints are divided, only integer part is retrieved
        int current_banknotes = input / cash[i];
        count_of_banknotes += current_banknotes;

        input -= current_banknotes * cash[i];
    }
    cout << "Minimum you need: " << count_of_banknotes << " casheses";
}
