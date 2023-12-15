#include <iostream>
#include <vector>

using namespace std;



void swap(int arr[], int a, int b)
{
    int t = arr[a];
    arr[a]=arr[b];
    arr[b]=t;
}

void sort2(int arr[],int n)
{
    for(int i=1, j = 0; i<n; i++)
    {
        if(arr[j]>arr[i])
        {
            swap(arr,i,j);
        }

        if(i==n-1)
        {   
            i=j;
            j++;
        }
    }
}
void sort1(int arr[],int n)
{
    for(int i=1, j = 0; i<n; i++)
    {
        if(arr[j]<arr[i])
        {
            swap(arr,i,j);
        }

        if(i==n-1)
        {   
            i=j;
            j++;
        }
    }
}

int main()
{
    int n,m;
    cin>>n;

    int num_arr[n];

    vector<int> arr0,arr1,arr2;
    bool possibility;

    for(int i = 0;i<n;i++)
    {
        cin>>num_arr[i];
    }
    for(int i = 0;i<n;i++)
    {
        possibility=0;

        for(int t = i+1;t<n;t++)
        {
            if(num_arr[i]==num_arr[t])
            {
                possibility=1;
                break;
            }
        }
        if(num_arr[i] % 3 == 0 && possibility ==0)
        {
            arr0.push_back(num_arr[i]);
        }
        else if(num_arr[i] % 3 == 1 && possibility ==0)
        {
            arr1.push_back(num_arr[i]);
        }
        else if(num_arr[i] % 3 == 2 && possibility ==0)
        {
            arr2.push_back(num_arr[i]);
        }
    }
    int sorted0[arr0.size()],sorted1[arr1.size()],sorted2[arr2.size()];
    for(int i = 0;i<arr0.size();i++)
    {
        sorted0[i]=arr0[i];
    }
    for(int i = 0;i<arr1.size();i++)
    {
        sorted1[i]=arr1[i];
    }
    for(int i = 0;i<arr2.size();i++)
    {
        sorted2[i]=arr2[i];
    }
    sort2(sorted0,arr0.size());
    sort1(sorted1,arr1.size());
    sort2(sorted2,arr2.size());

    cout<<arr0.size()+arr1.size()+arr2.size()<<"\n";
    for(int i = 0;i<arr0.size();i++)
    {
        cout<<sorted0[i]<<" ";
    }
    for(int i = 0;i<arr1.size();i++)
    {
        cout<<sorted1[i]<<" ";
    }
    for(int i = 0;i<arr2.size();i++)
    {
        cout<<sorted2[i]<<" ";
    }
}
