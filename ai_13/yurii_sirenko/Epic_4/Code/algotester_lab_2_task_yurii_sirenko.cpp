#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int stepright = 0;
    int stepleft = 0;
    int initial = 0;
    int n;
    cin >> n;


    int final = n-1;
    int road[n];
            
    for(int q = 0; q<n; q++)
    {  
        cin >> road[q];
    }
    while(initial+stepright<=final-stepleft)
    {
        if(initial+stepright==final-stepleft)
        {
            cout << initial+stepright+1<<" "<<final-stepleft+1<<"\n";
            cout << "Collision";
            return 0;
        }
        else if(initial+stepright+1==final-stepleft)
        {
            cout << initial+stepright+1<<" "<<final-stepleft+1<<"\n";
            cout << "Stopped";
            return 0;
        }    
        initial = initial+stepright;
        stepright = road[initial];

        final = final-stepleft;
        stepleft = road[final];
    }
    cout << initial+stepright+1<<" "<<final-stepleft+1<<"\n";
    cout << "Miss";
    return 0;
}