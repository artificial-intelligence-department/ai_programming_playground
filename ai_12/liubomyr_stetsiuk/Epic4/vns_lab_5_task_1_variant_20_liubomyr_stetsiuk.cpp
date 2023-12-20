#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int rows = 3;
const int columns = 3;

int main()
{
    int array[rows][columns] = {{0, 2, 3},
                                {4, 5, 6},
                                {6, 8, 8}};

    vector<int> uniqueElements;

    bool foundUnique = true;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            foundUnique = true;

            for (int k = 0; k < rows; ++k)
            {
                for (int l = 0; l < columns; ++l)
                {
                    if (array[i][j] == array[k][l] && (i != k || j != l))
                    {
                        foundUnique = false;
                        break;
                    }
                }
                if (!foundUnique)
                {
                    break;
                }
            }

            if (foundUnique)
            {
                uniqueElements.push_back(array[i][j]);
            }
        }
    }

    sort(uniqueElements.begin(), uniqueElements.end());
    cout << uniqueElements[0] << endl;
    return 0;
}
