// Вогняне дихання
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double countDistance(int x, int y, int x_i, int y_i);

int main()
{
    int x, y, n, k, x_i, y_i;
    double r;

    cin >> x >> y;
    cin >> n >> k;

    double r_i[n];

    for(int i = 0; i < n; i++)
    {
        cin >> x_i >> y_i;

        r_i[i] = countDistance(x, y, x_i, y_i);
    }

    sort(r_i, r_i + n);

    cout << r_i[k-1];

    return 0;
}
double countDistance(int x, int y, int x_i, int y_i)
{
    double distance;

    distance = sqrt( pow(abs(x-x_i), 2) + pow(abs(y-y_i), 2) );

    return distance;
}
