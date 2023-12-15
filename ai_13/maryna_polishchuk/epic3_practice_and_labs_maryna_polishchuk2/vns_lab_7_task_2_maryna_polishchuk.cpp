#include <iostream>
#include <string>
using namespace std;
int Count(int nums[], int length)
{
    int output = 0;
    for(int i = 0; i < length; i++)
    {
        if(nums[i] < 0)
            output++;
    }
    return output;
}
void Count(string str)
{
    str += ' ';
    int result = 0;
    bool isWordStarted = false;
    for(int i = 0; i < str.size(); i++)
    {
        int temp; //індекс початку слова
        // char currentChar = str[i];
        if(str[i] != ' ' && !isWordStarted)
        {
            temp = i; 
            isWordStarted = true;
        }
        if(str[i] == ' ' && isWordStarted)
        {
            if(str[temp] == str[i-1])
                result++;
            isWordStarted = false;        }
    }
    cout << "last and first letter are equel: " << result << endl;
}
int main()
{
    int arr[] = {1, 5, -4, 6, -9, -5, -2},
        length = sizeof(arr) / sizeof(arr[0]);
    int result = Count(arr, length);
    cout << "amount of negative numbers: " << result << endl;
    string str = "   sdsds fkwe f q  sddfsm";
    Count(str);
    return 0;
}

