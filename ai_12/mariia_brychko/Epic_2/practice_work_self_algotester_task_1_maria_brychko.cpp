#include <iostream>
#include <vector>

using namespace std;

int main() {

int price;
cin >> price;

vector<int>banknotes = {500, 200, 100, 50, 20, 10, 5, 2, 1};
int number = 0;

    for (int i = 0; i < banknotes.size(); i++) {
        number += price / banknotes[i];
        price %= banknotes[i];
    }

    cout << number;

    return 0;
}
