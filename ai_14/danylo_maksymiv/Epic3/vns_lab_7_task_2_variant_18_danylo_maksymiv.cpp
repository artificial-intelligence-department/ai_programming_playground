#include <iostream>
#include <string>
using namespace std;

string max(const string& strr) {
    string longestword;
    string currentword;

    for (char letter : strr) 
    {
        if (isalpha(letter)) 
        {
            currentword += letter;
        } 
        else 
        {
            if (currentword.length() > longestword.length()) {
                longestword = currentword;
            }
            currentword.clear();
        }
    }
    if (currentword.length() > longestword.length()) 
    {
        longestword = currentword;
    }

    return longestword;
}

int i;
int max ( int n, int arr[ ])
{
    int maximum=arr[0];
    for ( i=1; i<n; i++)
    {
        if (arr[i]>maximum) 
        {
            maximum=arr[i];
        }
    }
    return maximum;
}

// long max ( int n, long arr[ ])
// {
//     long maximum=arr[0];
//     for ( i=1; i<n; i++)
//     {
//         if (arr[i]>maximum) 
//         {
//             maximum=arr[i];
//         }
//     }
//     return maximum;
// }

// short max ( int n, short arr[ ])
// {
//     short maximum=arr[0];
//     for ( i=1; i<n; i++)
//     {
//         if (arr[i]>maximum) 
//         {
//             maximum=arr[i];
//         }
//     }
//     return maximum;
// }

// long long max ( int n, long long arr[ ])
// {
//     long long maximum=arr[0];
//     for ( i=1; i<n; i++)
//     {
//         if (arr[i]>maximum) 
//         {
//             maximum=arr[i];
//         }
//     }
//     return maximum;
// }

int main ( )
{
    string str="I hate LNuuuuuU",maxstr;
    int a;
    // int b,c,d;

    cout<<"Enter size of array"<<endl;
    cin>>a;
    // cin>>b>>c>>d;

    int arra[a];
    // long arrb[b];
    // short arrc[c];
    // long long  arrd[d];

    cout<<"Enter elements of array(int)"<<endl;    
    for(i=0;i<a;i++)
    {
        cin>>arra[i];
    }
    // cout<<"Enter elements of array(long)"<<endl;  
    // for(i=0;i<b;i++)
    // {
    //     cin>>arrb[i];
    // }
    // cout<<"Enter elements of array(short)"<<endl;  
    // for(i=0;i<c;i++)
    // {
    //     cin>>arrc[i];
    // }
    // cout<<"Enter elements of array(long long)"<<endl;  
    // for(i=0;i<d;i++)
    // {
    //     cin>>arrd[i];
    // }

    int m=max(a, arra );
    // long m2=max(b, arrb);
    // short m3=max(c, arrc);
    // long long m4=max(d, arrd);
    maxstr=max(str);

    cout<<"Max(int):"<<m<<endl/*<<"Max(long):"<<m2<<endl<<"Max(short):"<<m3<<endl<<"Max(long long):"<<m4<<endl*/<<"The longest word is :"<<maxstr;

}