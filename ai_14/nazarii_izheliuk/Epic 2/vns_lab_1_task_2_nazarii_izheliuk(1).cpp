#include<iostream>
using namespace std;

int main() {
    int n, m, answer;
    cout << "Enter value for n: ";
    cin >> n;
    cout << "Enter value for m: ";
    cin >> m;
    n--;
    answer = n - m;
    cout << "Answer: " << answer;
    return 0;
}