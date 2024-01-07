#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> numbers;
    for (int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    sort(numbers.begin(), numbers.end());
    vector<int>::iterator point = unique(numbers.begin(), numbers.end());
    numbers.erase(point, numbers.end());

    vector<int>::iterator point1;
    vector<int>::iterator point2;
    point1 = partition(numbers.begin(), numbers.end(), [](int value){ return value % 3 == 0; });
    point2 = partition(point1, numbers.end(), [](int value){ return value % 3 == 1; });
    sort(numbers.begin(), point1);
    sort(point1, point2, greater<int>());
    sort(point2, numbers.end());
    cout << numbers.size() << endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
}