#include <iostream>
#include <vector>

using namespace std;

bool point_in_polygon(const vector<pair<double, double>> &polygonpoints, const pair<double, double> &point)
{
    for (const auto &pointp : polygonpoints)
    {
        if (pointp == point)
        {
            return true;
        }
    }

    int n = polygonpoints.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;

        if (point.first > polygonpoints[i].first && point.first < polygonpoints[j].first)
        {
            double x = (point.first - polygonpoints[i].first) / (polygonpoints[j].first - polygonpoints[i].first) * (polygonpoints[j].second - polygonpoints[i].second) + polygonpoints[i].second;
            if (x > point.second)
            {
                count++;
            }
        }
    }

    return count % 2 == 1;
}

int main()
{
    int n;
    cout << "number of sides: ";
    cin >> n;

    vector<pair<double, double>> polygonpoints(n);
    for (int i = 0; i < n; i++)
    {
        cout << "coordinates of dot " << i + 1 << ": ";
        cin >> polygonpoints[i].first >> polygonpoints[i].second;
    }

    pair<double, double> point;
    cout << "coordinates of dot we're checking: ";
    cin >> point.first >> point.second;

    bool is_in = point_in_polygon(polygonpoints, point);

    if (is_in)
    {
        cout << "true." << endl;
    }
    else
    {
        cout << "false." << endl;
    }

    return 0;
}
