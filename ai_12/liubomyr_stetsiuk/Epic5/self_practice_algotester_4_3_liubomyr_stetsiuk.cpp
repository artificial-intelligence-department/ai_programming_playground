#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> inputVector;
    int size;
    cin >> size;

    vector<int> moduloZero, moduloOne, moduloTwo;

    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        inputVector.push_back(num);

        if (num % 3 == 0)
        {
            moduloZero.push_back(num);
        }
        else if (num % 3 == 1)
        {
            moduloOne.push_back(num);
        }
        else if (num % 3 == 2)
        {
            moduloTwo.push_back(num);
        }
    }

    sort(moduloZero.begin(), moduloZero.end());
    sort(moduloOne.begin(), moduloOne.end(), greater<int>());
    sort(moduloTwo.begin(), moduloTwo.end());

    inputVector.clear();

    for (int i = 0; i < moduloZero.size(); i++)
    {
        inputVector.push_back(moduloZero[i]);
    }
    for (int i = 0; i < moduloOne.size(); i++)
    {
        inputVector.push_back(moduloOne[i]);
    }
    for (int i = 0; i < moduloTwo.size(); i++)
    {
        inputVector.push_back(moduloTwo[i]);
    }

    auto last = unique(inputVector.begin(), inputVector.end());
    inputVector.erase(last, inputVector.end());

    cout << inputVector.size() << endl;
    for (int i = 0; i < inputVector.size(); i++)
    {
        cout << inputVector[i] << " ";
    }

    return 0;
}