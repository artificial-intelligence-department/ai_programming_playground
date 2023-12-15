#include <iostream>
using namespace std;

int main() {
    int cost[100], number, money;

    cout << "Введіть суму грошей, які у Петра: ";
    cin >> money;

    cout << "Введіть кількість доступних книг: ";
    cin >> number;

    cout << "Введіть ціни книг через пробіл: ";
    for (int i = 0; i < number; i++) {
        cin >> cost[i];
    }


    int count = 0;
    for(int i = 0; i < number; i++) {
        if(money < cost[i]) {
            break;
        } else {
            money -= cost[i];
            count++;
        }
    }

    cout << "Петро може собі дозволити " << count << " книг." << endl;
    return 0;
}
