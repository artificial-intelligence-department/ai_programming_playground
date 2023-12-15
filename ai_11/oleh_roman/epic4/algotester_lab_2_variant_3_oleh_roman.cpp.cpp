#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector <int> position(n);
    for (int i = 0; i < n; i++) {
        cin >> position[i];
    }

    int left = 1;
    int right = n;
    while (1) {
        if (left == right){
            cout << left << " " << right << endl;
            cout << "Collision" << endl;
            return 0;
        }
        if (left + 1 == right) {
            cout << left << " " << right << endl;
            cout << "Stopped" <<endl;
            return 0;
        }
        left += position[left - 1];
        right -= position[right - 1];
        if (left > right){
            cout << left << " " << right << endl;
            cout << "Miss" << endl;
            return 0;
        }
    }
    return 0;
}
    


