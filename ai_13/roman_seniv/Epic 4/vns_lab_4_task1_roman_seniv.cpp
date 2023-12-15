#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    const int size = 10;
    vector<int> a(size);

    srand(time(0));

    for (int i = 0; i < size; ++i) {
        a[i] = rand() % 100 + 1;
    }

    cout << "First vector: ";
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    vector<int> result; 

    for (int i = 0; i < size; ++i) {
        if (a[i] % 7 != 0) {
            result.push_back(a[i]);
            if (a[i] % 2 != 0) {
                result.push_back(0);
            }
        }
    }

    cout << "Second vector: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
