#include <iostream>
#include <cmath>

using namespace std;
const int Nrow=sqrt(9);
const int Ncol=sqrt(9);

void create_matrix(int arr[])
{
    int matrix[Nrow][Ncol];

    for(int i=0,k=0; i<Nrow; i++)
    {
        for(int j=0; j<Ncol; j++)
        {
            
            matrix[i][j]=arr[k];
            cout<<matrix[i][j]<<"\t";
            if(matrix[i][j] == matrix[1][2])
            {
                cout<<" - Array, converted into matrix ";
            }
            k++;
        }
        cout<<endl;
    }

    for (int i = 0; i <  Nrow - 1; i++) 
    {
        for (int j = 0; j < Ncol - i - 1; j++) 
        {
            if (matrix[j][0] > matrix[j + 1][0])
            {
                for (int i = 0; i < Ncol; i++) 
                {
                    swap(matrix[j][i], matrix[j+1][i]);
                }
            }
        }
    }

    cout<<endl;

    for(int i=0; i<Nrow; i++)
    {
        for(int j=0; j<Ncol; j++)
        {
            cout<<matrix[i][j]<<"\t";
        
            if(matrix[i][j] == matrix[1][2])
            {
                cout<<" - Matrix, sorted by first column in growing order";
            }
        }
        cout<<endl;
    }

    cout<<endl;
}

int main()
{
    int Nsqr =9;
    int arr1[]={95,8,23,41,15,62,79,28,9};
    cout<<"First array is:"<<endl;
    for(int i=0;i<Nsqr; i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl<<endl;
    create_matrix(arr1);
    int arr2[]={36,0,3,29,75,27,4,16,89};
    cout<<"Second array is:"<<endl;
    for(int i=0;i<Nsqr; i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl<<endl;
    create_matrix(arr2);

    return 0;

}
