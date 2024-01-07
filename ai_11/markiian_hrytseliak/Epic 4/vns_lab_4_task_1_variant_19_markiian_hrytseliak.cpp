#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Функція для виведення кільця, починаючи від К-го елементу і до К+1

void output_circle(const vector<int>& circle, int stidx)
{
    int size=circle.size();
    for(int i=0; i<size; i++)
        {
            cout<<circle[(stidx+i)%size]<<" ";
        }
        cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter n: "<<endl;

    cin>>n;

    vector<int>circle(n);
    cout<<"Enter numbers of the circle: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>circle[i];
    }
    int K;
    cout<<"Enter K: "<<endl;

    cin>>K;

    output_circle(circle,K);

    int fr, ls;
    cout<<"Enter first and last element: "<<endl;

    cin>>fr>>ls;

    circle.insert(circle.begin (), fr);
    circle.insert(circle.end (), ls);

    for(auto it=circle.begin(); it != circle.end();)
    {
        if(*it % 2 != 0)
        {
            circle.erase(it);
        }
        else
            it++;
    }

    int Knew;

    cout<<"Enter K: "<<endl;

    cin>>Knew;

    output_circle(circle ,Knew);

    return 0;
   
}
