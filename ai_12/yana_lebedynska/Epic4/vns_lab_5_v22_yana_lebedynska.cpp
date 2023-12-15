#include <iostream>
using namespace std;

int main()
{
    int arr[4][5] =
    {
    {1, 4, 5, 2, 7},
    {2, 4, 9, 0, 3},
    {3, 4, 1, 1, 2},
    {3, 1, 6, 8, 2}
    };

    int sumOfFirstColumn = 0;
    double avarageOfFirstColumn;
    for(int row = 0; row < 4; row++)
    {
        sumOfFirstColumn += arr[row][0];
    }

    avarageOfFirstColumn = sumOfFirstColumn/4;
    cout << "The avarage of elements of the first column is: " << avarageOfFirstColumn << endl;

    for(int col = 1; col < 5; col++)
    {
        int numberOfElements = 0;
        for(int row = 0; row < 4; row++)
        {
            if(arr[row][col] > avarageOfFirstColumn)
            {
                numberOfElements++;
            }
        }

        cout << "In column number " << col << " there is " << numberOfElements << " elements which exceed the average. " << endl;
        cout << endl;
    }

    return 0;
}
