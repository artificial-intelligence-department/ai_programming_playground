#include <iostream>
#include <vector>


using namespace std;


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
void reverse(vector<int>& num_arr)
{
    for(int i = 0;i < num_arr.size() / 2;i++)
    {
        int buff = num_arr[i];
        num_arr[i] = num_arr[num_arr.size() - 1 - i];
        num_arr[num_arr.size() - 1 - i] = buff;
    }

}



int main(){
    int size;
    cin >> size;
    vector<int> numbers;
    for (int i = 0; i < size; i++){
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    vector <int> buff0, buff1, buff2;
    for (int i = 0; i < size; i++){
        if (numbers[i] % 3 == 0){
            buff0.push_back(numbers[i]);
        }
        else if (numbers[i] % 3 == 1){
            buff1.push_back(numbers[i]);
        }
        else if (numbers[i] % 3 == 2){
            buff2.push_back(numbers[i]);
        }
    }

    merge_sort(buff0, 0, buff0.size() - 1);
    merge_sort(buff1, 0, buff1.size() - 1);

    reverse(buff1);
    merge_sort(buff2, 0, buff2.size() - 1);
    buff0.insert(buff0.end(), buff1.begin(), buff1.end());
    buff0.insert(buff0.end(), buff2.begin(), buff2.end());

    vector<int> buff;
    for(int i = 0;i < buff0.size() ;i++)
    {

        if (i == 0 || buff0[i] != buff0[i - 1])
        {
           buff.push_back(buff0[i]);
        }

    }
    cout<<buff.size()<<endl;
    for(int i : buff)
    {
        cout<<i<<' ';
    }

    return 0;
}