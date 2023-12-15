#include <iostream>
#include <algorithm>

int main() 
{
    int n;
    std::cin >> n;

    int arr[100]; 

    for (int i = 0; i < n; ++i) 
    {
        std::cin >> arr[i];
    }

    int dp[100]; 
    for (int i = 0; i < n; ++i) 
    {
        dp[i] = 1; // Ініціалізація всіх dp[i] значеннями 1
    }

    for (int i = 1; i < n; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) 
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max_length = *std::max_element(dp, dp + n);
    std::cout << max_length << std::endl;

    return 0;
}
