#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> drones(n);
    for (int i = 0; i < n; i++) {
        cin >> drones[i];
    }

    int leftDronePos = 1;
    int rightDronePos = n;

    while (true) {
        // Перевірка умов завершення
        if (leftDronePos == rightDronePos) {
            cout << leftDronePos << " " << rightDronePos << endl;
            cout << "Collision" << endl;
            break;
        } else if (leftDronePos > rightDronePos) {
            cout << leftDronePos << " " << rightDronePos << endl;
            cout << "Miss" << endl;
            break;
        } else if (leftDronePos + 1 == rightDronePos) {
            cout << leftDronePos << " " << rightDronePos << endl;
            cout << "Stopped" << endl;
            break;
        }

        // Обчислення наступних позицій
        leftDronePos += drones[leftDronePos - 1];
        rightDronePos -= drones[rightDronePos - 1];
    }

    return 0;
}
