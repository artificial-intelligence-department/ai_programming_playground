#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* speeds = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> speeds[i];
    }

    // we have one drone on both sides - start and end
    int drone_a_pos = 1, drone_b_pos = n;

    string status = "Ok";
    while (status == "Ok") {
        if (drone_a_pos == drone_b_pos)
            status = "Collision";
        else if (drone_a_pos + 1 == drone_b_pos)
            status = "Stopped";
        else if (drone_a_pos > drone_b_pos)
            status = "Miss";
        else {
            drone_a_pos += speeds[drone_a_pos - 1];
            drone_b_pos -= speeds[drone_b_pos - 1];
        }
    }

    cout << drone_a_pos << " " << drone_b_pos << endl
         << status;

    delete[] speeds;
    return 0;
}
