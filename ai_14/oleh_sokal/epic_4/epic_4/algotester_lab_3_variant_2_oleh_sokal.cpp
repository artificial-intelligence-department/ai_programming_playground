#include <iostream>
using namespace std;

int main() {
    int arr[100] = {0}, arr1[100] = {0};
    int n, n1;
    int unique = 0;
    int similar = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < n1; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (arr1[i] == arr[j]) {
                similar++;
            }
        }
    }
unique= (n1+n) - similar;
    cout << similar << endl;
    cout << unique << endl;
    return 0;
}
