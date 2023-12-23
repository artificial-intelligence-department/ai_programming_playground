#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> n;
    if (n < 1)
    {
        return 0;
    }
    else if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int array[n];

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        array[i] = number;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    if (array[n - 1] - array[1] > array[n - 2] - array[0]) {
        m = array[n - 2] - array[0];
    } else {
        m = array[n - 1] - array[1];
    }
    cout << m;

    return 0;
}
