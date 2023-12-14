#include<bits/stdc++.h> 
using namespace std;

int main() {
int arr[3][2];

for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
        cin >> arr[i][j];  
        }
    }

    double a = pow((pow((arr[0][0] - arr[1][0]), 2) + pow((arr[0][1] - arr[1][1]), 2)), 0.5);
    double b = pow((pow((arr[0][0] - arr[2][0]), 2) + pow((arr[0][1] - arr[2][1]), 2)), 0.5);
    double c = pow((pow((arr[1][0] - arr[2][0]), 2) + pow((arr[1][1] - arr[2][1]), 2)), 0.5);

    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    cout << "area: " << area;
    return 0;
}