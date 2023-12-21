#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool CheckIfNumberOccurs(vector<int> arr, int num)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == num)
            return true;
    }
    return false;
}

vector<int> sortedNumbers(vector<int> numbers) 
{
    vector<int> noRemainder, rem1, rem2;

    for (int num : numbers) 
    {
        if (num % 3 == 0)
            noRemainder.push_back(num);
        else if (num % 3 == 1)
            rem1.push_back(num);
        else
            rem2.push_back(num);
    }

    sort(noRemainder.begin(), noRemainder.end());
    sort(rem2.begin(), rem2.end());
    sort(rem1.begin(), rem1.end(), greater<int>());


    vector<int> temp, result;
    temp.insert(temp.end(), noRemainder.begin(), noRemainder.end());
    temp.insert(temp.end(), rem1.begin(), rem1.end());
    temp.insert(temp.end(), rem2.begin(), rem2.end());
    
    for(int i = 0; i < temp.size(); i++)
    {
        if(!CheckIfNumberOccurs(result, temp[i]))
                result.push_back(temp[i]);
        else continue;
    }

    return result;
}

int main() 
{
        //input
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i=0; i<n; ++i)
        cin >> numbers[i];

    vector<int> result = sortedNumbers(numbers);
    cout << result.size() << endl;

    for (int i=0; i < result.size(); ++i)
        cout << result[i] << " ";

    return 0;
}