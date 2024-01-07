#include <iostream>
#include <cmath>

int main()
{
    int n, m, x, y, maxelement=0;
    std::cin >> n >> m >> x >> y;
    
    int arr[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(maxelement < abs(x-1-i) + abs(y-1-j) )
            maxelement = abs(x-1-i) + abs(y-1-j);
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            arr[i][j] = maxelement - (abs(x-1-i) + abs(y-1-j));
        }
    }
    arr[x-1][y-1]=maxelement;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            std::cout << arr[i][j] << " ";
        }

        std::cout<< std::endl;
    }
}