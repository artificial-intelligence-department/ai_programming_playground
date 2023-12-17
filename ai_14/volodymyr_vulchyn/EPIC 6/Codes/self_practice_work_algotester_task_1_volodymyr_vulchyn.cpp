#include <iostream>
#include <vector>

using namespace std;

int chain(vector <int> & number) 
{
    int n = number.size();

    if (n == 0) {
        return 0;
}

    vector <int> arra(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (number[i] > number[j]) {
                arra[i] = max(arra[i], arra[j] + 1);
            }
        }
    }

    int max = 0;

    for (int i = 0; i < n; ++i) {
        if (arra[i] > max) {
            max = arra[i];
        }
    }
    return max;
}

int main() 
{
    int n;
    cin >> n;
    vector <int> number(n);
    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }
    int result = chain(number);
    cout << result;

    return 0;
}