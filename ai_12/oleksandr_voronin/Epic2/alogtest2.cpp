#include <iostream>
using namespace std;

void BubleSort(int road[], int elements)
{
    for (int i = 0; i < elements-1; i++)
    {
    for (int j = i + 1; j < elements; j++)
        {
        if(road[j]<road[i])
            {
            swap (road[j],road[i]);
            }
        } 
    }
}
int main()
{

int elements;
cout <<"enter size of array \n";
cin >> elements;
int road[elements];
cout << "Enter elements of array \n";
for (int i = 0; i < elements; i++)
{
    cin >> road[i];
}
BubleSort(road,elements);

int NewElements=elements-1;
int NewRoad[NewElements];
for(int i=0;i<elements; i++) 
    {
        NewRoad[i - 1] = road[i];
    }
int min=NewRoad[0];
int max=NewRoad[NewElements-1];
int m = max - min;
cout <<"m "<< m << endl;
return 0;

}