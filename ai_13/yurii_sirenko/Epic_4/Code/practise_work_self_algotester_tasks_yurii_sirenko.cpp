#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int array[n];
    for(int i = 0; i < n; i++)
    {   
        cin >> array[i];
    }

    int prefix_sum[n];
    prefix_sum[0] = array[0];
    for(int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i-1] + array[i];
    }

    int tasks[m][3];
    for(int i = 0; i < m; i++)
    {
        cin >> tasks[i][0] >> tasks[i][1] >> tasks[i][2];
    }
    for(int i = 0; i < m; i++)
    {
        if(tasks[i][0] == 1)
        {
            cout << prefix_sum[tasks[i][2]-1]-prefix_sum[tasks[i][1]-2] << "\n";
        }
        else if(tasks[i][0] == 2)
        {
            for(int j = tasks[i][1]-1; j < n; j++)
            {
                prefix_sum[j] += tasks[i][2];
            }
        }
    }
}
