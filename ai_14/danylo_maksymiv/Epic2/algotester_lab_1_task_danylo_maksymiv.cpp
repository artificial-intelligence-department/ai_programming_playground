#include <iostream>

using namespace std;

int main() {
    int i=0,j=0;
    long long sticks[4] = {};
    long long slices[4] = {};
    bool isTableGood1 = true, isTableGood2 = false, isError = false;

    for (int i = 0; i < 4; i++) {
        cin >> sticks[i];
    }

    long long sticks_new[4] = {sticks[0], sticks[1], sticks[2], sticks[3]};
    long long max = -3,min = sticks_new[0];

    for (int i = 0; i < 4; i++) {
        cin >> slices[i];
        
        if (slices[i] > sticks[i]) 
        {
            isError = true;
            break;
        }
        
        sticks_new[i] = sticks[i] - slices[i];
        
        for(j=1;j<4;j++)
        {
            if (sticks_new[j] > max) 
            {
                max = sticks_new[j];
            }
        }
        for(j=1;j<4;j++)
        {
            if (sticks_new[j] < min) 
            {
                min = sticks_new[j];
            }
        }
        
        if(max >= 2 * min || min == 0)
        {
            isTableGood1 = false;
        }
    }

    if(sticks_new[0] == sticks_new[1] && sticks_new[1] == sticks_new[2] && sticks_new[2] == sticks_new[3])
    {
        isTableGood2 = true;
    }

    if (isError) 
    {
        cout << "ERROR";
    } 
    else if(isTableGood2 == true &&  isTableGood1 == true) 
    {
        cout << "YES";
    }
    else 
    {
        cout << "NO";
    } 

    return 0;
}
