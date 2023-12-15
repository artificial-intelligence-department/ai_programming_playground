#include <iostream>
using namespace std;

int main()
{
int N;
cin>>N;//Введіть розмір масиву
int cell[N];
int drone_1=1, drone_2=N; 

    for(int i=0; i<N; i++)
    {
        cin>>cell[i];//Введіть елементи масиву
    }

    if(drone_1 == drone_2)
    {
        cout<<drone_1<<" "<<drone_2<<"\n"<<"Collision";
        return 0;
    }
    else if (drone_1==drone_2-1 || drone_2==drone_1+1)
        {
            cout<<drone_1<<" "<<drone_2<<"\n"<<"Stopped";
            return 0;
        }
    else if (drone_1>drone_2)
        {
            cout<<drone_1<<" "<<drone_2<<"\n"<<"Miss";
            return 0;
        }
    else
    {
        while (drone_1<=N && drone_2>=1)
        {
            drone_1+=cell[drone_1-1]; 
            drone_2-=cell[drone_2-1]; 

            if(drone_1 == drone_2)
            {
                cout<<drone_1<<" "<<drone_2<<"\n"<<"Collision";
                break;
            }
            else if (drone_1==drone_2-1 || drone_2==drone_1+1)
            {
                cout<<drone_1<<" "<<drone_2<<"\n"<<"Stopped";
                break;
            }
            else if (drone_1>drone_2)
            {
                cout<<drone_1<<" "<<drone_2<<"\n"<<"Miss";
                break;
            }
        }
    }
return 0;
}
