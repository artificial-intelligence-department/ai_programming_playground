#include<iostream>
#include<string>

using namespace std;

int main()
{   
    int N;
    cin>>N;
    
    cin.ignore();
    string str;
    getline(cin, str);

    int arr[N][N];

    int k=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            arr[i][j]=str[k]-'0';
            k=k+2;
        }
    }

    cout<<endl;
    
    for (int i=0; i<N; i++) 
    {
        for (int j=0; j<N; j++) 
        {
            for (int k=0; k<N-i-1; k++) 
            {
                if (arr[k][0]>arr[k + 1][0]) 
                {
                    for (int l=0; l<N; l++) 
                    {
                        int t=arr[k][l];
                        arr[k][l]=arr[k+1][l];
                        arr[k+1][l]=t;
                    }
                }
            }
        }
    }
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Можна";

    return 0;
}
