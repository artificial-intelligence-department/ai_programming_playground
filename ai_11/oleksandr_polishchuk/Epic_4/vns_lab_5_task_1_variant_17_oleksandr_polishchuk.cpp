#include <iostream>
#include <vector>

using namespace std;

void maks(int N, int M, vector<vector<int>> arr)
{
    
    int sum = 0, sum1=0;
    
        for(int r = 0; r<=N-3; r++)
        {
            for (int c = 0; c<=M-3; c++)
            {
                for(int v=0; v<3; v++)
                {
                    for (int b=0; b<3; b++)
                    {
                        sum1+=arr[r+v][c+b];
                    }
                    
                }
                if (sum1 > sum)
                    sum = sum1;
                    sum1=0;
                
                
            }
        }
    
    
    cout << sum;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 2, 3}, {1, 2, 2, 1}, {1, 2, 2, 4}, {1, 2, 2, 5}};
    maks(4, 4, arr);
    return 0;
}
