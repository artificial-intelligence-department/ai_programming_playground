#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

int min_vec_idx(vector<int> nums)
{
    int min = nums[0];
    int min_idx = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(min > nums[i])
        {
            min = nums[i];
            min_idx = i;
        }
    }
    return min_idx;
}


vector<int> selection_sort(vector<int> nums)
{
    vector<int> buff_num;
    for(int i = nums.size();i >= 0 && nums.size() != 0; i--)
    {
        int min = min_vec_idx(nums);
      buff_num.push_back(nums[min]);
      nums.erase(nums.begin() + min );
    }
    return buff_num;
}



vector<int> bucket_sort(vector<int> numbers)
{
    int max = *max_element(numbers.begin(),numbers.end());
    vector<vector<int>> buff(max/10 + 1);
    vector<int> buff_sort;
    for (int i = 0;i < numbers.size(); i++)
    {
        buff[numbers[i]/10].push_back(numbers[i]);
    }
    for (int j = 0;j < buff.size();j++)
    {
        buff[j]= selection_sort(buff[j]);
    }
    for(int i = 0; i < buff.size(); i++)
    {
        for(int j = 0; j < buff[i].size(); j++)
        {
           buff_sort.push_back(buff[i][j]) ;
        }
    }
    return buff_sort;



}
void print_array(vector<int> numbers)
{
    for(int i = 0; i < numbers.size();i++)
    {
        cout<< numbers[i]<<" ";
    }
}

int main()
{
    srand(time(0));
    vector<int> numbers = {};
    for(int i = 0; i < 10;i++)
    {
        numbers.push_back(rand() % 100);
    }
    cout<<"Array: ";
    print_array(numbers);
    numbers = bucket_sort(numbers);
    cout<<"\nSorted array: ";
    print_array(numbers);
    return 0;

}