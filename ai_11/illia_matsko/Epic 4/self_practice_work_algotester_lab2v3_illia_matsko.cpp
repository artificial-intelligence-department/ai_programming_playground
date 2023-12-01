#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int firstIndex = 0, secondIndex = n-1;

    while(true)
    {
        if(secondIndex - firstIndex == 1)
        {
            cout << firstIndex+1 << ' ' << secondIndex+1 << endl;
            cout << "Stopped";
            return 0;
        } else if(firstIndex == secondIndex)
        {
            cout << firstIndex+1 << ' ' << secondIndex+1 << endl;
            cout << "Collision";
            return 0;
        } else if(firstIndex > secondIndex)
        {
            cout << firstIndex+1 << ' ' << secondIndex+1 << endl;
            cout << "Miss";
            return 0;
        }

        firstIndex +=arr[firstIndex];
        secondIndex -= arr[secondIndex];
    }
}