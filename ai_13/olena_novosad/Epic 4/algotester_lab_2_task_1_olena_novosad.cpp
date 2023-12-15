#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m = 0;
int main()
{
    int N;
    cin >> N;

    if (N <= 0)
    {
        cout << m;
        return 0;
    }

    vector<int> vect;
    int n = 0;

    while (n < N)
    {
        int elem;
        cin >> elem;
        vect.push_back(elem);
        n++;
    }
    if (N == 1)
    {
        cout << m;
        return 0;
    }

    sort(vect.begin(), vect.end());

    int min = vect.at(0);
    int pmin = vect.at(1);

    int max = vect.at(N - 1);
    int pmax = vect.at(N - 2);

    int deltamax = max - pmax;
    int deltamin = pmin - min;

    if (deltamax > deltamin)
    {
        m = pmax - min;
    }
    else
    {
        m = max - pmin;
    }
    cout << m << endl;
}