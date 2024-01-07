// Замінуй країну 404
#include <iostream>

using namespace std;

int main()
{
    int  n, m;
    char pattern[5][5] = {{'x', '.', '.', '.', '.'},   // x , , . .
                           {'.', '.', 'x', '.', '.'},  // , , x , ,
                           {'.', '.', '.', '.', 'x'},  // . , , , x
                           {'.', 'x', '.', '.', '.'},  // , x , , ,
                           {'.', '.', '.', 'x', '.'}}; // . , , x ,

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << pattern[i % 5][j % 5];
        }
        cout << endl;;
    }
    
    return 0;

}
