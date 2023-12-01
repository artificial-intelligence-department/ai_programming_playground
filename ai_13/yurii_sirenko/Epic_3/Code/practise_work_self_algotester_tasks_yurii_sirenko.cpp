#include <iostream>

using namespace std;

void sortArray(int array[][2] ,int start,int mid, int end)
{
    int left_array_size=mid-start+1;
    int right_array_size=end-mid;
    int left_array[left_array_size][2];
    int right_array[right_array_size][2];

    for(int i = 0;i<left_array_size;i++)
    {
        left_array[i][0]=array[i+start][0];
        left_array[i][1]=array[i+start][1];
    }
    for(int i = 0;i<right_array_size;i++)
    {
        right_array[i][0]=array[i+mid+1][0];
        right_array[i][1]=array[i+mid+1][1];
    }
    int left_itter=0;
    int right_itter=0;
    int main_itter=start;
    while(left_itter < left_array_size && right_itter < right_array_size)
    {
        if(left_array[left_itter][0]<=right_array[right_itter][0])
        {
            array[main_itter][0]=left_array[left_itter][0];
            array[main_itter][1]=left_array[left_itter][1];
            left_itter++;
        }
        else
        {
            array[main_itter][0]=right_array[right_itter][0];
            array[main_itter][1]=right_array[right_itter][1];
            right_itter++;
        }
        main_itter++;
    }
    while(left_itter < left_array_size)
    {
        array[main_itter][0]=left_array[left_itter][0];
        array[main_itter][1]=left_array[left_itter][1];
        left_itter++;
        main_itter++;
    }
    while(right_itter < right_array_size)
    {
        array[main_itter][0]=right_array[right_itter][0];
        array[main_itter][1]=right_array[right_itter][1];
        right_itter++;
        main_itter++;
    }
}
void sort(int array[][2],int start, int end)
{
    if(start<end)
    {
        int mid = start +(end-start)/2;

        sort(array,start,mid);
        sort(array,mid+1,end);

        sortArray(array,start,mid,end);
    }
}

int main()
{
    int n;

    cin >> n;

    int street[n][2];

    for (int i = 0; i < n; i++)
    {
        cin >> street[i][0];
    }
    for (int i = 0; i < n; i++)
    {
        street[i][1] = i;
    }
    sort(street, 0, n-1 );
    for (int i = 0; i < n; ++i)
    {
        cout << street[i][1]+1 << " ";
    }

    return 0;
}