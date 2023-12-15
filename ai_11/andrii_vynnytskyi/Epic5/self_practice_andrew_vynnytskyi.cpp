#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;
void print_array(vector<int> num, int start , int end)
{
    for(int i = start; i < end; i++)
    {
        cout << num[i]<<" ";
    }
}

void Shell_sort_sedgvik(vector<int> numbers, vector<int>key)
{
    int counter = 0;
    for(int k = key.size() - 1; k >= 0; k--) {
        int buff;

        for (int i = key[k]; i < numbers.size(); i ++) {
            buff = numbers[i];
            counter++;
            int ind = i - key[k];
            for (; ind >= 0 && numbers[ind] > buff; ind-=key[k]) {
                counter++;
                numbers[ind + key[k]] = numbers[ind];
            }
            numbers[ind + key[k]] = buff;

        }
    }

    cout<<"\nSorted array: ";
    print_array(numbers, 0, numbers.size());

    cout<<"\nNumber of iterations: "<<counter;
}
void insertion_sort(vector<int> numbers)
{   long long int counter = 0;
    int buff;
    for(int i = 0; i < numbers.size(); i++)
    {
        counter++;
        buff = numbers[i];
        int ind = i - 1;
        for(;ind >= 0 && numbers[ind] > buff;ind--)
        {
            counter++;
            numbers[ind + 1] = numbers[ind];
        }
        numbers[ind + 1] = buff;

    }

    cout<<"\nSorted array: ";
    print_array(numbers, 0, numbers.size());

    cout<<"\nNumber of iterations: "<<counter;
}
void Shell_sort(vector<int> numbers)
{   int counter = 0;
    for(int k = numbers.size(); k > 0; k/=2) {
        int buff;

        for (int i = k; i < numbers.size(); i ++) {
            counter++;
            buff = numbers[i];
            int ind = i - k;
            for (; ind >= 0 && numbers[ind] > buff; ind-=k) {
                counter++;
                numbers[ind + k] = numbers[ind];
            }
            numbers[ind + k] = buff;

        }
    }

    cout<<"\nSorted array: ";
    print_array(numbers, 0, numbers.size());

    cout<<"\nNumber of iterations: "<<counter;
}


vector<int> Sedgvik(int size)
{
    vector<int>steps;
    int count = 0;
    do{
        if (count % 2 != 0) {
            int buff = 8 * pow(2,count) - 6* pow(2, (count + 1)/2) + 1;
            steps.push_back(buff);
            count++;
        }
        else {
            int buff1 = 9 * pow(2,count) - 9 * pow(2,count/2) + 1;
            steps.push_back(buff1);
            count++;
        }
    }while(3*steps[count - 1] < size);
    steps.erase(steps.end() - 1);
    return steps;
}

int main()
{
    srand(time(0));
    vector<int> nums;
    for(int i = 0; i < 100;i++)
    {
            nums.push_back(rand() % 100 );
    }
    cout<<"\nUnSorted array: ";
    print_array(nums, 0, nums.size());
    vector<int> buff = Sedgvik(nums.size());

    Shell_sort_sedgvik(nums, buff);

    Shell_sort(nums);

    insertion_sort(nums);

    return 0;
}