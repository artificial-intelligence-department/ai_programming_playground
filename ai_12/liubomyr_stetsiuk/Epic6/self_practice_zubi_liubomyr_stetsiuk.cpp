#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    vector<long long> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    long long max_count = 0;
    long long current_count = 0;

    for (int i = 0; i < n; i++)
    {
        if (num[i] >= k)
        {
            current_count++;
            if (current_count > max_count)
            {
                max_count = current_count;
            }
        }
        else
        {
            current_count = 0;
        }
    }

    cout << max_count << endl;
    return 0;
}
