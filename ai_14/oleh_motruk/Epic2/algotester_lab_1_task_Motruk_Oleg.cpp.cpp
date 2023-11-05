#include <iostream>
#include <string>

using namespace std;

int main() {
    const int n = 5;
    int numbers[n];
    string check;

    cout << "Enter a side of cube:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (numbers[i] <= 0) {
            cout << "Side of cube can not be 0" << endl;
            exit(0);
        }
    }

    for (int i = 0; i < n; i++) {
        if (numbers[i] > numbers[i -1] ){
            check = "Lose";
        }
        else if (numbers[i] < numbers[i - 1]){
            check = "Win";
        }
    }

    if (check == "Lose") {
        cout << "Lose" << endl;
    }
    else if (check == "Win"){
        cout << "win" << endl;
    }
    return 0;
}
