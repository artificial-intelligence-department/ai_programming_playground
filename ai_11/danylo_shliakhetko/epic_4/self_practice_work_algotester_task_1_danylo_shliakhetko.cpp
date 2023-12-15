#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int answer = 1;

    for(int i = 0; i < n; i++){
        answer = max(answer, dp[i]);
    }

    cout << answer;

    return 0;
}
