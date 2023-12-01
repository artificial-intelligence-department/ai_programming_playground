#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long int n;
    int x1, x2, y1, y2;
    long int totalDistance = 0;

    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        long int distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

        totalDistance += distance;
    }

   cout << totalDistance;

    return 0;
}

