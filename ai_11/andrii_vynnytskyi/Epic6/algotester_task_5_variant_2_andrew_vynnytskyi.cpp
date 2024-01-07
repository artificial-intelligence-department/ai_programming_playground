#include <iostream>
#include <vector>
using namespace  std;

void check(vector<string>& arr)
{

    for(int j = 0; j < arr[0].size(); j++)

    {
        for(int i = arr.size() - 1; i > 0; i--)
        {
            while(i  < arr.size() && arr[i - 1][j] == 'S' && arr[i][j] == 'O'  )
            {
                char buff = arr[i][j];
                arr[i][j] = arr[i - 1][j];
                arr[i - 1][j] = buff;
                i++;
            }


            }

        }
    }



void print_array(vector<string> str)
{
    for(int i = 0; i < str.size(); i++)
    {
        cout << str[i]<<endl;
    }
}

int main()
{
int count, count1;
    cin>>count>> count1;
    vector<string> arr;
    for(int i = 0; i < count; i++)
    {
        string value;
        cin>> value;
        arr.push_back(value);
    }
    check(arr);
    print_array(arr);
    return 0;
}
