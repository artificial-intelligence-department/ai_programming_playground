#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void print_array(vector<int> num)
{
    for(int i = 0; i < num.size(); i++)
    {
        cout << num[i]<<" ";
    }
}
int max(vector<int> nums)
{
    int max_n = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(max_n < nums[i])
        {
            max_n = nums[i];
        }

    }
    return max_n;

}


vector<int> counting_sort(vector<int> nums)
{
    vector<int> count(max(nums) + 1, 0);
    for(int i :nums)
    {
        count[i]++;
    }
    for (int j = 1; j < count.size(); j++)
    {
        count[j] += count[j - 1];
    }
    vector<int> result(nums.size(), 0);
    for(int k :nums)
    {
        result[count[k] - 1] = k;
        count[k]--;
    }

    return result;
}

int main()
{
    srand(time(0));
    vector<int> nums;
    for(int i = 0; i < 10;i++)
    {
        nums.push_back(rand() % 10);
    }
    cout<<"Generated array: ";
    print_array(nums);
    nums = counting_sort(nums);
    cout<<"\nSorted array: ";
    print_array(nums);
    return 0;
}