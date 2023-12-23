#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void print_array(vector<int> num, int start , int end)
{
    for(int i = start; i < end; i++)
    {
        cout << num[i]<<" ";
    }
}

void merging(vector<int>& num_arr, int start ,int midle, int end)
{
    vector<int> buff_right(num_arr.begin() + midle + 1, num_arr.begin() + end + 1);
    vector<int> buff_left(num_arr.begin() + start, num_arr.begin() + midle + 1);
    int ind = 0;
    while (!buff_left.empty() && !buff_right.empty())
    {
        if (buff_left[ind] > buff_right[ind])
        {
            num_arr[start] = buff_right[ind];
            buff_right.erase(buff_right.begin() + ind);
            start++;
        }
        else
        {
            num_arr[start] = buff_left[ind];
            buff_left.erase(buff_left.begin() + ind);
            start++;
        }

    }
    if(buff_left.empty())
    {
        for(int i : buff_right)
        {
            num_arr[start] = i;
            start++;
        }

    }
    else if(buff_right.empty())
    {
        for(int i : buff_left)
        {
            num_arr[start] = i;
            start++;
        }

    }
    }

void merge_sort(vector<int>& num_arr, int start , int end)
{
    if (end != start)
    {
        int mid = (end + start)/2;

        merge_sort(num_arr, start , mid);
        merge_sort(num_arr, mid + 1 ,end);

        merging(num_arr, start, mid, end);
    }

}

int main()
{
    srand(time(0));
    vector<int> nums;
    for(int i = 0; i < 100;i++)
    {
            nums.push_back(rand() % 100);
    }

    merge_sort(nums, 0 , nums.size() - 1);
    cout<<"Sorted array: ";
    print_array(nums, 0, nums.size());
    return 0;
}




