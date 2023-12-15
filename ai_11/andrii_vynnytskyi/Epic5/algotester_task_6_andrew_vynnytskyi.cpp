#include <iostream>
#include <vector>
using namespace std;

void check(vector<string> arr , int value1 , int value2 )
{

    if (arr[value1][value2] != '0')
    {
        cout<<1<<endl<<arr[value1][value2]<<endl<<endl;
        return;
    }
    vector<char> right;
    for(int f = 1;f <arr[value1].size() + 1; f++)
    {
        right.push_back(f + 48);
    }
    vector<char> buff;
    for(char i : arr[value1])
    {
        if(i!='0')
        {
            buff.push_back(i);
        }
    }
    for(int l = 0;l <arr[value1].size(); l++)
    {
        if(arr[l][value2]!='0')
        {
            buff.push_back(arr[l][value2]);
        }
    }
    for(char k : buff)
    {
        for(int h = 0;h <right.size(); h++)
        {
            if(k == right[h])
            {
                right.erase(right.begin() + h);
            }
        }
    }
    cout << right.size() << endl;
    for(char a : right)
    {
        cout<<a<<" ";
    }
    cout<<endl<<endl;
}



int main(){
    int count;
    cin>>count;
    vector<string> arr;
    for(int i = 0; i < count; i++)
    {
        string value;
        cin>> value;
        arr.push_back(value);
    }
    int count_a;
    cin>>count_a;
    for(int j = 0; j < count_a; j++)
    {
        int value1 , value2;
        cin>> value1>>value2;
        check(arr, value1 - 1, value2 - 1);

    }
    return 0;
}