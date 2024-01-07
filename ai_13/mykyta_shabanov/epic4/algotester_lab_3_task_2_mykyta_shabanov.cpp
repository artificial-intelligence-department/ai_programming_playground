#include <iostream>

using namespace std;

bool SearachBinary(int arr[], int size, int key)
{
    int mid, leftIndex = 0, rightIndex = size - 1;

    while(rightIndex >= leftIndex)
    {
        mid = (leftIndex + rightIndex)/2;
        if(key < arr[mid])
            rightIndex = mid - 1;
        else if(key > arr[mid])
            leftIndex = mid + 1;
        else
            return true;
    }
    return false;
}

int main()
{
        //prompting
    int n, m;
    cin >> n;
    int nums1 [n];
    for(int i = 0; i < n; i++)
        cin >> nums1[i];
    cin >> m;
    int nums2[m];
    for(int i = 0; i < m; i++)
        cin >> nums2[i];

        //serching elements in array
    int result = 0, l = n + m;
    for (int i = 0; i < n; i++)
    {
        int key = nums1[i];
        if(SearachBinary(nums2, m, key))
        {
            result++;
            l--;
        }
    }
    
    cout << result << endl << l;
    return 0;
}

