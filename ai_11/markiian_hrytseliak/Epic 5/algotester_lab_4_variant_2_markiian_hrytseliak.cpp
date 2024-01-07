#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int size,K;

    cin>>size>>K;

    vector<int>arr (size);
    
    for (int i = 0; i < size; ++i) 
    {
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    auto UniqueEnd = unique(arr.begin(),arr.end());

    arr.erase(UniqueEnd, arr.end());

    rotate(arr.begin(),arr.begin() + K % arr.size(),arr.end());

    cout<<arr.size()<<endl;

    for (const int& element : arr) 
    {
        cout << element << " ";
    }
    return 0;
}