#include <iostream>
#include <cmath>

using namespace std;

const int MaxSizeN = 9;
void GetDigit(int &n,int board[][MaxSizeN],int &given_number,int &row)
{
    for(int digit_counter=10,i=0; given_number!=0 || i<n ;i++)
    {
        board[n-i-1][row] =(given_number % digit_counter);
        given_number -=(given_number % digit_counter);
        given_number /= 10;
    }
}
void Deletionx(int board[][MaxSizeN],int x,int q,int n,int array[][9],int a)
{
    for(int t = 0; t<n;t++)
    {
        for(int iter = 0; iter<n;iter++)
        {
            if(board[x][t]==iter+1)
            {
                array[a][iter]=0;
            }
        }
    }
}
void Deletiony(int board[][MaxSizeN],int y,int q,int n,int array[][9],int a)
{
    for(int t = 0; t<n;t++)
    {
        for(int iter = 0; iter<n;iter++)
        {
            if(board[t][y]==iter+1)
            {
                array[a][iter]=0;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int board[n][MaxSizeN];
    for(int i=0,number_to_give;i<n;i++)
    {
        cin>>number_to_give;
        GetDigit(n,board,number_to_give,i);
    }
    int q;
    cin>>q;
    int x[q],y[q];
    int array[q][9];
    for(int t = 0;t<q;t++)
    {
        for(int i = 0;i<9;i++)
        {
            array[t][i]=i+1;
        }
    }
    for(int i = 0;i<q;i++)
    {
        cin>>y[i]>>x[i];
        x[i]-=1;
        y[i]-=1;
    }
    for(int t = 0;t<q;t++)
    {
        int count=0;
        if(board[x[t]][y[t]]==0)
        {
            Deletionx(board,x[t],q,n,array,t);
            Deletiony(board,y[t],q,n,array,t);
        
            for(int i = 0;i<n;i++)
            {
                if(array[t][i]!=0)
                {
                    count++;
                }
            }
            cout<<count;
            cout<<"\n";
            for(int i = 0;i<n;i++)
            {
                if(array[t][i]!=0)
                {
                    cout<<array[t][i]<<" ";
                }
            }
            cout<<"\n";
        }
        else
        {
            cout<<"1\n"<<board[x[t]][y[t]];
        }
        cout<<"\n";
    }
}
