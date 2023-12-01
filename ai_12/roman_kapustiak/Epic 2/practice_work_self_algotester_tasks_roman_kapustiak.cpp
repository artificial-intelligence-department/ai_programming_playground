// Наноробот
#include <iostream>

using namespace std;

int main()
{
    int width, height, steps;
    int maxSteps, currentStep = 1, x = 0, y = 1, top = 0, right = 0, bottom = 0, left = 0;

    if (!(cin >> width && width > 1))
    {
        cout << "Wrong input!\n";
        return 1;
    }

    if (!(cin >> height && height > 1))
    {
        cout << "Wrong input!\n";
        return 1;
    }

    if (!(cin >> steps && steps > 0))
    {
        cout << "Wrong input!\n";
        return 1;
    }
    
    maxSteps = width * height;

    if(steps > maxSteps)
    {
        cout << "-1 -1\n";
        return 0;
    }

    while(true)
    {
        while(x < width - right) // Move right
        {   
            x++;
            if(currentStep == steps)
            {
                cout << x << " " << y << endl;
                return 0;
            }
            currentStep++;
        }
        top++;

        while(y < height - bottom) // Move down
        {
            y++;
            if(currentStep == steps)
            {
                cout << x << " " << y << endl;
                return 0;
            }
            currentStep++;
        }
        right++;

        while(x > left + 1) // Move left
        {
            x--;
            if(currentStep == steps)
            {
                cout << x << " " << y << endl;
                return 0;
            }
            currentStep++;
        }
        bottom++;

        while(y > top + 1) // Move upward
        {
            y--;
            if(currentStep == steps)
            {
                cout << x << " " << y << endl;
                return 0;
            }
            currentStep++;
        }
        left++;
    }
    
    return 1;
}
