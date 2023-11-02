#include<iostream>
using namespace std;
int main()
{
    string result;
    int ni=0;
    int N=0;
    cout<<"Enter the size of the path: ";
    cin>>N;
    if(N<1||N>1000)
        N=rand()%1000+1;
    int path[N];
    for(int i=0;i<N;i++)
    {
        cout<<"Enter the speed in the cell: ";
        cin>>ni;
        if(ni<1||ni>5)
            ni=rand()%5+1;
        path[i]=ni;
    }
    int dron1=1;
    int dron2=N;
    do
    {
        if(dron1+path[dron1-1]<=N && dron2-path[dron2-1]>=1 )
        {
            dron1+=path[dron1-1];
            dron2-=path[dron2-1];
        }
        else
        {
            result="Miss";
        }
        if (dron2==dron1)
            result="Collision";
        else if(dron1>dron2)
            result="Miss";
        else if(dron2-dron1==1)
            result="Stopped";
    }while(dron1<dron2 && dron2-dron1!=1 && dron1+path[dron1-1]<=N && dron2-path[dron2-1]>=1);
    cout<<dron1<<" "<<dron2<<endl;
    cout<<result;
    return 0;
}
