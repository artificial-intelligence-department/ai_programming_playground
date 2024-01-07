#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t n;
    cin >> n;
    vector<size_t> numbers(n);
    vector<int> rnumbers(3);
    for (size_t i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> rnumbers[i];
    }
    for (int i = 0; i < 3; i++)
    {
        for (size_t b = 0; b < numbers.size();)
        {
            if (numbers[b] == rnumbers[i])
            {
                numbers.erase(numbers.begin() + b);
            }
            else
            {
                b++;
            }
        }
    }
    if (numbers.size() == 0 || numbers.size() == 1)
    {
        cout << "0" << endl;
        return 0;
    }
    for (size_t i = 0; i < numbers.size() - 1; i++)
    {
        numbers[i] = numbers[i] + numbers[i + 1];
    }
    numbers.pop_back();
    cout << numbers.size() << endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    return 0;
}