#include <iostream>
#include <sstream>

using namespace std;

int* cleanse(const int* arr, int n) {
    int* result = new int[n / 2 + n % 2];
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            result[j] = arr[i];
            ++j;
        }
    }
    return result;
}

string cleanse(const string& str, char separator = ' ') {
    string result, buf;
    stringstream ss(str);

    int n = 0;
    while (getline(ss, buf, separator)) {
        if (n % 2 == 0) result += buf + separator;
        n++;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter count of elements in array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; ++i)  cin >> arr[i];

    int new_size = n / 2 + n % 2;
    int* result = cleanse(arr, n);
    cout << "Result: ";
    for (int i = 0; i < new_size; ++i) cout << result[i] << ' ';

    cout << endl;

    string str;
    cout << "Enter string: ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, str);

    cout << "Result: " << cleanse(str) << endl;

    return 0;
}
