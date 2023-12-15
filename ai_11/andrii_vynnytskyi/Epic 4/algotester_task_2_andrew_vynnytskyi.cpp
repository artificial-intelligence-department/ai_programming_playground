#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr;
    long int count;
    cin>> count;
    for(int i = 0; i < count; i++)
    {
        int value;
        cin>> value;
        arr.push_back(value);
    }
    int first = 0;
    int last = count - 1 ;
    while (true)
    {
        if(first == last)
        {
            cout<< first + 1<<" "<< last + 1<<endl<<"Collision";
            break;
        }
        else if(first > last)
        {
            cout<< first + 1<<" "<< last + 1<<endl<<"Miss";
            break;
        }
        else if(first == last - 1)
        {
            cout<< first + 1<<" "<< last + 1<<endl<<"Stopped";
            break;
        }
        else
        {
            first += arr[first];
            last -= arr[last];
        }

    }
    return 0;
}