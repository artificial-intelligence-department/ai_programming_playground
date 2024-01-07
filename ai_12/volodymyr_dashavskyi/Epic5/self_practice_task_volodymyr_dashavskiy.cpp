#include <iostream>

using namespace std;
int main()
{

    unsigned int n, k;

    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    int currenttooth = 0;
    int maxtooth = 0;

    for (int j = 0; j < n; j++)
    {

        if (arr[j] >= k)
        {
            currenttooth++;
        }
        else
        {
            if (currenttooth > maxtooth)
            {
                maxtooth = currenttooth;
            }

            currenttooth = 0;
        }
    }
    if (currenttooth > maxtooth)
    {
        maxtooth = currenttooth;
    }
    cout << maxtooth << endl;
}