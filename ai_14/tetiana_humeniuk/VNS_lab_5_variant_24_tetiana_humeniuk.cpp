#include <iostream> 
using namespace std;
int countOfLargerElements(int **matrix, int n) 
{
    int diagonal_max;
    diagonal_max = matrix[0][0];
    for(int i=0; i<n; i++)
    {
        if(matrix[i][i] > diagonal_max)
        {
            diagonal_max = matrix[i][i];   
        }
    }
    int count = 0;
    for(int row=0; row<n; row++)
    {
        for(int column=0; column<n; column++)
        {
            if(matrix[row][column]>diagonal_max) 
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int n;
    cout<<"enter dimension of square matrix: ";
    cin>>n;
    cout<<"enter elements of matrix: \n";
    int **matrix = new int *[n];
    for(int i=0; i<n;i++)
    {
        matrix[i] = new int [n];
    }
    for(int row=0; row<n; row++)
    {
        for(int column=0; column<n; column++)
    {
         cin>>matrix[row][column];
    }
    } 
    cout<<countOfLargerElements(matrix, n);
}

//елемента на головній діагоналі.