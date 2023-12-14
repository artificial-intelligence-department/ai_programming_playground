#include <iostream>

using namespace std;

int main()
{
    float average = 0;
    float arr[5];
    float sum =0;
    float arithm=0;
    int i=0;
    while(i<5)                                                            // Вимога 9. в коді використаний while цикл 

    {
        cin>>arr[i];
        sum+=arr[i];                                                      // Вимога 6. в коді використаний одновимірний масив 
        arithm=sum/(i+1);
        if(i==0)
        cout<<"arithmetic mean of " <<i+1<<" element is: "<<arithm<<endl;
        else
        cout<<"arithmetic mean of " <<i+1<<" elements is: "<<arithm<<endl;
        i++;
    }
    return 0;
}