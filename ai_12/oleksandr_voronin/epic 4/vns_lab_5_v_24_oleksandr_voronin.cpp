#include <iostream>

using namespace std;

int main(){
    int n=3;
    int ROW = 3,COL = 3;
    int arr[ROW][COL]={  {5, 7, 1},
                         {123, 56, 122},
                         {77, 8, 3}};
    
    int sum=0;
    int diagonalrow=0;
    int diagonalcol=0;
pos1:
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            if(arr[i][j]>arr[diagonalrow][diagonalcol])
            {
                if(arr[i][j]==arr[diagonalrow][diagonalcol])
                {
                    continue;
                }
                else sum++;
            }
        }
    }

    if(n==ROW)
    {
        diagonalcol++;
        diagonalrow++;
        if(diagonalrow <=ROW)
        {
            cout << sum <<endl;
            sum =0;
            goto pos1;
        }
    }
}